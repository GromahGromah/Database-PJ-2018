/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *MainTabWidget;
    QWidget *HomepageTab;
    QFrame *graphicFrame;
    QLabel *WelcomeLabel;
    QLabel *TopRankedLabel;
    QTableView *TopRankedTableView;
    QGroupBox *LoginGroupBox;
    QPushButton *LoginPushButton;
    QGroupBox *ProfileGroupBox;
    QPushButton *LogoutPushButton;
    QLabel *WelcomeUserLabel;
    QGroupBox *ConfigHostGroupBox;
    QLabel *HostLabel;
    QLineEdit *HostLineEdit;
    QPushButton *HostSubmitButton;
    QWidget *ProblemsTab;
    QLabel *label;
    QTableView *ProblemsTableView;
    QLabel *ProblemsSearchLabel;
    QComboBox *ProblemsSearchComboBox;
    QLineEdit *ProblemsSearchLineEdit;
    QPushButton *ProblemsSearchSubmitButton;
    QWidget *StatusTab;
    QLabel *StatusLabel;
    QTableView *StatusTableView;
    QPushButton *StatusSearchSubmitButton;
    QLineEdit *StatusSearchLineEdit;
    QComboBox *StatusSearchComboBox;
    QLabel *StatusSearchLabel;
    QWidget *RanklistTab;
    QLabel *RankListLabel;
    QTableView *RankListTableView;
    QWidget *ProfileTab;
    QLabel *SearchUserLabel;
    QLineEdit *SearchUserLineEdit;
    QPushButton *SearchUserSubmitButton;
    QGroupBox *UserProfileGroupBox;
    QLabel *UserProfileNickLabel;
    QLabel *UserProfileMottoLabel;
    QLabel *UserProfileGenderLabel;
    QLabel *UserProfileSolvedLabel;
    QLabel *UserProfileAttemptedLabel;
    QLabel *UserProfileOrzByOthersLabel;
    QLCDNumber *UserProfileSolvedLcdNumber;
    QLCDNumber *UserProfileAttemptedLcdNumber;
    QLCDNumber *UserProfileOrzByOthersLcdNumber;
    QLineEdit *UserProfileNickLineEdit;
    QTextEdit *UserProfileMottoTextEdit;
    QPushButton *UserProfileOrzButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *UserProfileUnknownCheckBox;
    QCheckBox *UserProfileMaleCheckBox;
    QCheckBox *UserProfileFemaleCheckBox;
    QGroupBox *EditProfileGroupBox;
    QLabel *EditProfileMottoLabel;
    QLabel *label_3;
    QLabel *EditProfileGenderLabel;
    QLabel *EditProfileNickLabel;
    QTextEdit *EditProfileMottoTextEdit;
    QLineEdit *EditProfileNickLineEdit;
    QComboBox *EditProfileGenderComboBox;
    QPushButton *EditProfileSubmitButton;
    QLabel *label_4;
    QLabel *EditProfileLabel;
    QGroupBox *PasswordModifyGroupBox;
    QLabel *EditProfileOldPWDLabel;
    QLabel *EditProfileConfirmLabel;
    QLabel *label_2;
    QLineEdit *EditProfileOldPWDLineEdit;
    QLineEdit *EditProfileConfirmLineEdit;
    QLabel *EditProfileNewPWDLabel;
    QLineEdit *EditProfileNewPWDLineEdit;
    QWidget *tab;
    QGroupBox *AdminGroupBox;
    QGroupBox *EditUserGroupBox;
    QLabel *EditUserMottoLabel;
    QLabel *label_5;
    QLabel *EditUserGenderLabel;
    QLabel *EditUserNickLabel;
    QTextEdit *EditUserMottoTextEdit;
    QLineEdit *EditUserNickLineEdit;
    QComboBox *EditUserGenderComboBox;
    QPushButton *EditUserSubmitButton;
    QLabel *label_6;
    QGroupBox *AdminPasswordModifyGroupBox;
    QLabel *EditUserConfirmLabel;
    QLabel *label_7;
    QLineEdit *EditUserConfirmLineEdit;
    QLabel *EditUserNewPWDLabel;
    QLineEdit *EditUserNewPWDLineEdit;
    QLabel *AdminSearchUserLabel;
    QPushButton *AdminSearchUserSubmitButton;
    QLineEdit *AdminSearchUserLineEdit;
    QGroupBox *groupBox;
    QLabel *EditProblemLabel;
    QComboBox *EditProblemComboBox;
    QLineEdit *EditProblemLineEdit;
    QPushButton *EditProblemSubmitButton;
    QTableView *EditProblemTableView;
    QFrame *line;
    QPushButton *AddProblemButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1048, 698);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainTabWidget = new QTabWidget(centralWidget);
        MainTabWidget->setObjectName(QStringLiteral("MainTabWidget"));
        MainTabWidget->setGeometry(QRect(0, -3, 1021, 641));
        HomepageTab = new QWidget();
        HomepageTab->setObjectName(QStringLiteral("HomepageTab"));
        graphicFrame = new QFrame(HomepageTab);
        graphicFrame->setObjectName(QStringLiteral("graphicFrame"));
        graphicFrame->setGeometry(QRect(30, 30, 201, 201));
        graphicFrame->setFrameShape(QFrame::StyledPanel);
        graphicFrame->setFrameShadow(QFrame::Raised);
        WelcomeLabel = new QLabel(HomepageTab);
        WelcomeLabel->setObjectName(QStringLiteral("WelcomeLabel"));
        WelcomeLabel->setGeometry(QRect(380, 50, 481, 51));
        TopRankedLabel = new QLabel(HomepageTab);
        TopRankedLabel->setObjectName(QStringLiteral("TopRankedLabel"));
        TopRankedLabel->setGeometry(QRect(280, 120, 261, 51));
        TopRankedTableView = new QTableView(HomepageTab);
        TopRankedTableView->setObjectName(QStringLiteral("TopRankedTableView"));
        TopRankedTableView->setGeometry(QRect(280, 190, 711, 381));
        LoginGroupBox = new QGroupBox(HomepageTab);
        LoginGroupBox->setObjectName(QStringLiteral("LoginGroupBox"));
        LoginGroupBox->setGeometry(QRect(870, 10, 141, 31));
        LoginPushButton = new QPushButton(LoginGroupBox);
        LoginPushButton->setObjectName(QStringLiteral("LoginPushButton"));
        LoginPushButton->setGeometry(QRect(0, 0, 141, 31));
        ProfileGroupBox = new QGroupBox(HomepageTab);
        ProfileGroupBox->setObjectName(QStringLiteral("ProfileGroupBox"));
        ProfileGroupBox->setGeometry(QRect(770, 10, 241, 31));
        LogoutPushButton = new QPushButton(ProfileGroupBox);
        LogoutPushButton->setObjectName(QStringLiteral("LogoutPushButton"));
        LogoutPushButton->setGeometry(QRect(170, 0, 71, 31));
        WelcomeUserLabel = new QLabel(ProfileGroupBox);
        WelcomeUserLabel->setObjectName(QStringLiteral("WelcomeUserLabel"));
        WelcomeUserLabel->setGeometry(QRect(1, 0, 161, 31));
        ConfigHostGroupBox = new QGroupBox(HomepageTab);
        ConfigHostGroupBox->setObjectName(QStringLiteral("ConfigHostGroupBox"));
        ConfigHostGroupBox->setGeometry(QRect(30, 300, 201, 211));
        HostLabel = new QLabel(ConfigHostGroupBox);
        HostLabel->setObjectName(QStringLiteral("HostLabel"));
        HostLabel->setGeometry(QRect(30, 32, 141, 41));
        HostLineEdit = new QLineEdit(ConfigHostGroupBox);
        HostLineEdit->setObjectName(QStringLiteral("HostLineEdit"));
        HostLineEdit->setGeometry(QRect(20, 92, 161, 31));
        HostSubmitButton = new QPushButton(ConfigHostGroupBox);
        HostSubmitButton->setObjectName(QStringLiteral("HostSubmitButton"));
        HostSubmitButton->setGeometry(QRect(20, 150, 161, 41));
        HostSubmitButton->setStyleSheet(QStringLiteral("font: 75 11pt \"Courier New\";"));
        MainTabWidget->addTab(HomepageTab, QString());
        ProblemsTab = new QWidget();
        ProblemsTab->setObjectName(QStringLiteral("ProblemsTab"));
        label = new QLabel(ProblemsTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 30, 381, 61));
        ProblemsTableView = new QTableView(ProblemsTab);
        ProblemsTableView->setObjectName(QStringLiteral("ProblemsTableView"));
        ProblemsTableView->setGeometry(QRect(190, 160, 641, 431));
        ProblemsSearchLabel = new QLabel(ProblemsTab);
        ProblemsSearchLabel->setObjectName(QStringLiteral("ProblemsSearchLabel"));
        ProblemsSearchLabel->setGeometry(QRect(200, 110, 221, 31));
        ProblemsSearchComboBox = new QComboBox(ProblemsTab);
        ProblemsSearchComboBox->setObjectName(QStringLiteral("ProblemsSearchComboBox"));
        ProblemsSearchComboBox->setGeometry(QRect(440, 110, 101, 31));
        ProblemsSearchLineEdit = new QLineEdit(ProblemsTab);
        ProblemsSearchLineEdit->setObjectName(QStringLiteral("ProblemsSearchLineEdit"));
        ProblemsSearchLineEdit->setGeometry(QRect(560, 110, 141, 31));
        ProblemsSearchSubmitButton = new QPushButton(ProblemsTab);
        ProblemsSearchSubmitButton->setObjectName(QStringLiteral("ProblemsSearchSubmitButton"));
        ProblemsSearchSubmitButton->setGeometry(QRect(720, 110, 101, 31));
        MainTabWidget->addTab(ProblemsTab, QString());
        StatusTab = new QWidget();
        StatusTab->setObjectName(QStringLiteral("StatusTab"));
        StatusLabel = new QLabel(StatusTab);
        StatusLabel->setObjectName(QStringLiteral("StatusLabel"));
        StatusLabel->setGeometry(QRect(390, 30, 241, 71));
        StatusTableView = new QTableView(StatusTab);
        StatusTableView->setObjectName(QStringLiteral("StatusTableView"));
        StatusTableView->setGeometry(QRect(140, 160, 741, 431));
        StatusSearchSubmitButton = new QPushButton(StatusTab);
        StatusSearchSubmitButton->setObjectName(QStringLiteral("StatusSearchSubmitButton"));
        StatusSearchSubmitButton->setGeometry(QRect(710, 110, 101, 31));
        StatusSearchLineEdit = new QLineEdit(StatusTab);
        StatusSearchLineEdit->setObjectName(QStringLiteral("StatusSearchLineEdit"));
        StatusSearchLineEdit->setGeometry(QRect(550, 110, 141, 31));
        StatusSearchComboBox = new QComboBox(StatusTab);
        StatusSearchComboBox->setObjectName(QStringLiteral("StatusSearchComboBox"));
        StatusSearchComboBox->setGeometry(QRect(430, 110, 101, 31));
        StatusSearchLabel = new QLabel(StatusTab);
        StatusSearchLabel->setObjectName(QStringLiteral("StatusSearchLabel"));
        StatusSearchLabel->setGeometry(QRect(190, 110, 221, 31));
        MainTabWidget->addTab(StatusTab, QString());
        RanklistTab = new QWidget();
        RanklistTab->setObjectName(QStringLiteral("RanklistTab"));
        RankListLabel = new QLabel(RanklistTab);
        RankListLabel->setObjectName(QStringLiteral("RankListLabel"));
        RankListLabel->setGeometry(QRect(320, 30, 381, 71));
        RankListTableView = new QTableView(RanklistTab);
        RankListTableView->setObjectName(QStringLiteral("RankListTableView"));
        RankListTableView->setGeometry(QRect(110, 130, 801, 431));
        MainTabWidget->addTab(RanklistTab, QString());
        ProfileTab = new QWidget();
        ProfileTab->setObjectName(QStringLiteral("ProfileTab"));
        SearchUserLabel = new QLabel(ProfileTab);
        SearchUserLabel->setObjectName(QStringLiteral("SearchUserLabel"));
        SearchUserLabel->setGeometry(QRect(80, 40, 151, 31));
        SearchUserLineEdit = new QLineEdit(ProfileTab);
        SearchUserLineEdit->setObjectName(QStringLiteral("SearchUserLineEdit"));
        SearchUserLineEdit->setGeometry(QRect(240, 40, 141, 31));
        SearchUserSubmitButton = new QPushButton(ProfileTab);
        SearchUserSubmitButton->setObjectName(QStringLiteral("SearchUserSubmitButton"));
        SearchUserSubmitButton->setGeometry(QRect(400, 40, 91, 31));
        UserProfileGroupBox = new QGroupBox(ProfileTab);
        UserProfileGroupBox->setObjectName(QStringLiteral("UserProfileGroupBox"));
        UserProfileGroupBox->setGeometry(QRect(80, 90, 421, 421));
        UserProfileNickLabel = new QLabel(UserProfileGroupBox);
        UserProfileNickLabel->setObjectName(QStringLiteral("UserProfileNickLabel"));
        UserProfileNickLabel->setGeometry(QRect(50, 44, 81, 31));
        UserProfileMottoLabel = new QLabel(UserProfileGroupBox);
        UserProfileMottoLabel->setObjectName(QStringLiteral("UserProfileMottoLabel"));
        UserProfileMottoLabel->setGeometry(QRect(50, 135, 81, 31));
        UserProfileGenderLabel = new QLabel(UserProfileGroupBox);
        UserProfileGenderLabel->setObjectName(QStringLiteral("UserProfileGenderLabel"));
        UserProfileGenderLabel->setGeometry(QRect(50, 224, 81, 31));
        UserProfileSolvedLabel = new QLabel(UserProfileGroupBox);
        UserProfileSolvedLabel->setObjectName(QStringLiteral("UserProfileSolvedLabel"));
        UserProfileSolvedLabel->setGeometry(QRect(30, 299, 81, 31));
        UserProfileAttemptedLabel = new QLabel(UserProfileGroupBox);
        UserProfileAttemptedLabel->setObjectName(QStringLiteral("UserProfileAttemptedLabel"));
        UserProfileAttemptedLabel->setGeometry(QRect(147, 299, 111, 31));
        UserProfileOrzByOthersLabel = new QLabel(UserProfileGroupBox);
        UserProfileOrzByOthersLabel->setObjectName(QStringLiteral("UserProfileOrzByOthersLabel"));
        UserProfileOrzByOthersLabel->setGeometry(QRect(280, 299, 131, 31));
        UserProfileSolvedLcdNumber = new QLCDNumber(UserProfileGroupBox);
        UserProfileSolvedLcdNumber->setObjectName(QStringLiteral("UserProfileSolvedLcdNumber"));
        UserProfileSolvedLcdNumber->setGeometry(QRect(34, 329, 71, 71));
        UserProfileSolvedLcdNumber->setMaximumSize(QSize(16777215, 71));
        UserProfileSolvedLcdNumber->setStyleSheet(QStringLiteral("font: 75 16pt \"Aharoni\";"));
        UserProfileAttemptedLcdNumber = new QLCDNumber(UserProfileGroupBox);
        UserProfileAttemptedLcdNumber->setObjectName(QStringLiteral("UserProfileAttemptedLcdNumber"));
        UserProfileAttemptedLcdNumber->setGeometry(QRect(165, 329, 71, 71));
        UserProfileAttemptedLcdNumber->setStyleSheet(QStringLiteral("font: 75 16pt \"Aharoni\";"));
        UserProfileOrzByOthersLcdNumber = new QLCDNumber(UserProfileGroupBox);
        UserProfileOrzByOthersLcdNumber->setObjectName(QStringLiteral("UserProfileOrzByOthersLcdNumber"));
        UserProfileOrzByOthersLcdNumber->setGeometry(QRect(310, 329, 71, 71));
        UserProfileOrzByOthersLcdNumber->setStyleSheet(QStringLiteral("font: 75 16pt \"Aharoni\";"));
        UserProfileNickLineEdit = new QLineEdit(UserProfileGroupBox);
        UserProfileNickLineEdit->setObjectName(QStringLiteral("UserProfileNickLineEdit"));
        UserProfileNickLineEdit->setGeometry(QRect(143, 44, 151, 31));
        UserProfileMottoTextEdit = new QTextEdit(UserProfileGroupBox);
        UserProfileMottoTextEdit->setObjectName(QStringLiteral("UserProfileMottoTextEdit"));
        UserProfileMottoTextEdit->setGeometry(QRect(143, 100, 151, 101));
        UserProfileOrzButton = new QPushButton(UserProfileGroupBox);
        UserProfileOrzButton->setObjectName(QStringLiteral("UserProfileOrzButton"));
        UserProfileOrzButton->setGeometry(QRect(280, 220, 121, 51));
        UserProfileOrzButton->setStyleSheet(QStringLiteral("font: 75 16pt \"Courier New\";"));
        layoutWidget = new QWidget(UserProfileGroupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(143, 214, 91, 62));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        UserProfileUnknownCheckBox = new QCheckBox(layoutWidget);
        UserProfileUnknownCheckBox->setObjectName(QStringLiteral("UserProfileUnknownCheckBox"));

        verticalLayout->addWidget(UserProfileUnknownCheckBox);

        UserProfileMaleCheckBox = new QCheckBox(layoutWidget);
        UserProfileMaleCheckBox->setObjectName(QStringLiteral("UserProfileMaleCheckBox"));

        verticalLayout->addWidget(UserProfileMaleCheckBox);

        UserProfileFemaleCheckBox = new QCheckBox(layoutWidget);
        UserProfileFemaleCheckBox->setObjectName(QStringLiteral("UserProfileFemaleCheckBox"));

        verticalLayout->addWidget(UserProfileFemaleCheckBox);

        EditProfileGroupBox = new QGroupBox(ProfileTab);
        EditProfileGroupBox->setObjectName(QStringLiteral("EditProfileGroupBox"));
        EditProfileGroupBox->setGeometry(QRect(590, 90, 391, 421));
        EditProfileMottoLabel = new QLabel(EditProfileGroupBox);
        EditProfileMottoLabel->setObjectName(QStringLiteral("EditProfileMottoLabel"));
        EditProfileMottoLabel->setGeometry(QRect(60, 263, 61, 27));
        label_3 = new QLabel(EditProfileGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(271, 210, 101, 20));
        EditProfileGenderLabel = new QLabel(EditProfileGroupBox);
        EditProfileGenderLabel->setObjectName(QStringLiteral("EditProfileGenderLabel"));
        EditProfileGenderLabel->setGeometry(QRect(50, 322, 71, 27));
        EditProfileNickLabel = new QLabel(EditProfileGroupBox);
        EditProfileNickLabel->setObjectName(QStringLiteral("EditProfileNickLabel"));
        EditProfileNickLabel->setGeometry(QRect(71, 207, 51, 27));
        EditProfileMottoTextEdit = new QTextEdit(EditProfileGroupBox);
        EditProfileMottoTextEdit->setObjectName(QStringLiteral("EditProfileMottoTextEdit"));
        EditProfileMottoTextEdit->setGeometry(QRect(131, 241, 131, 71));
        EditProfileNickLineEdit = new QLineEdit(EditProfileGroupBox);
        EditProfileNickLineEdit->setObjectName(QStringLiteral("EditProfileNickLineEdit"));
        EditProfileNickLineEdit->setGeometry(QRect(131, 210, 133, 20));
        EditProfileGenderComboBox = new QComboBox(EditProfileGroupBox);
        EditProfileGenderComboBox->setObjectName(QStringLiteral("EditProfileGenderComboBox"));
        EditProfileGenderComboBox->setGeometry(QRect(132, 325, 131, 22));
        EditProfileSubmitButton = new QPushButton(EditProfileGroupBox);
        EditProfileSubmitButton->setObjectName(QStringLiteral("EditProfileSubmitButton"));
        EditProfileSubmitButton->setGeometry(QRect(131, 363, 131, 41));
        label_4 = new QLabel(EditProfileGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(271, 266, 101, 20));
        EditProfileLabel = new QLabel(EditProfileGroupBox);
        EditProfileLabel->setObjectName(QStringLiteral("EditProfileLabel"));
        EditProfileLabel->setGeometry(QRect(17, 15, 361, 41));
        PasswordModifyGroupBox = new QGroupBox(EditProfileGroupBox);
        PasswordModifyGroupBox->setObjectName(QStringLiteral("PasswordModifyGroupBox"));
        PasswordModifyGroupBox->setGeometry(QRect(10, 63, 371, 131));
        EditProfileOldPWDLabel = new QLabel(PasswordModifyGroupBox);
        EditProfileOldPWDLabel->setObjectName(QStringLiteral("EditProfileOldPWDLabel"));
        EditProfileOldPWDLabel->setGeometry(QRect(25, 23, 91, 27));
        EditProfileConfirmLabel = new QLabel(PasswordModifyGroupBox);
        EditProfileConfirmLabel->setObjectName(QStringLiteral("EditProfileConfirmLabel"));
        EditProfileConfirmLabel->setGeometry(QRect(24, 93, 91, 27));
        label_2 = new QLabel(PasswordModifyGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(261, 62, 101, 20));
        EditProfileOldPWDLineEdit = new QLineEdit(PasswordModifyGroupBox);
        EditProfileOldPWDLineEdit->setObjectName(QStringLiteral("EditProfileOldPWDLineEdit"));
        EditProfileOldPWDLineEdit->setGeometry(QRect(121, 26, 133, 20));
        EditProfileConfirmLineEdit = new QLineEdit(PasswordModifyGroupBox);
        EditProfileConfirmLineEdit->setObjectName(QStringLiteral("EditProfileConfirmLineEdit"));
        EditProfileConfirmLineEdit->setGeometry(QRect(121, 96, 133, 20));
        EditProfileNewPWDLabel = new QLabel(PasswordModifyGroupBox);
        EditProfileNewPWDLabel->setObjectName(QStringLiteral("EditProfileNewPWDLabel"));
        EditProfileNewPWDLabel->setGeometry(QRect(25, 57, 91, 27));
        EditProfileNewPWDLineEdit = new QLineEdit(PasswordModifyGroupBox);
        EditProfileNewPWDLineEdit->setObjectName(QStringLiteral("EditProfileNewPWDLineEdit"));
        EditProfileNewPWDLineEdit->setGeometry(QRect(121, 61, 133, 20));
        MainTabWidget->addTab(ProfileTab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        AdminGroupBox = new QGroupBox(tab);
        AdminGroupBox->setObjectName(QStringLiteral("AdminGroupBox"));
        AdminGroupBox->setGeometry(QRect(30, 30, 961, 571));
        EditUserGroupBox = new QGroupBox(AdminGroupBox);
        EditUserGroupBox->setObjectName(QStringLiteral("EditUserGroupBox"));
        EditUserGroupBox->setGeometry(QRect(20, 30, 391, 521));
        EditUserMottoLabel = new QLabel(EditUserGroupBox);
        EditUserMottoLabel->setObjectName(QStringLiteral("EditUserMottoLabel"));
        EditUserMottoLabel->setGeometry(QRect(60, 327, 61, 27));
        label_5 = new QLabel(EditUserGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(271, 250, 101, 20));
        EditUserGenderLabel = new QLabel(EditUserGroupBox);
        EditUserGenderLabel->setObjectName(QStringLiteral("EditUserGenderLabel"));
        EditUserGenderLabel->setGeometry(QRect(50, 407, 71, 27));
        EditUserNickLabel = new QLabel(EditUserGroupBox);
        EditUserNickLabel->setObjectName(QStringLiteral("EditUserNickLabel"));
        EditUserNickLabel->setGeometry(QRect(71, 247, 51, 27));
        EditUserMottoTextEdit = new QTextEdit(EditUserGroupBox);
        EditUserMottoTextEdit->setObjectName(QStringLiteral("EditUserMottoTextEdit"));
        EditUserMottoTextEdit->setGeometry(QRect(131, 295, 131, 91));
        EditUserNickLineEdit = new QLineEdit(EditUserGroupBox);
        EditUserNickLineEdit->setObjectName(QStringLiteral("EditUserNickLineEdit"));
        EditUserNickLineEdit->setGeometry(QRect(131, 250, 133, 20));
        EditUserGenderComboBox = new QComboBox(EditUserGroupBox);
        EditUserGenderComboBox->setObjectName(QStringLiteral("EditUserGenderComboBox"));
        EditUserGenderComboBox->setGeometry(QRect(132, 410, 131, 22));
        EditUserSubmitButton = new QPushButton(EditUserGroupBox);
        EditUserSubmitButton->setObjectName(QStringLiteral("EditUserSubmitButton"));
        EditUserSubmitButton->setGeometry(QRect(131, 456, 131, 41));
        label_6 = new QLabel(EditUserGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(271, 330, 101, 20));
        AdminPasswordModifyGroupBox = new QGroupBox(EditUserGroupBox);
        AdminPasswordModifyGroupBox->setObjectName(QStringLiteral("AdminPasswordModifyGroupBox"));
        AdminPasswordModifyGroupBox->setGeometry(QRect(10, 110, 371, 111));
        EditUserConfirmLabel = new QLabel(AdminPasswordModifyGroupBox);
        EditUserConfirmLabel->setObjectName(QStringLiteral("EditUserConfirmLabel"));
        EditUserConfirmLabel->setGeometry(QRect(24, 67, 91, 27));
        label_7 = new QLabel(AdminPasswordModifyGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(261, 28, 101, 20));
        EditUserConfirmLineEdit = new QLineEdit(AdminPasswordModifyGroupBox);
        EditUserConfirmLineEdit->setObjectName(QStringLiteral("EditUserConfirmLineEdit"));
        EditUserConfirmLineEdit->setGeometry(QRect(121, 70, 133, 20));
        EditUserNewPWDLabel = new QLabel(AdminPasswordModifyGroupBox);
        EditUserNewPWDLabel->setObjectName(QStringLiteral("EditUserNewPWDLabel"));
        EditUserNewPWDLabel->setGeometry(QRect(25, 24, 91, 27));
        EditUserNewPWDLineEdit = new QLineEdit(AdminPasswordModifyGroupBox);
        EditUserNewPWDLineEdit->setObjectName(QStringLiteral("EditUserNewPWDLineEdit"));
        EditUserNewPWDLineEdit->setGeometry(QRect(121, 28, 133, 20));
        AdminSearchUserLabel = new QLabel(EditUserGroupBox);
        AdminSearchUserLabel->setObjectName(QStringLiteral("AdminSearchUserLabel"));
        AdminSearchUserLabel->setGeometry(QRect(61, 30, 141, 31));
        AdminSearchUserSubmitButton = new QPushButton(EditUserGroupBox);
        AdminSearchUserSubmitButton->setObjectName(QStringLiteral("AdminSearchUserSubmitButton"));
        AdminSearchUserSubmitButton->setGeometry(QRect(150, 70, 91, 31));
        AdminSearchUserLineEdit = new QLineEdit(EditUserGroupBox);
        AdminSearchUserLineEdit->setObjectName(QStringLiteral("AdminSearchUserLineEdit"));
        AdminSearchUserLineEdit->setGeometry(QRect(210, 30, 111, 31));
        groupBox = new QGroupBox(AdminGroupBox);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(450, 30, 501, 521));
        EditProblemLabel = new QLabel(groupBox);
        EditProblemLabel->setObjectName(QStringLiteral("EditProblemLabel"));
        EditProblemLabel->setGeometry(QRect(13, 30, 221, 31));
        EditProblemComboBox = new QComboBox(groupBox);
        EditProblemComboBox->setObjectName(QStringLiteral("EditProblemComboBox"));
        EditProblemComboBox->setGeometry(QRect(237, 30, 91, 31));
        EditProblemLineEdit = new QLineEdit(groupBox);
        EditProblemLineEdit->setObjectName(QStringLiteral("EditProblemLineEdit"));
        EditProblemLineEdit->setGeometry(QRect(336, 30, 81, 31));
        EditProblemSubmitButton = new QPushButton(groupBox);
        EditProblemSubmitButton->setObjectName(QStringLiteral("EditProblemSubmitButton"));
        EditProblemSubmitButton->setGeometry(QRect(425, 30, 60, 31));
        EditProblemTableView = new QTableView(groupBox);
        EditProblemTableView->setObjectName(QStringLiteral("EditProblemTableView"));
        EditProblemTableView->setGeometry(QRect(20, 70, 461, 301));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 370, 461, 40));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        AddProblemButton = new QPushButton(groupBox);
        AddProblemButton->setObjectName(QStringLiteral("AddProblemButton"));
        AddProblemButton->setGeometry(QRect(20, 400, 461, 111));
        AddProblemButton->setStyleSheet(QLatin1String("font: 75 48pt \"Aharoni\";\n"
"font: 75 36pt \"Courier New\";"));
        MainTabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1048, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        MainTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        WelcomeLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">Welcome to Gromah OJ</span></p></body></html>", 0));
        TopRankedLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:22pt;\">Top Ranked Users</span></p></body></html>", 0));
        LoginGroupBox->setTitle(QString());
        LoginPushButton->setText(QApplication::translate("MainWindow", "Login / Register", 0));
        ProfileGroupBox->setTitle(QString());
        LogoutPushButton->setText(QApplication::translate("MainWindow", "Logout", 0));
        WelcomeUserLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">TextLabel</p></body></html>", 0));
        ConfigHostGroupBox->setTitle(QApplication::translate("MainWindow", "Config Host", 0));
        HostLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">Input Host</span></p></body></html>", 0));
        HostSubmitButton->setText(QApplication::translate("MainWindow", "Submit And Start", 0));
        MainTabWidget->setTabText(MainTabWidget->indexOf(HomepageTab), QApplication::translate("MainWindow", "Tab 1", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">Problems</span></p></body></html>", 0));
        ProblemsSearchLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Search Problems By</span></p></body></html>", 0));
        ProblemsSearchComboBox->clear();
        ProblemsSearchComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Problem Id", 0)
         << QApplication::translate("MainWindow", "Name", 0)
         << QApplication::translate("MainWindow", "Source", 0)
        );
        ProblemsSearchSubmitButton->setText(QApplication::translate("MainWindow", "Submit", 0));
        MainTabWidget->setTabText(MainTabWidget->indexOf(ProblemsTab), QApplication::translate("MainWindow", "Tab 2", 0));
        StatusLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">Status</span></p></body></html>", 0));
        StatusSearchSubmitButton->setText(QApplication::translate("MainWindow", "Submit", 0));
        StatusSearchComboBox->clear();
        StatusSearchComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Run Id", 0)
         << QApplication::translate("MainWindow", "Problem Id", 0)
         << QApplication::translate("MainWindow", "User Id", 0)
         << QApplication::translate("MainWindow", "Result", 0)
        );
        StatusSearchLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt;\">Search Status By</span></p></body></html>", 0));
        MainTabWidget->setTabText(MainTabWidget->indexOf(StatusTab), QApplication::translate("MainWindow", "\351\241\265", 0));
        RankListLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">RankList</span></p></body></html>", 0));
        MainTabWidget->setTabText(MainTabWidget->indexOf(RanklistTab), QApplication::translate("MainWindow", "\351\241\265", 0));
        SearchUserLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Search User</span></p></body></html>", 0));
        SearchUserSubmitButton->setText(QApplication::translate("MainWindow", "Submit", 0));
        UserProfileGroupBox->setTitle(QApplication::translate("MainWindow", "UserProfile", 0));
        UserProfileNickLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Nick</span></p></body></html>", 0));
        UserProfileMottoLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Motto</span></p></body></html>", 0));
        UserProfileGenderLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Gender</span></p></body></html>", 0));
        UserProfileSolvedLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Solved</span></p></body></html>", 0));
        UserProfileAttemptedLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Attempted</span></p></body></html>", 0));
        UserProfileOrzByOthersLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">OrzByOthers</span></p></body></html>", 0));
        UserProfileOrzButton->setText(QApplication::translate("MainWindow", "Just Orz", 0));
        UserProfileUnknownCheckBox->setText(QApplication::translate("MainWindow", "Unknown", 0));
        UserProfileMaleCheckBox->setText(QApplication::translate("MainWindow", "Male", 0));
        UserProfileFemaleCheckBox->setText(QApplication::translate("MainWindow", "Female", 0));
        EditProfileGroupBox->setTitle(QApplication::translate("MainWindow", "EditProfile", 0));
        EditProfileMottoLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Motto</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "(Max Length 16)", 0));
        EditProfileGenderLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Gender</span></p></body></html>", 0));
        EditProfileNickLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Nick</span></p></body></html>", 0));
        EditProfileGenderComboBox->clear();
        EditProfileGenderComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Unknown", 0)
         << QApplication::translate("MainWindow", "Male", 0)
         << QApplication::translate("MainWindow", "Female", 0)
        );
        EditProfileSubmitButton->setText(QApplication::translate("MainWindow", "Submit", 0));
        label_4->setText(QApplication::translate("MainWindow", "(Max Length 50)", 0));
        EditProfileLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">Current User</span></p></body></html>", 0));
        PasswordModifyGroupBox->setTitle(QApplication::translate("MainWindow", "PasswordModify", 0));
        EditProfileOldPWDLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Old PWD</span></p></body></html>", 0));
        EditProfileConfirmLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Confirm</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "(Max Length 16)", 0));
        EditProfileNewPWDLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">New PWD</span></p></body></html>", 0));
        MainTabWidget->setTabText(MainTabWidget->indexOf(ProfileTab), QApplication::translate("MainWindow", "\351\241\265", 0));
        AdminGroupBox->setTitle(QApplication::translate("MainWindow", "Administration", 0));
        EditUserGroupBox->setTitle(QApplication::translate("MainWindow", "Edit User", 0));
        EditUserMottoLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Motto</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("MainWindow", "(Max Length 16)", 0));
        EditUserGenderLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Gender</span></p></body></html>", 0));
        EditUserNickLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Nick</span></p></body></html>", 0));
        EditUserGenderComboBox->clear();
        EditUserGenderComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Unknown", 0)
         << QApplication::translate("MainWindow", "Male", 0)
         << QApplication::translate("MainWindow", "Female", 0)
        );
        EditUserSubmitButton->setText(QApplication::translate("MainWindow", "Submit", 0));
        label_6->setText(QApplication::translate("MainWindow", "(Max Length 50)", 0));
        AdminPasswordModifyGroupBox->setTitle(QApplication::translate("MainWindow", "PasswordModify", 0));
        EditUserConfirmLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">Confirm</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("MainWindow", "(Max Length 16)", 0));
        EditUserNewPWDLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">New PWD</span></p></body></html>", 0));
        AdminSearchUserLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Search User</span></p></body></html>", 0));
        AdminSearchUserSubmitButton->setText(QApplication::translate("MainWindow", "Submit", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Edit Problem", 0));
        EditProblemLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Search Problems By</span></p></body></html>", 0));
        EditProblemComboBox->clear();
        EditProblemComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Problem Id", 0)
         << QApplication::translate("MainWindow", "Name", 0)
         << QApplication::translate("MainWindow", "Source", 0)
        );
        EditProblemSubmitButton->setText(QApplication::translate("MainWindow", "Submit", 0));
        AddProblemButton->setText(QApplication::translate("MainWindow", "Add A Problem", 0));
        MainTabWidget->setTabText(MainTabWidget->indexOf(tab), QApplication::translate("MainWindow", "\351\241\265", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
