#include "logitemform.h"

#include <QDate>
#include <QTime>
#include <QDebug>

#include "ui_logitemform.h"

LogItemForm::LogItemForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogItemForm)
{
    ui->setupUi(this);
    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{border-with:0;border-style:outset}");
}


LogItemForm::~LogItemForm()
{
    delete ui;
}

int LogItemForm::getPlainTextWidth() {
    int w = ui->plainTextEdit->width();
    return w;
}

void LogItemForm::testHeight()
{
    qDebug() << "test:" << ui->plainTextEdit->width();
}

void LogItemForm::setTag(QString &s)
{
    ui->label_tag->setText(s);
}

int LogItemForm::getPlainTextHeight()
{

    int sumWidth = ui->plainTextEdit->document()->size().width();
    int h = ui->plainTextEdit->fontMetrics().lineSpacing();//
    int rowCount = ui->plainTextEdit->document()->size().height();
    this->resize(this->width(),rowCount * h + ui->plainTextEdit->fontMetrics().height() + 10 );
    return  this->height();
}

void LogItemForm::setLog(QString &log)
{
    ui->plainTextEdit->setPlainText(log);
    QDate d;
    QTime t;
    QString currentTime = d.currentDate().toString("yyyy/M/d").append(" ").append(t.currentTime().toString("h:m:s"));
    ui->label_time->setText(currentTime);
    qDebug() << ui->plainTextEdit->size();
}


int LogItemForm::getDivisionValue(int x, int y)
{
    return ceil((float)x / y);
}
