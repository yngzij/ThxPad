#include "logitemform.h"
#include "ui_logitemform.h"

LogItemForm::LogItemForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogItemForm)
{
    ui->setupUi(this);
}

LogItemForm::~LogItemForm()
{
    delete ui;
}
