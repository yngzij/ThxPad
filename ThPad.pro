QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = $$PWD/bin


include($$PWD/SideForm/SideForm.pri)
include($$PWD/ListItem/ListItem.pri)
include($$PWD/LogItem/LogItem.pri)
include($$PWD/AddForm/Addform.pri)
include($$PWD/sql)


SOURCES += \
    main.cpp \
    proxy/shadowproxy.cpp \
    proxywidget.cpp \
    sql/sql.cpp \
    widget.cpp

HEADERS += \
    proxy/shadowproxy.h \
    proxywidget.h \
    sql/sql.h \
    widget.h \
    $$PWD/sql/sqlite3.h

LIBS +=  \
    -L$$PWD/sql -lsqlite3

FORMS += \
    widget.ui

TRANSLATIONS += \
    ThPad_yue_CN.ts


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
