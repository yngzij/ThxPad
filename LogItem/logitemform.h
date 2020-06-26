#ifndef LOGITEMFORM_H
#define LOGITEMFORM_H

#include <QWidget>

namespace Ui
{
    class LogItemForm;
}

class LogItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit LogItemForm(QWidget *parent = nullptr);
    ~LogItemForm();

    int getPlainTextHeight();
    void setLog(QString &);
    int getPlainTextWidth();
    void testHeight();
    void setTag(QString &);
private slots:
private:
    int getDivisionValue(int, int);

private:
    Ui::LogItemForm *ui;
};

#endif // LOGITEMFORM_H
