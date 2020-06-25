#include "shadowproxy.h"

#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

ShadowProxy::ShadowProxy(QWidget *parent) :
    QObject(parent),
    m_proxyWidget(parent)
{
    SHADOW_WIDTH = 5;
    m_proxyWidget->installEventFilter(this);
    m_proxyWidget->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);
    m_pixmaps.append(QPixmap(":/shadow/skin/shadow_left"));
    m_pixmaps.append(QPixmap(":/shadow/skin/shadow_right"));
    m_pixmaps.append(QPixmap(":/shadow/skin/shadow_top"));
    m_pixmaps.append(QPixmap(":/shadow/skin/shadow_bottom"));
    m_pixmaps.append(QPixmap(":/shadow/skin/shadow_left_top"));
    m_pixmaps.append(QPixmap(":/shadow/skin/shadow_right_top"));
    m_pixmaps.append(QPixmap(":/shadow/skin/shadow_left_bottom"));
    m_pixmaps.append(QPixmap(":/shadow/skin/shadow_right_bottom"));

    m_proxyWidget->setAttribute(Qt::WA_TranslucentBackground);
}

void ShadowProxy::setEnable(bool enable)
{
    if(enable)
        SHADOW_WIDTH = 5;
    else
        SHADOW_WIDTH = 0;
    m_proxyWidget->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH );
}

void ShadowProxy::drawShadow()
{

    if(!m_proxyWidget) return;
    qDebug() << "111" << '\n';
    QPainter painter(m_proxyWidget);
    int width = m_proxyWidget->width();
    int height = m_proxyWidget->height();

    painter.drawPixmap(0, 0, SHADOW_WIDTH, SHADOW_WIDTH, m_pixmaps[4]);

    // -- 右上角 --
    painter.drawPixmap(width - SHADOW_WIDTH, 0, SHADOW_WIDTH, SHADOW_WIDTH, m_pixmaps[5]);

    // -- 左下角 --
    painter.drawPixmap(0, height - SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, m_pixmaps[6]);

    // -- 右下角 --
    painter.drawPixmap(width - SHADOW_WIDTH, height - SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, m_pixmaps[7]);

    // -- 左边 --
    painter.drawPixmap(0, SHADOW_WIDTH, SHADOW_WIDTH, height - 2 * SHADOW_WIDTH, m_pixmaps[0].scaled(SHADOW_WIDTH, height - 2 * SHADOW_WIDTH ));

    // -- 右边 --
    painter.drawPixmap(width - SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, height - 2 * SHADOW_WIDTH - 2, m_pixmaps[1].scaled(SHADOW_WIDTH, height - 2 * SHADOW_WIDTH ));

    // -- 上边 --
    painter.drawPixmap(SHADOW_WIDTH, 0, width - 2 * SHADOW_WIDTH - 2, SHADOW_WIDTH, m_pixmaps[2].scaled(width - 2 * SHADOW_WIDTH, SHADOW_WIDTH));

    // -- 下边 --
    painter.drawPixmap(SHADOW_WIDTH, height - SHADOW_WIDTH, width - 2 * SHADOW_WIDTH, SHADOW_WIDTH, m_pixmaps[3].scaled(width - 2 * SHADOW_WIDTH, SHADOW_WIDTH));

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QColor(0, 0, 0, 30));
    painter.setBrush(QColor(255, 255, 255, 255));
    painter.drawRoundRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH, width - 2 * SHADOW_WIDTH, height - 2 * SHADOW_WIDTH ), 0, 0);
}

bool ShadowProxy::eventFilter(QObject *watched, QEvent *event)
{
    QEvent::Type et = event->type();
    if(et == QEvent::Paint)
    {
        if(m_proxyWidget)
        {
            this->drawShadow();
        }
    }
    else if(et  == QEvent::Show)
        m_proxyWidget->repaint();

    return m_proxyWidget->eventFilter(watched, event);
}
