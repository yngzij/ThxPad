#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::addTagListItem(QString s)
{
    ui->comboBox_tag->addItem(s);
}

QString AddDialog::getContent()
{
    QString content = this->ui->plainTextEdit->toPlainText();
    return content;
}



QString AddDialog::getTag()
{
    QString tag = this->ui->comboBox_tag->currentText();
    return tag;
}
