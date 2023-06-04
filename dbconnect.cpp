#include "dbconnect.h"

DBConnect::DBConnect()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={SQL Server};Server=LAPTOP-4DHEHD7N;Database=VeronaKLD;Uid=sa;Pwd=12312003");

    if (!db.open()) {
    qDebug() << "Failed to connect to database.";
    }
    else{
        qDebug()<<"Success";
    }

}

