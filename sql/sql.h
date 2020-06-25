#ifndef SQL_H
#define SQL_H

#include <QObject>


class sqlite3;
class Sql : public QObject
{
    Q_OBJECT
public:
    explicit Sql(QObject *parent = nullptr);
    ~Sql();

    sqlite3 *getCur();

private:
    void initialize();
    void sqlExec(const char *sql);

    sqlite3 *m_sql;
};

#endif // SQL_H
