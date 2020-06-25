#include "proxywidget.h"

#include <QDesktopWidget>
#include <QApplication>

#include "shadowproxy.h"

ProxyWidget::ProxyWidget(QWidget *child) :
    QObject((QObject *)child),
    m_ProxyWidget(child)
{
    m_shadowProxy = new ShadowProxy(child);
    //child->setWindowFlags(Qt::FramelessWindowHint);
    QRect screenRect = QApplication::desktop()->availableGeometry();

    int width, height;
    if(screenRect.width() > 2048)
    {
        width = 1600;
        height = 870;
    }
    else if(screenRect.width() >= 1920)
    {
        width = 600;
        height = 600;
    }
    else if(screenRect.width() >= 1366)
    {
        width = 700;
        height = 700;
    }

    int x = (screenRect.width() - width) / 2;
    int y = (screenRect.height() - height) / 2;

    child ->setGeometry(x, y, width, height);
}
