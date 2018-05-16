/********************************************************************************
** Form generated from reading UI file 'problems.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROBLEMS_H
#define UI_PROBLEMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Problems
{
public:
    QWidget *centralwidget;
    QLabel *ProblemNameLabel;
    QGroupBox *ProblemDescriptionGroupBox;
    QTextEdit *ProblemDescriptionTextEdit;
    QGroupBox *ProblemSolveGroupBox;
    QTextEdit *ProblemSolveTextEdit;
    QPushButton *ProblemSolveSubmitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Problems)
    {
        if (Problems->objectName().isEmpty())
            Problems->setObjectName(QStringLiteral("Problems"));
        Problems->resize(800, 647);
        centralwidget = new QWidget(Problems);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ProblemNameLabel = new QLabel(centralwidget);
        ProblemNameLabel->setObjectName(QStringLiteral("ProblemNameLabel"));
        ProblemNameLabel->setGeometry(QRect(10, 10, 801, 61));
        ProblemDescriptionGroupBox = new QGroupBox(centralwidget);
        ProblemDescriptionGroupBox->setObjectName(QStringLiteral("ProblemDescriptionGroupBox"));
        ProblemDescriptionGroupBox->setGeometry(QRect(50, 80, 721, 361));
        ProblemDescriptionTextEdit = new QTextEdit(ProblemDescriptionGroupBox);
        ProblemDescriptionTextEdit->setObjectName(QStringLiteral("ProblemDescriptionTextEdit"));
        ProblemDescriptionTextEdit->setGeometry(QRect(10, 20, 701, 331));
        ProblemSolveGroupBox = new QGroupBox(centralwidget);
        ProblemSolveGroupBox->setObjectName(QStringLiteral("ProblemSolveGroupBox"));
        ProblemSolveGroupBox->setGeometry(QRect(50, 460, 721, 111));
        ProblemSolveTextEdit = new QTextEdit(ProblemSolveGroupBox);
        ProblemSolveTextEdit->setObjectName(QStringLiteral("ProblemSolveTextEdit"));
        ProblemSolveTextEdit->setGeometry(QRect(10, 20, 581, 81));
        ProblemSolveSubmitButton = new QPushButton(ProblemSolveGroupBox);
        ProblemSolveSubmitButton->setObjectName(QStringLiteral("ProblemSolveSubmitButton"));
        ProblemSolveSubmitButton->setGeometry(QRect(600, 20, 111, 81));
        Problems->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Problems);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        Problems->setMenuBar(menubar);
        statusbar = new QStatusBar(Problems);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Problems->setStatusBar(statusbar);

        retranslateUi(Problems);

        QMetaObject::connectSlotsByName(Problems);
    } // setupUi

    void retranslateUi(QMainWindow *Problems)
    {
        Problems->setWindowTitle(QApplication::translate("Problems", "MainWindow", 0));
        ProblemNameLabel->setText(QApplication::translate("Problems", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Problem Name</span></p></body></html>", 0));
        ProblemDescriptionGroupBox->setTitle(QApplication::translate("Problems", "Description", 0));
        ProblemDescriptionTextEdit->setHtml(QApplication::translate("Problems", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p></body></html>", 0));
        ProblemSolveGroupBox->setTitle(QApplication::translate("Problems", "Solve it", 0));
        ProblemSolveSubmitButton->setText(QApplication::translate("Problems", "Submit", 0));
    } // retranslateUi

};

namespace Ui {
    class Problems: public Ui_Problems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROBLEMS_H
