#include "sql.h"

#include "sqlite3.h"


Sql::Sql(QObject *parent) : QObject(parent)
{
    sqlite3_open("./test.db", &m_sql);
    initialize();
}

Sql::~Sql()
{
    sqlite3_close(m_sql);
}

sqlite3 *Sql::getCur()
{
    return m_sql;
}

void Sql::initialize()
{
    if(!m_sql) return;
    const char *command = "CREATE TABLE IF NOT EXISTS t_article (id integer PRIMARY KEY AUTOINCREMENT, \
                                                                 tag text NOT NULL UNIQUE, \
                                                                 content text NOT NULL, \
                                                                 create_time varchar(50) NOT NULL)";
    sqlExec(command);
}

void Sql::sqlExec(const char *sql)
{
    if(!m_sql) return;
    sqlite3_stmt *stmt = NULL;
    int result = sqlite3_prepare_v2(m_sql, sql, -1, &stmt, NULL);
    if (result == SQLITE_OK)
    {
        sqlite3_step(stmt);
    }
    else
    {

    }
}



