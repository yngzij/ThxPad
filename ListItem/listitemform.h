#ifndef LISTITEMFORM_H
#define LISTITEMFORM_H

#include <QWidget>

namespace Ui {
class ListItemForm;
}

class ListItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit ListItemForm(QWidget *parent = nullptr);
    ~ListItemForm();

private:
    Ui::ListItemForm *ui;
};

#endif // LISTITEMFORM_H
