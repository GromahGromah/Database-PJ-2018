#include "session.h"
#include <QCryptographicHash>
#include <QMessageBox>

void Session::Init()
{
    currentUser.clear();
    searchUser.clear();
}

bool Session::IsLogin()
{
    return !currentUser.isEmpty();
}

bool Session::IsAdmin()
{
    return currentUser == admin;
}

bool Session::IsExistUser(QString user)
{
    QString instr = "SELECT * FROM Users WHERE Id = '" + user + "';";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    return !rec.empty();
}


bool Session::CheckLength(QString src, QString description, QString *logs, int MaxLength, QString MaxLengthStr)
{
    bool res = src.size() <= MaxLength;
    if (res == false && logs != NULL)
       *logs = description + " too Long (Exceeded " + MaxLengthStr + ").";
    return res;
}

QString Session::GetCurrentUser()
{
    return currentUser;
}

QString Session::GetSearchUser()
{
    return searchUser;
}

QTime Session::GetLastClickTime()
{
    return LastClickTime;
}

QString Session::Hash(QString src)
{
    QString res;
    QByteArray bb, tmp;
    tmp.append(src);
    bb = QCryptographicHash::hash(tmp, QCryptographicHash::Md5);
    res.append(bb.toHex());
    return res;
}

void Session::SetCurrentUser(QString user)
{
    currentUser = user;
}

void Session::SetSearchUser(QString user)
{
    searchUser = user;
}

void Session::SetLastClickTime(QTime ClickTime)
{
    LastClickTime = ClickTime;
}

bool Session::AvoidQuickClick(QMainWindow *CurWindow)
{
    QTime curTime = QTime::currentTime();
    if (LastClickTime.isValid() && curTime <= GetLastClickTime().addMSecs(400))
    {
        QMessageBox::warning(CurWindow, "Oops", "Please Be Patient and NOT so Quick.");
        return false;
    }
    SetLastClickTime(curTime);
    return true;
}

void Session::Logout()
{
    Init();
}

bool Session::Login(QString user, QString HashedPassword, QString *logs)
{
    if (user.isEmpty())
    {
        if (logs != NULL)
            *logs = "Please Input User.";
        return false;
    }
    if (IsLogin())
    {
        if (logs != NULL)
            *logs = "User " + GetCurrentUser() + " Already Loged In.";
        return false;
    }
    QString instr = "SELECT HashedPassword FROM Users WHERE Id = '" + user + "';";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    if (rec.empty())
    {
        if (logs != NULL)
            *logs = "No Such User.";
        return false;
    }
    if (HashedPassword.isEmpty())
    {
        if (logs != NULL)
            *logs = "Please Input Password.";
        return false;
    }
    else if (rec[0][0] != HashedPassword)
    {
        if (logs != NULL)
            *logs = "Wrong Password.";
        return false;
    }
    SetCurrentUser(user);
    if (logs != NULL)
        *logs = "User " + user + " Loged in Successfully.";
    return true;
}

bool Session::Update(QString user, QString srcField, int dest, bool SystemEvent, QString *logs)
{
    QString deststr;
    deststr.setNum(dest);
    return Update(user, srcField, deststr, SystemEvent, logs);
}

bool Session::Update(QString user, QString srcField, QString dest, bool SystemEvent, QString *logs)
{
    if (SystemEvent || user == currentUser || IsAdmin())
    {
        QString instr = "UPDATE Users SET " + srcField + " = " + dest + " WHERE Id = '" + user + "';";
        bool res = DataBase::UpdateInstr(instr);
        if (logs != NULL)
        {
            if (res == true)
                *logs = "Update Succeeded.";
            else *logs = "Update Failed.";
        }
        return res;
    }
    else
    {
        if (logs != NULL)
            *logs = "Not Current User or Admin, Permission Denied.";
        return false;
    }
}

bool Session::Register(QString user, QString Password, QString Confirm, QString Nick, QString Motto, QString Gender, QString *logs)
{
    if (IsExistUser(user))
    {
        if (logs != NULL)
            *logs = "User " + user + " Already Exists.";
        return false;
    }
    else if (user.isEmpty())
    {
        if (logs != NULL)
            *logs = "Please Input User.";
        return false;
    }
    if (!CheckLength(user, "User", logs)) return false;
    if (Password.isEmpty())
    {
        if (logs != NULL)
            *logs = "Please Input Password.";
        return false;
    }
    else if (Confirm.isEmpty())
    {
        if (logs != NULL)
            *logs = "Please Input Confirm.";
        return false;
    }
    else if (Password != Confirm)
    {
        if (logs != NULL)
            *logs = "Input Password and Confirm are not the same.";
        return false;
    }
    else if (Password.size() > MAX_LEN)
    {
        if (logs != NULL)
            *logs = "Input Password is too Long(Exceed" + MAX_LEN_STR + ").";
        return false;
    }
    if (!CheckLength(Password, "Password", logs)) return false;
    if (!CheckLength(Nick, "Nick", logs)) return false;
    if (!CheckLength(Motto, "Motto", logs, 50, "50")) return false;
    QString quote = "\'";
    QString instr;
    instr = "INSERT INTO Users (Id, HashedPassword, Nick, Motto, Gender, Solved, Attempted, OrzByOthers) values (" +
            quote + user + quote + "," +
            quote + Hash(Password) + quote + "," +
            quote + Nick + quote + "," +
            quote + Motto + quote + "," +
            quote + Gender + quote + "," +
            "0, 0, 0)" + ";";
    bool res = DataBase::InsertInstr(instr);
    if (logs != NULL)
    {
        if (res == true)
            *logs = "User " + user + " Registered";
        else *logs = "Register Failed";
    }
    return res;
}
