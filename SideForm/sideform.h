#ifndef SIDEFORM_H
#define SIDEFORM_H

#include <QWidget>

namespace Ui
{
    class SideForm;
}

class AddDialog;
class SideForm : public QWidget
{
    Q_OBJECT

public:
    explicit SideForm(QWidget *parent = nullptr);
    ~SideForm();

signals:
    void signal_addContent(QString);
private slots:
    void on_toolButton_add_clicked();
    void addTag(QString s);
private:
    void initiazile();

private:
    Ui::SideForm *ui;
    AddDialog  *m_addDialog;
};

#endif // SIDEFORM_H
