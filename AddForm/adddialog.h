#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui
{
    class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

public:
    void addTagListItem(QString s);
    QString getContent();
    QString getTag();
private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
