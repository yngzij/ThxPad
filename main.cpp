#include "widget.h"

#include <QApplication>
#include <QSplitter>

#include "proxywidget.h"
#include "SideForm/sideform.h"
#include "sql/sql.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplitter splitter;
    Widget w;
    SideForm sideForm;

    QObject::connect(&sideForm, SIGNAL(signal_addContent(QString, QString)), &w, SLOT(slot_addContentItem(QString, QString)));
    ProxyWidget pw(&splitter);
    Sql sql;
    splitter.setHandleWidth(1);
    splitter.addWidget(&sideForm);
    splitter.addWidget(&w);
    splitter.show();
    return a.exec();
}
