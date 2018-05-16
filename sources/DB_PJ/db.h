#ifndef DB_H
#define DB_H

#include <QtSql>
#include <QSqlQuery>

namespace DataBase
{
    static const QString DBName = "DB_PJ";
    static QString host = "localhost";
    static QString user = "root";
    static QString password = "";
    static QSqlDatabase db;
    static QSqlQuery query;
    using Record = std::vector <std::vector <QString>>;

    bool Init();
    QString GetHost();
    QString GetUser();
    QString GetPassword();
    void SetHost(QString host);
    void SetUser(QString user);
    void SetPassword(QString password);
    void InsertTables();
    void InsertInstr(QString instr, bool *ok);
    void DeleteInstr(QString instr, bool *ok);
    void UpdateInstr(QString instr, bool *ok);
    bool InsertInstr(QString instr);
    bool DeleteInstr(QString instr);
    bool UpdateInstr(QString instr);
    Record SelectInstr(QString instr, bool *ok = NULL);
}

#endif // DB_H
