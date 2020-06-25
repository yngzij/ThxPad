#include "sideform.h"
#include "ui_sideform.h"

SideForm::SideForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SideForm)
{
    ui->setupUi(this);
}

SideForm::~SideForm()
{
    delete ui;
}
