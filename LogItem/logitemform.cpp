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

int LogItemForm::getPlainTextHeight()
{
    int sumWidth = ui->plainTextEdit->fontMetrics().width(ui->plainTextEdit->toPlainText());
    int w = ui->plainTextEdit->width();
    int h = ui->plainTextEdit->fontMetrics().lineSpacing();// + ui->plainTextEdit->fontMetrics().height() ;
    int rowCount = getDivisionValue(sumWidth, w);
    if(!rowCount) rowCount = 1;
    qDebug() << sumWidth;
    qDebug() << w;
    qDebug() << h;
    qDebug() << rowCount;
    ui->plainTextEdit->setFixedHeight(rowCount * h);
    return rowCount * h;
}

void LogItemForm::setLog(QString &log)
{
    ui->plainTextEdit->setPlainText(log);
    QDate d;
    QTime t;
    QString currentTime = d.currentDate().toString("yyyy/M/d").append(" ").append(t.currentTime().toString("h:m:s"));
    ui->label_time->setText(currentTime);
}

int LogItemForm::getDivisionValue(int x, int y)
{
    return ceil((float)x / y);
}

