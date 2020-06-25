#include "listitemform.h"

#include <QColor>

#include "ui_listitemform.h"

ListItemForm::ListItemForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListItemForm)
{
    ui->setupUi(this);
    initialize();
}

ListItemForm::~ListItemForm()
{
    delete ui;
}

void ListItemForm::setTag(const QString &tag)
{
    this->ui->lineEdit_tag->setText(tag);
    this->ui->lineEdit_tag->setFont(QFont("Timers", 10, QFont::Normal));
}

void ListItemForm::initialize()
{
    this->ui->lineEdit_tag->setStyleSheet("QLineEdit{border-with:0;border-style:outset}");
    this->ui->lineEdit_tag->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    QPalette palette;
    palette.setColor(QPalette::Text, QColor(77, 123, 220));
    ui->lineEdit_tag->setPalette(palette);

}

void ListItemForm::on_lineEdit_tag_textEdited(const QString &arg1)
{

}
