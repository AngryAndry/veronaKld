#ifndef DBCONNECT_H
#define DBCONNECT_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

class DBConnect
{
public:

    static DBConnect& instance()
    {
    static DBConnect instance; // создаем единственный объект
    return instance; // возвращаем ссылку на объект
    }

    DBConnect(const DBConnect&) = delete;
    DBConnect& operator=(const DBConnect&) = delete;
     QSqlDatabase db;


private:
DBConnect();
  ~DBConnect() = default;
}
;

#endif // DBCONNECT_H
