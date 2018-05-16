#include "db.h"
#include "tables.h"
#include <QSqlRecord>

bool DataBase::Init()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(host);
    db.setUserName(user);
    db.setPassword(password);
    if(!db.open()){
#ifdef DEBUG
        qDebug() << "Failed To Connect mySQL." << endl;
#endif
        return false;
    }
    query = QSqlQuery(db);
    query.exec("CREATE DATABASE IF NOT EXISTS " + DBName + ";");
    query.exec("USE " + DBName + ";");
    InsertTables();
    return true;
}

QString DataBase::GetHost()
{
    return host;
}

QString DataBase::GetUser()
{
    return user;
}

QString DataBase::GetPassword()
{
    return password;
}

void DataBase::SetHost(QString NewHost)
{
    host = NewHost;
}

void DataBase::SetUser(QString NewUser)
{
    user = NewUser;
}

void DataBase::SetPassword(QString NewPassword)
{
    password = NewPassword;
}

void DataBase::InsertTables()
{
    QString CreateUser = CreateTable_Users();
    QString CreateProb = CreateTable_Problems();
    QString CreateStatus = CreateTable_Status();
#ifdef DEBUG
    qDebug() << endl << CreateUser << query.exec(CreateUser) << endl;
    qDebug() << endl << CreateProb << query.exec(CreateProb) << endl;
    qDebug() << endl << CreateStatus << query.exec(CreateStatus) << endl;
#endif
}

void DataBase::InsertInstr(QString instr, bool *ok)
{
    bool res = query.exec(instr);
#ifdef DEBUG
    qDebug() << instr << endl;
#endif
    if (ok != NULL) *ok = res;
#ifdef DEBUG
    else qDebug() << "Insert Return Bool Value : " << res << endl;
#endif
}

void DataBase::DeleteInstr(QString instr, bool *ok)
{
    bool res = query.exec(instr);
#ifdef DEBUG
    qDebug() << instr << endl;
#endif
    if (ok != NULL) *ok = res;
#ifdef DEBUG
    else qDebug() << "Delete Return Bool Value : " << res << endl;
#endif
}

void DataBase::UpdateInstr(QString instr, bool *ok)
{
    bool res = query.exec(instr);
#ifdef DEBUG
    qDebug() << instr << endl;
#endif
    if (ok != NULL) *ok = res;
#ifdef DEBUG
    else qDebug() << "Update Return Bool Value : " << res << endl;
#endif
}

bool DataBase::InsertInstr(QString instr)
{
    bool *res = new bool;
    InsertInstr(instr, res);
    return *res;
}

bool DataBase::DeleteInstr(QString instr)
{
    bool *res = new bool;
    DeleteInstr(instr, res);
    return *res;
}

bool DataBase::UpdateInstr(QString instr)
{
    bool *res = new bool;
    UpdateInstr(instr, res);
    return *res;
}

DataBase::Record DataBase::SelectInstr(QString instr, bool *ok)
{
    bool res = query.exec(instr);
#ifdef DEBUG
    qDebug() << instr << endl;
#endif
    if (ok != NULL) *ok = res;
#ifdef DEBUG
    else qDebug() << "Select Return Bool Value : " << res << endl;
#endif
    DataBase::Record record;
    int ItemCount = query.record().count();
    query.seek(-1);
    while(query.next())
    {
        std::vector <QString> items;
        for (int i = 0; i < ItemCount; i ++)
            items.push_back(query.value(i).toString());
        record.push_back(items);
    }
#ifdef DEBUG
    qDebug() << "Received " << record.size() << " Records." << endl;
#endif
    return record;
}
