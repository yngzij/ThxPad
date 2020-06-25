#ifndef SHADOWPROXY_H
#define SHADOWPROXY_H

#include <QObject>
#include <QWidget>

class ShadowProxy : public QObject
{
    Q_OBJECT
public:
    explicit ShadowProxy(QWidget *parent = nullptr);

    void  setEnable(bool enable = true);
    void drawShadow();

protected:
    virtual bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QWidget *m_proxyWidget;
    QList<QPixmap> m_pixmaps;

    int SHADOW_WIDTH;
};

#endif // SHADOWPROXY_H
