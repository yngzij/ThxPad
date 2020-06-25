#include "listitemform.h"
#include "ui_listitemform.h"

ListItemForm::ListItemForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListItemForm)
{
    ui->setupUi(this);
}

ListItemForm::~ListItemForm()
{
    delete ui;
}
