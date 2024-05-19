#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void resetFunc();
    void onPushBtnPlus();
    void onPushBtnMinus();
    void onRadioBtnAll();
    void onRadioBtnInit();
    void updateButtonLayout(int count);

private:
    Ui::MainWindow *ui;
    QString labelName;
    QLabel* createLabel;
    QLabel* labelToRemove;
    QString btnName;
    QPushButton* qLabelToBtn;
    QPushButton* createBtn;
    QPushButton* btnToRemove;
    int clickCount;
    int row;
    int col;
    int rowSpan;
    int colSpan;
    int index;
};
#endif // MAINWINDOW_H
