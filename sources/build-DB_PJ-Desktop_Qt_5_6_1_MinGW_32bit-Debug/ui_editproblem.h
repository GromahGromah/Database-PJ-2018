/********************************************************************************
** Form generated from reading UI file 'editproblem.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROBLEM_H
#define UI_EDITPROBLEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_EditProblem
{
public:
    QWidget *centralwidget;
    QLabel *EditOrAddProblemLabel;
    QLabel *NameLabel;
    QLineEdit *NameLineEdit;
    QLabel *SourceLabel;
    QLineEdit *SourceLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *DescriptionLabel;
    QTextEdit *DescriptionTextEdit;
    QLabel *label_3;
    QLabel *AnswerLabel;
    QLineEdit *AnswerLineEdit;
    QLabel *label_4;
    QPushButton *SubmitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditProblem)
    {
        if (EditProblem->objectName().isEmpty())
            EditProblem->setObjectName(QStringLiteral("EditProblem"));
        EditProblem->resize(800, 600);
        centralwidget = new QWidget(EditProblem);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        EditOrAddProblemLabel = new QLabel(centralwidget);
        EditOrAddProblemLabel->setObjectName(QStringLiteral("EditOrAddProblemLabel"));
        EditOrAddProblemLabel->setGeometry(QRect(10, 20, 781, 71));
        NameLabel = new QLabel(centralwidget);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));
        NameLabel->setGeometry(QRect(192, 117, 61, 31));
        NameLineEdit = new QLineEdit(centralwidget);
        NameLineEdit->setObjectName(QStringLiteral("NameLineEdit"));
        NameLineEdit->setGeometry(QRect(254, 107, 291, 50));
        SourceLabel = new QLabel(centralwidget);
        SourceLabel->setObjectName(QStringLiteral("SourceLabel"));
        SourceLabel->setGeometry(QRect(170, 185, 81, 31));
        SourceLineEdit = new QLineEdit(centralwidget);
        SourceLineEdit->setObjectName(QStringLiteral("SourceLineEdit"));
        SourceLineEdit->setGeometry(QRect(254, 170, 291, 61));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(554, 124, 91, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(554, 192, 91, 16));
        DescriptionLabel = new QLabel(centralwidget);
        DescriptionLabel->setObjectName(QStringLiteral("DescriptionLabel"));
        DescriptionLabel->setGeometry(QRect(115, 240, 131, 31));
        DescriptionTextEdit = new QTextEdit(centralwidget);
        DescriptionTextEdit->setObjectName(QStringLiteral("DescriptionTextEdit"));
        DescriptionTextEdit->setGeometry(QRect(254, 240, 291, 181));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(554, 248, 101, 16));
        AnswerLabel = new QLabel(centralwidget);
        AnswerLabel->setObjectName(QStringLiteral("AnswerLabel"));
        AnswerLabel->setGeometry(QRect(168, 445, 81, 31));
        AnswerLineEdit = new QLineEdit(centralwidget);
        AnswerLineEdit->setObjectName(QStringLiteral("AnswerLineEdit"));
        AnswerLineEdit->setGeometry(QRect(254, 430, 291, 61));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(554, 452, 101, 16));
        SubmitButton = new QPushButton(centralwidget);
        SubmitButton->setObjectName(QStringLiteral("SubmitButton"));
        SubmitButton->setGeometry(QRect(309, 502, 181, 51));
        EditProblem->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditProblem);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        EditProblem->setMenuBar(menubar);
        statusbar = new QStatusBar(EditProblem);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        EditProblem->setStatusBar(statusbar);

        retranslateUi(EditProblem);

        QMetaObject::connectSlotsByName(EditProblem);
    } // setupUi

    void retranslateUi(QMainWindow *EditProblem)
    {
        EditProblem->setWindowTitle(QApplication::translate("EditProblem", "MainWindow", 0));
        EditOrAddProblemLabel->setText(QApplication::translate("EditProblem", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">TextLabel</span></p></body></html>", 0));
        NameLabel->setText(QApplication::translate("EditProblem", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Name</span></p></body></html>", 0));
        SourceLabel->setText(QApplication::translate("EditProblem", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Source</span></p></body></html>", 0));
        label->setText(QApplication::translate("EditProblem", "(Max Length 40)", 0));
        label_2->setText(QApplication::translate("EditProblem", "(Max Length 50)", 0));
        DescriptionLabel->setText(QApplication::translate("EditProblem", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Description</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("EditProblem", "(Max Length 200)", 0));
        AnswerLabel->setText(QApplication::translate("EditProblem", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Answer</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("EditProblem", "(Max Length 50)", 0));
        SubmitButton->setText(QApplication::translate("EditProblem", "Submit", 0));
    } // retranslateUi

};

namespace Ui {
    class EditProblem: public Ui_EditProblem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROBLEM_H
