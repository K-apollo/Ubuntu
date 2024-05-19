#include "dialogbtnplus.h"
#include "ui_dialogbtnplus.h"

DialogBtnPlus::DialogBtnPlus(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogBtnPlus)
{
    ui->setupUi(this);
}

DialogBtnPlus::~DialogBtnPlus()
{
    delete ui;
}
