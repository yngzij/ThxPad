#include "sideform.h"

#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>

#include "ui_sideform.h"
#include "ListItem/listitemform.h"
#include "AddForm/adddialog.h"


SideForm::SideForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SideForm),
    m_addDialog(new AddDialog)
{

    ui->setupUi(this);
    initiazile();
}

SideForm::~SideForm()
{
    delete ui;
}

void SideForm::initiazile()
{
    this->ui->widget->setStyleSheet("background-color:rgba(245, 246, 245,0.7)");

    this->ui->widget_tag->setStyleSheet("background-color:rgba(245, 246, 245,0.7)");
    this->ui->listWidget_tag->setFrameShape(QListWidget::NoFrame);

    this->ui->toolButton_search->setIcon(QIcon(":/icon/icon/icon_search"));
    this->ui->toolButton_add->setIcon(QIcon(":/icon/icon/icon_add"));

    this->ui->toolButton_add->setIconSize(QSize(16, 16));
    this->ui->toolButton_search->setIconSize(QSize(16, 16));
}

void SideForm::on_toolButton_add_clicked()
{
    if(m_addDialog->exec() == QDialog::Accepted)
    {
        QString content = m_addDialog->getContent();
        QString tag = m_addDialog->getTag();
        addTag(tag);
        m_addDialog->addTagListItem(tag);
        emit signal_addContent(content);
    }
    else
    {

    }
}

void SideForm::addTag(QString s)
{
    QListWidgetItem *listItem = new QListWidgetItem;
    listItem->setSizeHint(QSize(30, 30));

    ListItemForm *item = new ListItemForm;
    item->setTag(s);
    ui->listWidget_tag->insertItem(ui->listWidget_tag->model()->rowCount(), listItem);
    ui->listWidget_tag->setItemWidget(listItem, item);
}

