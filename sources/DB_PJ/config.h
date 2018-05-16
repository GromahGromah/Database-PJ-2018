#ifndef CONFIG_H
#define CONFIG_H

#include "session.h"

namespace Config
{
    Ui::MainWindow *ui;

    void SetGroupBoxFlat()
    {
        ui -> LoginGroupBox -> setStyleSheet("QGroupBox{border:none}");
        ui -> ProfileGroupBox -> setStyleSheet("QGroupBox{border:none}");
    }

    void SetTabWidgetText()
    {
        ui -> MainTabWidget -> setTabText(0, "Homepage");
        ui -> MainTabWidget -> setTabText(1, "Problems");
        ui -> MainTabWidget -> setTabText(2, "Status");
        ui -> MainTabWidget -> setTabText(3, "Ranklist");
        ui -> MainTabWidget -> setTabText(4, "Profile");
        ui -> MainTabWidget -> setTabText(5, "Administration");
    }

    void SetLabels()
    {
        ui -> WelcomeUserLabel -> setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui -> EditProfileLabel -> setAlignment(Qt::AlignCenter);
        ui -> EditProfileLabel -> setFont(QFont("Timers", 16, QFont::Bold));
    }

    void SetReadModules()
    {
        ui -> TopRankedTableView -> setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui -> RankListTableView -> setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui -> ProblemsTableView -> setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui -> StatusTableView -> setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui -> EditProblemTableView -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

    void SetUserProfileGroupBox()
    {
        ui -> UserProfileNickLineEdit -> setFocusPolicy(Qt::NoFocus);
        ui -> UserProfileMottoTextEdit -> setReadOnly(true);
    }

    void SetLineEdits()
    {
        ui -> PasswordLineEdit -> setEchoMode(QLineEdit::Password);
        ui -> EditProfileOldPWDLineEdit -> setEchoMode(QLineEdit::Password);
        ui -> EditProfileNewPWDLineEdit -> setEchoMode(QLineEdit::Password);
        ui -> EditProfileConfirmLineEdit -> setEchoMode(QLineEdit::Password);
        ui -> EditUserNewPWDLineEdit -> setEchoMode(QLineEdit::Password);
        ui -> EditUserConfirmLineEdit -> setEchoMode(QLineEdit::Password);
    }

    void Init(Ui::MainWindow *_ui)
    {
        ui = _ui;
        SetGroupBoxFlat();
        SetTabWidgetText();
        SetLabels();
        SetReadModules();
        SetUserProfileGroupBox();
        SetLineEdits();
    }
}

#endif // CONFIG_H
