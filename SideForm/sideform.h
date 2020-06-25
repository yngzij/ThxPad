#ifndef SIDEFORM_H
#define SIDEFORM_H

#include <QWidget>

namespace Ui {
class SideForm;
}

class SideForm : public QWidget
{
    Q_OBJECT

public:
    explicit SideForm(QWidget *parent = nullptr);
    ~SideForm();

private:
    Ui::SideForm *ui;
};

#endif // SIDEFORM_H
