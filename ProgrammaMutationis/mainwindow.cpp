#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resetFunc();
    connect(ui->pBtn01Plus,  &QPushButton::clicked,  this, &MainWindow::onPushBtnPlus);
    connect(ui->pBtn02Minus, &QPushButton::clicked,  this, &MainWindow::onPushBtnMinus);
    connect(ui->rBtn01All,   &QRadioButton::clicked, this, &MainWindow::onRadioBtnAll);
    connect(ui->rBtn02Init,  &QRadioButton::clicked, this, &MainWindow::onRadioBtnInit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetFunc()
{
    clickCount = 0;
}

void MainWindow::onPushBtnPlus()
{
    clickCount++;
    if (clickCount <= 25) updateButtonLayout(clickCount);
    else ui->statusBarInfo->showMessage("더이상 진행이 불가능한 횟수입니다.");
}

void MainWindow::onPushBtnMinus()
{
    if (clickCount > 0)
    {
        btnName = QString("pBtn%1").arg(clickCount, 2, 10, QChar('0'));
        btnToRemove = findChild<QPushButton*>(btnName);

        if (btnToRemove)
        {
            index = ui->gL01->indexOf(btnToRemove);

            if (index != -1)
            {
                ui->gL01->getItemPosition(index, &row, &col, &rowSpan, &colSpan);
                ui->gL01->removeWidget(btnToRemove);
                delete btnToRemove;

                createLabel = new QLabel(this);
                createLabel->setObjectName(QString("label%1").arg(clickCount, 2, 10, QChar('0')));
                createLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
                createLabel->setMinimumSize(30, 30);
                ui->gL01->addWidget(createLabel, row, col, rowSpan, colSpan);
            }
        }
        clickCount--;
    }
    else
        ui->statusBarInfo->showMessage("더이상 제거할 버튼이 없습니다.");
}

void MainWindow::onRadioBtnAll()
{
    for (int i = 1; i <= 25; i++) updateButtonLayout(i);
    resetFunc();
}

void MainWindow::onRadioBtnInit()
{
    for (int i = 1; i <= 25; i++)
    {
        btnName = QString("pBtn%1").arg(i, 2, 10, QChar('0'));
        btnToRemove = findChild<QPushButton*>(btnName);

        if (btnToRemove)
        {
            index = ui->gL01->indexOf(btnToRemove);

            if (index != -1)
            {
                ui->gL01->getItemPosition(index, &row, &col, &rowSpan, &colSpan);
                ui->gL01->removeWidget(btnToRemove);
                delete btnToRemove;

                createLabel = new QLabel(this);
                createLabel->setObjectName(QString("label%1").arg(i, 2, 10, QChar('0')));
                createLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
                createLabel->setMinimumSize(30, 30);
                ui->gL01->addWidget(createLabel, row, col, rowSpan, colSpan);
            }
        }
    }
    resetFunc();
}

void MainWindow::updateButtonLayout(int count)
{
    labelName = QString("label%1").arg(count, 2, 10, QChar('0'));
    labelToRemove = findChild<QLabel*>(labelName);
    index = ui->gL01->indexOf(labelToRemove);

    if (index != -1)
    {
        ui->gL01->getItemPosition(index, &row, &col, &rowSpan, &colSpan);
        if (labelToRemove)
        {
            ui->gL01->removeWidget(labelToRemove);
            delete labelToRemove;

            createBtn = new QPushButton(this);
            createBtn->setObjectName(QString("pBtn%1").arg(count, 2, 10, QChar('0')));
            createBtn->setStyleSheet("QPushButton {"
                                     "border-image: url(/home/uk91/Qt/uK91/ProgrammaMutationis/icon/Plus.png) 0 0 0 0 stretch stretch;"
                                     "}");
            createBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
            createBtn->setMinimumSize(30, 30);
            ui->gL01->addWidget(createBtn, row, col, rowSpan, colSpan);
        }
    }
}
