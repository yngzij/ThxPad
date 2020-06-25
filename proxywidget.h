#ifndef PROXYWIDGET_H
#define PROXYWIDGET_H

#include <QObject>
#include <QWidget>

class ShadowProxy;
class ProxyWidget : public QObject
{
    Q_OBJECT
public:
    explicit ProxyWidget(QWidget *child = nullptr);

private:
    QWidget     *m_ProxyWidget;
    ShadowProxy *m_shadowProxy;

    int SHADOW_WIDTH;
};

#endif // PROXYWIDGET_H
