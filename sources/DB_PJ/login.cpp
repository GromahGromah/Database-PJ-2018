#include "login.h"
#include "ui_login.h"
#include "session.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    // Set Size
    this -> setMinimumSize(800,600);
    this -> setMaximumSize(800,600);

    // Set Title
    this -> setWindowTitle("Login / Register");

    // Set PasswordInvisable
    ui -> LoginPasswordLineEdit -> setEchoMode(QLineEdit::Password);
    ui -> RegisterPasswordLineEdit -> setEchoMode(QLineEdit::Password);
    ui -> RegisterConfirmLineEdit -> setEchoMode(QLineEdit::Password);

    // SetSlots
    QObject::connect(ui -> LoginPasswordLineEdit, SIGNAL(returnPressed()), this, SLOT(TryLogin()));
    QObject::connect(ui -> LoginSubmitButton, SIGNAL(clicked(bool)), this, SLOT(TryLogin()));
    QObject::connect(ui -> RegisterSubmitButton, SIGNAL(clicked(bool)), this, SLOT(TryRegister()));
}

void Login::Clear()
{
    // Clear All LineEdits
    ui -> LoginUserLineEdit -> clear();
    ui -> LoginPasswordLineEdit -> clear();
    ui -> RegisterUserLineEdit -> clear();
    ui -> RegisterPasswordLineEdit -> clear();
    ui -> RegisterConfirmLineEdit -> clear();
    ui -> RegisterNickLineEdit -> clear();
    ui -> RegisterGenderComboBox -> setCurrentIndex(0);
    ui -> RegisterMottoTextEdit -> clear();
}

void Login::TryLogin()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString user = ui -> LoginUserLineEdit -> text();
    QString Password = ui -> LoginPasswordLineEdit -> text();
    QString *logs = new QString;
    bool res = Session::Login(user, Session::Hash(Password), logs);
#ifdef DEBUG
    qDebug() << *logs << endl;
#endif
    if (res == true)
    {
        Clear();
#ifdef DEBUG
        qDebug() << "LoginPage Closed." << endl;
#endif
        emit Refresh(true);
        this -> close();
    }
    else QMessageBox::warning(this, "Error", *logs);
}

void Login::TryRegister()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString User = ui -> RegisterUserLineEdit -> text();
    QString Password = ui -> RegisterPasswordLineEdit -> text();
    QString Confirm = ui -> RegisterConfirmLineEdit -> text();
    QString Nick = ui -> RegisterNickLineEdit -> text();
    QString Motto = ui -> RegisterMottoTextEdit -> toPlainText();
    QString Gender = ui -> RegisterGenderComboBox -> currentText();
    QString *logs = new QString;
    bool res = Session::Register(User, Password, Confirm, Nick, Motto, Gender, logs);
#ifdef DEBUG
    qDebug() << *logs << endl;
#endif
    if (res == true)
    {
        Clear();
#ifdef DEBUG
        qDebug() << "LoginPage Closed." << endl;
#endif
        emit Refresh(true);
        this -> close();
    }
    else QMessageBox::warning(this, "Error", *logs);
}

Login::~Login()
{
    delete ui;
}
