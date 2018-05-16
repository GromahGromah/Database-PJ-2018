#ifndef SESSION_H
#define SESSION_H

#include "db.h"
#include <QMainWindow>

namespace Session
{
    static const int MAX_LEN = 16;
    static const QString MAX_LEN_STR = "16";
    static const QString admin = "admin";
    static QString currentUser;
    static QString searchUser;
    static QTime LastClickTime;

    void Init();
    bool IsLogin();
    bool IsAdmin();
    bool IsExistUser(QString user);
    bool CheckLength(QString src, QString description, QString *logs = NULL, int MaxLength = MAX_LEN, QString MaxLengthStr = MAX_LEN_STR);
    QString GetCurrentUser();
    QString GetSearchUser();
    QTime GetLastClickTime();
    bool AvoidQuickClick(QMainWindow *CurWindow);
    QString Hash(QString src);
    void SetCurrentUser(QString user);
    void SetSearchUser(QString user);
    void SetLastClickTime(QTime ClickTime);
    void Logout();
    bool Login(QString user, QString HashedPassword, QString *logs = NULL);
    bool Update(QString user, QString srcField, int dest, bool SystemEvent, QString *logs = NULL);
    bool Update(QString user, QString srcField, QString dest, bool SystemEvent, QString *logs = NULL);
    bool Register(QString user, QString Password, QString Confirm, QString Nick, QString Motto, QString Gender, QString *logs = NULL);
}

#endif // SESSION_H
