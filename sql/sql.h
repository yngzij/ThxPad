#ifndef SQL_H
#define SQL_H

#include <QObject>

class Sql : public QObject
{
    Q_OBJECT
public:
    explicit Sql(QObject *parent = nullptr);

signals:

};

#endif // SQL_H
