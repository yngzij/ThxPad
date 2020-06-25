#ifndef LISTITEMFORM_H
#define LISTITEMFORM_H

#include <QWidget>

namespace Ui
{
    class ListItemForm;
}

class ListItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit ListItemForm(QWidget *parent = nullptr);
    ~ListItemForm();


    void setTag(const QString &tag);
private:
    void initialize();
private slots:
    void on_lineEdit_tag_textEdited(const QString &arg1);

private:
    Ui::ListItemForm *ui;
};

#endif // LISTITEMFORM_H
