/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QLabel *LoginLabel;
    QFrame *line;
    QLabel *LoginUserLabel;
    QLineEdit *LoginUserLineEdit;
    QLineEdit *LoginPasswordLineEdit;
    QLabel *LoginPasswordLabel;
    QPushButton *LoginSubmitButton;
    QLabel *RegisterLabel;
    QLabel *RegisterUserLabel;
    QLineEdit *RegisterUserLineEdit;
    QLineEdit *RegisterPasswordLineEdit;
    QLabel *RegisterPasswordLabel;
    QLabel *RegisterConfirmLabel;
    QLineEdit *RegisterConfirmLineEdit;
    QLineEdit *RegisterNickLineEdit;
    QLabel *RegisterNickLabel;
    QLabel *RegisterMottoLabel;
    QLabel *RegisterGenderLabel;
    QPushButton *RegisterSubmitButton;
    QComboBox *RegisterGenderComboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *RegisterMottoTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(800, 600);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        LoginLabel = new QLabel(centralwidget);
        LoginLabel->setObjectName(QStringLiteral("LoginLabel"));
        LoginLabel->setGeometry(QRect(70, 70, 211, 81));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(370, 40, 20, 501));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        LoginUserLabel = new QLabel(centralwidget);
        LoginUserLabel->setObjectName(QStringLiteral("LoginUserLabel"));
        LoginUserLabel->setGeometry(QRect(110, 230, 48, 27));
        LoginUserLineEdit = new QLineEdit(centralwidget);
        LoginUserLineEdit->setObjectName(QStringLiteral("LoginUserLineEdit"));
        LoginUserLineEdit->setGeometry(QRect(170, 232, 133, 20));
        LoginPasswordLineEdit = new QLineEdit(centralwidget);
        LoginPasswordLineEdit->setObjectName(QStringLiteral("LoginPasswordLineEdit"));
        LoginPasswordLineEdit->setGeometry(QRect(170, 283, 133, 20));
        LoginPasswordLabel = new QLabel(centralwidget);
        LoginPasswordLabel->setObjectName(QStringLiteral("LoginPasswordLabel"));
        LoginPasswordLabel->setGeometry(QRect(60, 280, 111, 27));
        LoginSubmitButton = new QPushButton(centralwidget);
        LoginSubmitButton->setObjectName(QStringLiteral("LoginSubmitButton"));
        LoginSubmitButton->setGeometry(QRect(130, 390, 111, 41));
        RegisterLabel = new QLabel(centralwidget);
        RegisterLabel->setObjectName(QStringLiteral("RegisterLabel"));
        RegisterLabel->setGeometry(QRect(530, 80, 161, 51));
        RegisterUserLabel = new QLabel(centralwidget);
        RegisterUserLabel->setObjectName(QStringLiteral("RegisterUserLabel"));
        RegisterUserLabel->setGeometry(QRect(490, 168, 48, 27));
        RegisterUserLineEdit = new QLineEdit(centralwidget);
        RegisterUserLineEdit->setObjectName(QStringLiteral("RegisterUserLineEdit"));
        RegisterUserLineEdit->setGeometry(QRect(550, 170, 133, 20));
        RegisterPasswordLineEdit = new QLineEdit(centralwidget);
        RegisterPasswordLineEdit->setObjectName(QStringLiteral("RegisterPasswordLineEdit"));
        RegisterPasswordLineEdit->setGeometry(QRect(550, 210, 133, 20));
        RegisterPasswordLabel = new QLabel(centralwidget);
        RegisterPasswordLabel->setObjectName(QStringLiteral("RegisterPasswordLabel"));
        RegisterPasswordLabel->setGeometry(QRect(440, 207, 111, 27));
        RegisterConfirmLabel = new QLabel(centralwidget);
        RegisterConfirmLabel->setObjectName(QStringLiteral("RegisterConfirmLabel"));
        RegisterConfirmLabel->setGeometry(QRect(452, 247, 91, 27));
        RegisterConfirmLineEdit = new QLineEdit(centralwidget);
        RegisterConfirmLineEdit->setObjectName(QStringLiteral("RegisterConfirmLineEdit"));
        RegisterConfirmLineEdit->setGeometry(QRect(550, 250, 133, 20));
        RegisterNickLineEdit = new QLineEdit(centralwidget);
        RegisterNickLineEdit->setObjectName(QStringLiteral("RegisterNickLineEdit"));
        RegisterNickLineEdit->setGeometry(QRect(550, 290, 133, 20));
        RegisterNickLabel = new QLabel(centralwidget);
        RegisterNickLabel->setObjectName(QStringLiteral("RegisterNickLabel"));
        RegisterNickLabel->setGeometry(QRect(490, 287, 51, 27));
        RegisterMottoLabel = new QLabel(centralwidget);
        RegisterMottoLabel->setObjectName(QStringLiteral("RegisterMottoLabel"));
        RegisterMottoLabel->setGeometry(QRect(479, 387, 61, 27));
        RegisterGenderLabel = new QLabel(centralwidget);
        RegisterGenderLabel->setObjectName(QStringLiteral("RegisterGenderLabel"));
        RegisterGenderLabel->setGeometry(QRect(469, 327, 71, 27));
        RegisterSubmitButton = new QPushButton(centralwidget);
        RegisterSubmitButton->setObjectName(QStringLiteral("RegisterSubmitButton"));
        RegisterSubmitButton->setGeometry(QRect(550, 450, 131, 41));
        RegisterGenderComboBox = new QComboBox(centralwidget);
        RegisterGenderComboBox->setObjectName(QStringLiteral("RegisterGenderComboBox"));
        RegisterGenderComboBox->setGeometry(QRect(551, 330, 131, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 170, 101, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(690, 210, 101, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(690, 290, 101, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(690, 390, 101, 20));
        RegisterMottoTextEdit = new QTextEdit(centralwidget);
        RegisterMottoTextEdit->setObjectName(QStringLiteral("RegisterMottoTextEdit"));
        RegisterMottoTextEdit->setGeometry(QRect(550, 372, 131, 61));
        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "MainWindow", 0));
        LoginLabel->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt;\">Login</span></p></body></html>", 0));
        LoginUserLabel->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:18pt;\">User</span></p></body></html>", 0));
        LoginPasswordLabel->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:18pt;\">Password</span></p></body></html>", 0));
        LoginSubmitButton->setText(QApplication::translate("Login", "Submit", 0));
        RegisterLabel->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt;\">Register</span></p></body></html>", 0));
        RegisterUserLabel->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:18pt;\">User</span></p></body></html>", 0));
        RegisterPasswordLabel->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:18pt;\">Password</span></p></body></html>", 0));
        RegisterConfirmLabel->setText(QApplication::translate("Login", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Confirm</span></p></body></html>", 0));
        RegisterNickLabel->setText(QApplication::translate("Login", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Nick</span></p></body></html>", 0));
        RegisterMottoLabel->setText(QApplication::translate("Login", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Motto</span></p></body></html>", 0));
        RegisterGenderLabel->setText(QApplication::translate("Login", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Gender</span></p></body></html>", 0));
        RegisterSubmitButton->setText(QApplication::translate("Login", "Submit", 0));
        RegisterGenderComboBox->clear();
        RegisterGenderComboBox->insertItems(0, QStringList()
         << QApplication::translate("Login", "Unknown", 0)
         << QApplication::translate("Login", "Male", 0)
         << QApplication::translate("Login", "Female", 0)
        );
        label->setText(QApplication::translate("Login", "(Max Length 16)", 0));
        label_2->setText(QApplication::translate("Login", "(Max Length 16)", 0));
        label_3->setText(QApplication::translate("Login", "(Max Length 16)", 0));
        label_4->setText(QApplication::translate("Login", "(Max Length 50)", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
