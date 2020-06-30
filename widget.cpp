#include "widget.h"

#include <QListWidgetItem>
#include <QDebug>

#include "ui_widget.h"
#include "LogItem/logitemform.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initialize();
    ui->listWidget_content->setFrameShape(QListWidget::NoFrame);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_addContentItem(QString i, QString tag)
{
    QListWidgetItem *listItem = new QListWidgetItem;
    LogItemForm *item = new LogItemForm;

    item->setLog(i);
    item->setTag(tag);
    ui->listWidget_content->insertItem(ui->listWidget_content->model()->rowCount(), listItem);
    ui->listWidget_content->setItemWidget(listItem, item);
    ui->listWidget_content->repaint();
    int h = item->getPlainTextHeight();
    int w = item->getPlainTextWidth();
    listItem->setSizeHint(QSize(w, h));
}

void Widget::initialize()
{
    this->ui->widget_head->setStyleSheet("background-color:rgb(243, 244, 244)");
    this->ui->widget_center->setStyleSheet("background-color:rgb(243, 244, 244)");

    this->ui->toolButton_max->setIcon(QIcon(":/icon/icon/icon_max"));

    this->ui->toolButton_min->setIcon(QIcon(":/icon/icon/icon_min"));
    this->ui->toolButton_close->setIcon(QIcon(":/icon/icon/icon_close"));

    this->ui->toolButton_max->setIconSize(QSize(12, 12));
    this->ui->toolButton_min->setIconSize(QSize(12, 12));
    this->ui->toolButton_close->setIconSize(QSize(12, 12));
}


void Widget::on_toolButton_close_clicked()
{
    QApplication::quit();
}
