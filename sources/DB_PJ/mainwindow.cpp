#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHeaderView>
#include <QMessageBox>

#include "db.h"
#include "config.h"
#include "session.h"

static const int MAX_DISPLAY = 10;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login = new Login(this);
    problems = new Problems(this);
    editProblem = new EditProblem(this);
    MainTableModel = new QStandardItemModel();
    RankListModel = new QStandardItemModel();
    ProblemsModel = new QStandardItemModel();
    StatusModel = new QStandardItemModel();
    EditProblemModel = new QStandardItemModel();

    // Configures
    Config::Init(ui);
    ui -> EditProfileGroupBox -> hide();
    ui -> ProfileGroupBox -> hide();
    ui -> AdminGroupBox -> hide();
    ui -> HostLineEdit -> setText("192.168.1.107");
    ui -> UserLineEdit -> setText("root");
    ui -> PasswordLineEdit -> setText("gromah");

    // Set Size
    this -> setMinimumSize(1024,666);
    this -> setMaximumSize(1024,666);

    // Set Title
    this -> setWindowTitle("Gromah Online Judge");

    // Set Icon
    QString strPath = QApplication :: applicationDirPath();
    strPath += "/img/gromah.png";
    this -> setWindowIcon(QIcon(strPath));

    // Set Brand
    QPixmap pixmap(strPath);
    QPalette palette;
    palette.setBrush(ui -> graphicFrame -> backgroundRole(), QBrush(pixmap));
    ui -> graphicFrame -> setPalette(palette);
    ui -> graphicFrame -> setAutoFillBackground(true);

    // Set Slots
    QObject::connect(ui -> LoginPushButton, SIGNAL(clicked(bool)), this, SLOT(LoginButtonPressed()));
    QObject::connect(ui -> LogoutPushButton, SIGNAL(clicked(bool)), this, SLOT(LogoutButtonPressed()));
    QObject::connect(login, SIGNAL(Refresh(bool)), this, SLOT(ReceiveRefresh(bool)));
    QObject::connect(problems, SIGNAL(Refresh(bool)), this, SLOT(ReceiveRefresh(bool)));
    QObject::connect(editProblem, SIGNAL(Refresh(bool)), this, SLOT(ReceiveRefresh(bool)));
    QObject::connect(ui -> HostLineEdit, SIGNAL(returnPressed()), this, SLOT(HostButtonPressed()));
    QObject::connect(ui -> UserLineEdit, SIGNAL(returnPressed()), this, SLOT(HostButtonPressed()));
    QObject::connect(ui -> PasswordLineEdit, SIGNAL(returnPressed()), this, SLOT(HostButtonPressed()));
    QObject::connect(ui -> HostSubmitButton, SIGNAL(clicked(bool)), this, SLOT(HostButtonPressed()));
    QObject::connect(ui -> SearchUserLineEdit, SIGNAL(returnPressed()), this, SLOT(SearchUserButtonPressed()));
    QObject::connect(ui -> SearchUserSubmitButton, SIGNAL(clicked(bool)), this, SLOT(SearchUserButtonPressed()));
    QObject::connect(ui -> ProblemsSearchLineEdit, SIGNAL(returnPressed()), this, SLOT(ProblemsSearchButtonPressed()));
    QObject::connect(ui -> ProblemsSearchSubmitButton, SIGNAL(clicked(bool)), this, SLOT(ProblemsSearchButtonPressed()));
    QObject::connect(ui -> StatusSearchLineEdit, SIGNAL(returnPressed()), this, SLOT(StatusSearchButtonPressed()));
    QObject::connect(ui -> StatusSearchSubmitButton, SIGNAL(clicked(bool)), this, SLOT(StatusSearchButtonPressed()));
    QObject::connect(ui -> UserProfileOrzButton, SIGNAL(clicked(bool)), this, SLOT(OrzButtonPressed()));
    QObject::connect(ui -> EditProfileSubmitButton, SIGNAL(clicked(bool)), this, SLOT(EditProfileSubmitButtonPressed()));
    QObject::connect(ui -> AdminSearchUserLineEdit, SIGNAL(returnPressed()), this, SLOT(AdminSearchUserButtonPressed()));
    QObject::connect(ui -> AdminSearchUserSubmitButton, SIGNAL(clicked(bool)), this, SLOT(AdminSearchUserButtonPressed()));
    QObject::connect(ui -> EditUserSubmitButton, SIGNAL(clicked(bool)), this, SLOT(EditUserSubmitButtonPressed()));
    QObject::connect(ui -> EditProblemLineEdit, SIGNAL(returnPressed()), this, SLOT(EditProblemSubmitButtonPressed()));
    QObject::connect(ui -> EditProblemSubmitButton, SIGNAL(clicked(bool)), this, SLOT(EditProblemSubmitButtonPressed()));
    QObject::connect(ui -> AddProblemButton, SIGNAL(clicked(bool)), this, SLOT(AddProblemButtonPressed()));
    QObject::connect(ui -> RankListTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(RankListTabelClicked(QModelIndex)));
    QObject::connect(ui -> ProblemsTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(ProblemsTabelClicked(QModelIndex)));
    QObject::connect(ui -> StatusTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(StatusTabelClicked(QModelIndex)));
    QObject::connect(ui -> EditProblemTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(EditProblemTabelClicked(QModelIndex)));
}

void MainWindow::Start()
{
    // Initializations
    bool res = DataBase::Init();
    if (res == false)
        QMessageBox::warning(this, "Error", "Connection Error");
    Session::Init();
    // Render
    Render();
}

void MainWindow::ReceiveRefresh(bool reset)
{
    if (reset)
    {
        this -> show();
        Render();
        GenerateUserProfileGroupBox();
    }
}

void MainWindow::Render()
{
    SearchSession.Clear();
    ui -> ProblemsSearchComboBox -> setCurrentIndex(0);
    ui -> ProblemsSearchLineEdit -> clear();
    ui -> StatusSearchComboBox -> setCurrentIndex(0);
    ui -> StatusSearchLineEdit -> clear();
    GenerateLoginGroupBoxes();
    GenerateConfigHostGroupBox();
    GenerateUserTableView();
    GenerateProblemTableView();
    GenerateStatusTableView();
    AdminRender();
}

void MainWindow::AdminRender()
{
    if (Session::IsAdmin())
        ui -> AdminGroupBox -> show();
    else ui -> AdminGroupBox -> hide();
    GenerateUserEditGroupBox();
    GenerateProblemEditGroupBox();
}

void MainWindow::Add(QStandardItemModel *model, int row, int col, QString s)
{
    QStandardItem *tmp = new QStandardItem(s);
    tmp -> setTextAlignment(Qt::AlignCenter);
    model -> setItem(row, col, tmp);
}

void MainWindow::Orz(QString user)
{
    if (Session::IsLogin() && user == Session::GetCurrentUser() && !Session::IsAdmin())
    {
        QMessageBox::warning(this, "Oops", "Sorry, You Can't Orz Yourself.\n\nPlease Orz other Users or Logout to Orz Yourself.");
        return ;
    }
    QString instr = "SELECT OrzByOthers FROM Users WHERE Id = '" + user + "';";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    int cur = rec[0][0].toInt();
    int now = std::min(cur + 1, 233);
    QString *logs = new QString;
    bool res = Session::Update(user, "OrzByOthers", now, true, logs);
    if (res == false)
        QMessageBox::warning(this, "Error", *logs);
    else
    {
        GenerateUserProfileGroupBox();
        GenerateUserTableView();
    }
}

void MainWindow::GenerateLoginGroupBoxes()
{
    if (Session::IsLogin())
    {
        ui -> EditProfileGroupBox -> show();
        ui -> ProfileGroupBox -> show();
        ui -> LoginGroupBox -> hide();
        ui -> WelcomeUserLabel -> setText("Welcome, " + Session::GetCurrentUser());
        EditProfileInit();
    }
    else
    {
        ui -> EditProfileGroupBox -> hide();
        ui -> ProfileGroupBox -> hide();
        ui -> LoginGroupBox -> show();
    }
}

void MainWindow::GenerateUserTableView()
{
    const int COLUMNS = 6;
    const QString Lables[COLUMNS] = {"Id", "Nick", "Motto", "Solved", "Attempted", "OrzByOthers"};
    QString Paras;
    MainTableModel -> clear();
    RankListModel -> clear();
    MainTableModel -> setColumnCount(COLUMNS);
    RankListModel -> setColumnCount(COLUMNS + 1);
    for (int i = 0; i < COLUMNS; i ++)
    {
        Paras = Paras + Lables[i];
        if (i < COLUMNS - 1) Paras = Paras + ",";
        MainTableModel -> setHeaderData(i, Qt::Horizontal, Lables[i]);
        RankListModel -> setHeaderData(i, Qt::Horizontal, Lables[i]);
    }
    RankListModel -> setHeaderData(COLUMNS, Qt::Horizontal, "Click to Orz");
    QString instr = "SELECT " + Paras + " FROM Users" + " ORDER BY Solved DESC, Attempted ASC, OrzByOthers DESC" + " LIMIT 10;";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    for (size_t row = 0; row < rec.size() && row < MAX_DISPLAY; row ++)
    {
        QString& Motto = rec[row][2];
        QChar enter = '\n', space = ' ';
        Motto.replace(enter, space);
        for (size_t col = 0; col < rec[row].size(); col ++)
            Add(MainTableModel, row, col, rec[row][col]);
    }
    for (size_t row = 0; row < rec.size(); row ++)
    {
        QString user = rec[row][0];
        QString instr = "SELECT Gender FROM Users WHERE Id = '" + user + "';";
        QString Gender = DataBase::SelectInstr(instr)[0][0];
        if (Gender == "Unknown") Gender = "it";
        else if (Gender == "Male") Gender = "him";
        else Gender = "her";
        QString& Motto = rec[row][2];
        QChar enter = '\n', space = ' ';
        Motto.replace(enter, space);
        for (size_t col = 0; col < rec[row].size(); col ++)
            Add(RankListModel, row, col, rec[row][col]);
        QString Display = (Session::GetCurrentUser() == user && !Session::IsAdmin()) ? "" : "Orz " + (Session::GetCurrentUser() == Session::admin && Session::GetCurrentUser() == user ? "MYSELF !!!" : Gender);
        Add(RankListModel, row, COLUMNS, Display);
    }

    ui -> TopRankedTableView -> setModel(MainTableModel);
    // ui -> TopRankedTableView -> resizeColumnToContents(0);
    // ui -> TopRankedTableView -> resizeColumnToContents(1);
    ui -> TopRankedTableView -> resizeColumnToContents(2);
    // ui -> TopRankedTableView -> verticalHeader() -> hide();

    ui -> RankListTableView -> setModel(RankListModel);
    // ui -> RankListTableView -> resizeColumnToContents(1);
    ui -> RankListTableView -> resizeColumnToContents(2);
}

void MainWindow::GenerateProblemTableView()
{
    const int COLUMNS = 6;
    const QString Lables[COLUMNS] = {"Problem Id", "Name", "Source", "User Solved", "User Attempted", ""};
    ProblemsModel -> clear();
    ProblemsModel -> setColumnCount(COLUMNS);
    for (int i = 0; i < COLUMNS; i ++)
        ProblemsModel -> setHeaderData(i, Qt::Horizontal, Lables[i]);
    QString field = SearchSession.GetProbField();
    QString input = SearchSession.GetProbInput();
    QString instr;
    if (field.isEmpty())
        instr = Problems::SearchProblemsInstruction("Id, Name, Source", "", "", "", "ORDER BY Id ASC");
    else if (field == "Problem Id")
        instr = Problems::SearchProblemsInstruction("Id, Name, Source", input, "", "", "ORDER BY Id ASC");
    else if (field == "Name")
        instr = Problems::SearchProblemsInstruction("Id, Name, Source", "", input, "", "ORDER BY Id ASC");
    else instr = Problems::SearchProblemsInstruction("Id, Name, Source", "", "", input, "ORDER BY Id ASC");
    DataBase::Record rec = DataBase::SelectInstr(instr);
    for (size_t row = 0; row < rec.size(); row ++)
    {
        for (size_t col = 0; col < rec[row].size(); col ++)
            Add(ProblemsModel, row, col, rec[row][col]);

        QString str;
        DataBase::Record tmp;
        tmp = DataBase::SelectInstr("SELECT distinct UserId FROM Status WHERE Result = 'Correct' AND ProblemId = " + rec[row][0] + ";");
        str.setNum(tmp.size());
        Add(ProblemsModel, row, 3, str);
        tmp = DataBase::SelectInstr("SELECT distinct UserId FROM Status WHERE ProblemId = " + rec[row][0] + ";");
        str.setNum(tmp.size());
        Add(ProblemsModel, row, 4, str);

        Add(ProblemsModel, row, 5, "Enter");
    }
    ui -> ProblemsTableView -> setModel(ProblemsModel);
    ui -> ProblemsTableView -> verticalHeader() -> hide();
    // ui -> ProblemsTableView -> resizeColumnToContents(3);
    ui -> ProblemsTableView -> resizeColumnToContents(4);
}

void MainWindow::GenerateStatusTableView()
{
    const int COLUMNS = 7;
    const QString Lables[COLUMNS] = {"Run Id", "Problem Id", "User Id", "Answer Length", "Result", "Submit Time", ""};
    QString Paras;
    StatusModel -> clear();
    StatusModel -> setColumnCount(COLUMNS);
    for (int i = 0; i < COLUMNS; i ++)
    {
        Paras = Paras + Lables[i];
        if (i < COLUMNS - 1) Paras = Paras + ",";
        StatusModel -> setHeaderData(i, Qt::Horizontal, Lables[i]);
    }
    QString field = SearchSession.GetStatusField();
    QString input = SearchSession.GetStatusInput();
    QString paras = "Id, ProblemId, UserId, SubmitAnswer, Result, SubmitDate";
    QString instr;
    if (field.isEmpty())
        instr = Problems::SearchStatusInstruction(paras, "", "", "", "", "ORDER BY Id DESC");
    else if (field == "Run Id")
        instr = Problems::SearchStatusInstruction(paras, input, "", "", "", "ORDER BY Id DESC");
    else if (field == "Problem Id")
        instr = Problems::SearchStatusInstruction(paras, "", input, "", "", "ORDER BY Id DESC");
    else if (field == "User Id")
        instr = Problems::SearchStatusInstruction(paras, "", "", input, "", "ORDER BY Id DESC");
    else instr = Problems::SearchStatusInstruction(paras, "", "", "", input, "ORDER BY Id DESC");
    DataBase::Record rec = DataBase::SelectInstr(instr);
    for (size_t row = 0; row < rec.size(); row ++)
    {
        for (size_t col = 0; col < rec[row].size(); col ++)
        {
            if (col == 3)
            {
                int _len = rec[row][col].size();
                rec[row][col].setNum(_len);
            }
            Add(StatusModel, row, col, rec[row][col]);
        }
        if (Session::IsAdmin() || Session::GetCurrentUser() == rec[row][2])
            Add(StatusModel, row, 6, "Show Answer");
    }
    ui -> StatusTableView -> setModel(StatusModel);
    ui -> StatusTableView -> resizeColumnToContents(5);
    ui -> StatusTableView -> verticalHeader() -> hide();
}

void MainWindow::GenerateConfigHostGroupBox()
{
    ui -> HostLineEdit -> setText(DataBase::GetHost());
    ui -> UserLineEdit -> setText(DataBase::GetUser());
    ui -> PasswordLineEdit -> clear();
}

void MainWindow::GenerateUserProfileGroupBox()
{
    if (Session::GetSearchUser().isEmpty())
    {
        ui -> UserProfileNickLineEdit -> clear();
        ui -> UserProfileMottoTextEdit -> clear();
        ui -> UserProfileUnknownCheckBox -> setCheckState(Qt::Unchecked);
        ui -> UserProfileMaleCheckBox -> setCheckState(Qt::Unchecked);
        ui -> UserProfileFemaleCheckBox -> setCheckState(Qt::Unchecked);
        ui -> UserProfileSolvedLcdNumber -> display(0);
        ui -> UserProfileAttemptedLcdNumber -> display(0);
        ui -> UserProfileOrzByOthersLcdNumber -> display(0);
        return ;
    }
    QString instr = "SELECT Nick, Motto, Gender, Solved, Attempted, OrzByOthers FROM Users WHERE Id = '" + Session::GetSearchUser() + "';";
    bool *ok = new bool;
    DataBase::Record rec = DataBase::SelectInstr(instr, ok);
    if (!ok || rec.size() != 1)
        QMessageBox::warning(this, "Error", "Failed to Search User.");
    else
    {
        ui -> UserProfileNickLineEdit -> setText(rec[0][0]);
        ui -> UserProfileMottoTextEdit -> setText(rec[0][1]);
        ui -> UserProfileUnknownCheckBox -> setCheckState(rec[0][2] == "Unknown" ? Qt::Checked : Qt::Unchecked);
        ui -> UserProfileMaleCheckBox -> setCheckState(rec[0][2] == "Male" ? Qt::Checked : Qt::Unchecked);
        ui -> UserProfileFemaleCheckBox -> setCheckState(rec[0][2] == "Female" ? Qt::Checked : Qt::Unchecked);
        ui -> UserProfileSolvedLcdNumber -> display(rec[0][3].toInt());
        ui -> UserProfileAttemptedLcdNumber -> display(rec[0][4].toInt());
        ui -> UserProfileOrzByOthersLcdNumber -> display(rec[0][5].toInt());
    }
}

void MainWindow::GenerateUserEditGroupBox()
{
    if (Admin.GetAdminUser().isEmpty())
    {
        InitUserEditGroupBox();
        return ;
    }
    QString instr = "SELECT Nick, Motto, Gender FROM Users WHERE Id = '" + Admin.GetAdminUser() + "';";
    bool *ok = new bool;
    DataBase::Record rec = DataBase::SelectInstr(instr, ok);
    if (!ok || rec.size() != 1)
        QMessageBox::warning(this, "Error", "Failed to Search User.");
    else
    {
        ui -> EditUserNewPWDLineEdit -> clear();
        ui -> EditUserConfirmLineEdit -> clear();
        ui -> EditUserNickLineEdit -> setText(rec[0][0]);
        ui -> EditUserMottoTextEdit -> setText(rec[0][1]);
        ui -> EditUserGenderComboBox -> setCurrentIndex(rec[0][2] == "Male" ? 1 : (rec[0][2] == "Female" ? 2 : 0));
    }
}

void MainWindow::InitUserEditGroupBox()
{
    ui -> AdminSearchUserLineEdit -> clear();
    ui -> EditUserNewPWDLineEdit -> clear();
    ui -> EditUserConfirmLineEdit -> clear();
    ui -> EditUserNickLineEdit -> clear();
    ui -> EditUserMottoTextEdit -> clear();
    ui -> EditUserGenderComboBox -> setCurrentIndex(0);
}

void MainWindow::EditProfileInit()
{
    QString user = Session::GetCurrentUser();
    QString instr = "SELECT Nick, Motto, Gender FROM Users WHERE Id = '" + user + "';";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    ui -> EditProfileLabel -> setText("Current User : " + user);
    ui -> EditProfileOldPWDLineEdit -> clear();
    ui -> EditProfileNewPWDLineEdit -> clear();
    ui -> EditProfileConfirmLineEdit -> clear();
    ui -> EditProfileNickLineEdit -> setText(rec[0][0]);
    ui -> EditProfileMottoTextEdit -> setText(rec[0][1]);
    ui -> EditProfileGenderComboBox -> setCurrentIndex(rec[0][2] == "Male" ? 1 : (rec[0][2] == "Female" ? 2 : 0));
}

void MainWindow::GenerateProblemEditGroupBox()
{
    const int COLUMNS = 5;
    QString Lables[COLUMNS] = {"Problem Id", "Name", "Source", "", ""};
    EditProblemModel -> clear();
    EditProblemModel -> setColumnCount(COLUMNS);
    for (int i = 0; i < COLUMNS; i ++)
        EditProblemModel -> setHeaderData(i, Qt::Horizontal, Lables[i]);
    QString field = Admin.GetAdminField();
    QString input = Admin.GetAdminInput();
    QString instr;
    if (field == "Problem Id")
        instr = Problems::SearchProblemsInstruction("Id, Name, Source", input, "", "", "ORDER BY Id ASC");
    else if (field == "Name")
        instr = Problems::SearchProblemsInstruction("Id, Name, Source", "", input, "", "ORDER BY Id ASC");
    else instr = Problems::SearchProblemsInstruction("Id, Name, Source", "", "", input, "ORDER BY Id ASC");
    DataBase::Record rec = DataBase::SelectInstr(instr);
    for (size_t row = 0; row < rec.size(); row ++)
    {
        for (size_t col = 0; col < rec[row].size(); col ++)
            Add(EditProblemModel, row, col, rec[row][col]);
        Add(EditProblemModel, row, 3, "Edit");
        QString instr = "SELECT Hidden FROM Problems WHERE Id = " + rec[row][0] + ";";
        DataBase::Record rec = DataBase::SelectInstr(instr);
        bool hidden = rec[0][0].toInt();
        QString ProbAction = hidden ? "Show" : "Hide";
        Add(EditProblemModel, row, 4, ProbAction);
    }
    ui -> EditProblemTableView -> setModel(EditProblemModel);
    // ui -> EditProblemTableView -> resizeColumnToContents(3);
    ui -> EditProblemTableView -> resizeColumnToContents(4);
    ui -> EditProblemTableView -> verticalHeader() -> hide();
}

void MainWindow::EditOrAddProblem(int pid)
{
    editProblem -> Handle(pid);
}

void MainWindow::HostButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString host = ui -> HostLineEdit -> text();
    QString user = ui -> UserLineEdit -> text();
    QString password = ui -> PasswordLineEdit -> text();
    DataBase::SetHost(host);
    DataBase::SetUser(user);
    DataBase::SetPassword(password);
    Start();
}

void MainWindow::LoginButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
#ifdef DEBUG
    qDebug() << "LoginPushButton Pressed." << endl;
#endif
    login -> show();
}

void MainWindow::LogoutButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
#ifdef DEBUG
    qDebug() << "Logout." << endl;
#endif
    Session::Logout();
    Render();
}

void MainWindow::SearchUserButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString suser = ui -> SearchUserLineEdit -> text();
#ifdef DEBUG
    qDebug() << "Search User" + suser + "." << endl;
#endif
    if (!suser.isEmpty() && !Session::IsExistUser(suser))
        QMessageBox::warning(this, "Error", "No such User.");
    else
    {
        Session::SetSearchUser(suser);
        GenerateUserProfileGroupBox();
    }
}

void MainWindow::ProblemsSearchButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString field = ui -> ProblemsSearchComboBox -> currentText();
    QString input = ui -> ProblemsSearchLineEdit -> text();
    SearchSession.SetProbSession(field, input);
    GenerateProblemTableView();
}

void MainWindow::StatusSearchButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString field = ui -> StatusSearchComboBox -> currentText();
    QString input = ui -> StatusSearchLineEdit -> text();
    SearchSession.SetStatusSession(field, input);
    GenerateStatusTableView();
}

void MainWindow::AdminSearchUserButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString suser = ui -> AdminSearchUserLineEdit -> text();
#ifdef DEBUG
    qDebug() << "Admin Search User" + suser + "." << endl;
#endif
    if (!suser.isEmpty() && !Session::IsExistUser(suser))
        QMessageBox::warning(this, "Error", "No such User.");
    else
    {
        Admin.SetAdminUser(suser);
        GenerateUserEditGroupBox();
    }
}

void MainWindow::OrzButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString suser = Session::GetSearchUser();
    if (suser.isEmpty() || !Session::IsExistUser(suser))
        QMessageBox::warning(this, "Error", "Please Search one User First.");
    else Orz(suser);
}

void MainWindow::EditProfileSubmitButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString user = Session::GetCurrentUser();
    QString instr = "SELECT HashedPassword FROM Users WHERE Id = '" + user + "';";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    QString OldPWD = ui -> EditProfileOldPWDLineEdit -> text();
    QString NewPWD = ui -> EditProfileNewPWDLineEdit -> text();
    QString Confirm = ui -> EditProfileConfirmLineEdit -> text();
    bool all_ok = true;
    if (!OldPWD.isEmpty() || !NewPWD.isEmpty() || !Confirm.isEmpty())
    {
        all_ok = false;
        if (OldPWD.isEmpty())
            QMessageBox::warning(this, "Error", "Please Input Old PWD.");
        else if (Session::Hash(OldPWD) == rec[0][0])
        {
            if (NewPWD.isEmpty())
                QMessageBox::warning(this, "Error", "Please Input New PWD.");
            else if (NewPWD != Confirm)
                QMessageBox::warning(this, "Error", "Input New PWD and Confirm are not the same.");
            else if (NewPWD.size() > Session::MAX_LEN)
                QMessageBox::warning(this, "Error", "Input New PWD is too Long(Exceed " + Session::MAX_LEN_STR + ").");
            else
            {
                QString *logs = new QString;
                bool res = Session::Update(user, "HashedPassword", "'" + Session::Hash(NewPWD) + "'", false, logs);
                if (res == false)
                    QMessageBox::warning(this, "Error", *logs);
                else all_ok = true;
            }
        }
        else QMessageBox::warning(this, "Error", "Wrong Old PWD.");
    }
    QString Nick = ui -> EditProfileNickLineEdit -> text();
    if (Nick.size() > Session::MAX_LEN)
    {
        all_ok = false;
        QMessageBox::warning(this, "Error", "Input Nick is too Long(Exceed " + Session::MAX_LEN_STR + ").");
    }
    else Session::Update(user, "Nick", "'" + Nick + "'", false);
    QString Motto = ui -> EditProfileMottoTextEdit -> toPlainText();
    if (Motto.size() > 50)
    {
        all_ok = false;
        QMessageBox::warning(this, "Error", "Input Motto is too Long(Exceed 50).");
    }
    else Session::Update(user, "Motto", "'" + Motto + "'", false);
    QString Gender = ui -> EditProfileGenderComboBox -> currentText();
    Session::Update(user, "Gender", "'" + Gender + "'", false);
    if (all_ok == true)
        QMessageBox::information(this, "Information", "Edit Profile Success.");
    Render();
    GenerateUserProfileGroupBox();
}

void MainWindow::EditUserSubmitButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString user = Admin.GetAdminUser();
    if (user.isEmpty()) InitUserEditGroupBox();
    else if (!Session::IsExistUser(user))
        QMessageBox::warning(this, "Error", "No Such User.");
    else
    {
        bool all_ok = true;
        QString NewPWD = ui -> EditUserNewPWDLineEdit -> text();
        QString Confirm = ui -> EditUserConfirmLineEdit -> text();
        if (!NewPWD.isEmpty())
        {
            all_ok = false;
            if (NewPWD != Confirm)
                QMessageBox::warning(this, "Error", "Input New PWD and Confirm are not the same.");
            else if (NewPWD.size() > Session::MAX_LEN)
                QMessageBox::warning(this, "Error", "Input New PWD is too Long(Exceed " + Session::MAX_LEN_STR + ").");
            else
            {
                QString *logs = new QString;
                bool res = Session::Update(user, "HashedPassword", "'" + Session::Hash(NewPWD) + "'", false, logs);
                if (res == false)
                    QMessageBox::warning(this, "Error", *logs);
                else all_ok = true;
            }
        }
        QString Nick = ui -> EditUserNickLineEdit -> text();
        if (Nick.size() > Session::MAX_LEN)
        {
            all_ok = false;
            QMessageBox::warning(this, "Error", "Input Nick is too Long(Exceed " + Session::MAX_LEN_STR + ").");
        }
        else Session::Update(user, "Nick", "'" + Nick + "'", false);
        QString Motto = ui -> EditUserMottoTextEdit -> toPlainText();
        if (Motto.size() > 50)
        {
            all_ok = false;
            QMessageBox::warning(this, "Error", "Input Motto is too Long(Exceed 50).");
        }
        else Session::Update(user, "Motto", "'" + Motto + "'", false);
        QString Gender = ui -> EditUserGenderComboBox -> currentText();
        Session::Update(user, "Gender", "'" + Gender + "'", false);
        if (all_ok == true)
            QMessageBox::information(this, "Information", "Admin Edit User Success.");
        Render();
        GenerateUserProfileGroupBox();
    }
}

void MainWindow::EditProblemSubmitButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    QString field = ui -> EditProblemComboBox -> currentText();
    QString input = ui -> EditProblemLineEdit -> text();
#ifdef DEBUG
    qDebug() << "Search Problem by Field " << field << " With '" << input << "'" << endl;
#endif
    Admin.SetAdminField(field);
    Admin.SetAdminInput(input);
    GenerateProblemEditGroupBox();
}

void MainWindow::RankListTabelClicked(const QModelIndex &index)
{
    if(!index.isValid()) return;
    if (!Session::AvoidQuickClick(this)) return ;
    int row = index.row();
    int col = index.column();
    if (col != 6) return ;
    if (RankListModel -> data(index).toString().isEmpty()) return ;
    QModelIndex tmp = RankListModel -> index(row, 0);
    QString user = RankListModel -> data(tmp).toString();
    Orz(user);
}

void MainWindow::ProblemsTabelClicked(const QModelIndex &index)
{
    if(!index.isValid()) return;
    if (!Session::AvoidQuickClick(this)) return ;
    int col = index.column();
    if (col != 5) return ;
    int row = index.row();
    QModelIndex tmp = ProblemsModel -> index(row, 0);
    int pid = ProblemsModel -> data(tmp).toString().toInt();
    problems -> SetCurrentProblemAndRender(pid);
}

void MainWindow::StatusTabelClicked(const QModelIndex &index)
{
    if (!index.isValid()) return ;
    if (!Session::AvoidQuickClick(this)) return ;
    int row = index.row();
    int col = index.column();
    if (col == 1)
    {
        int pid = StatusModel -> data(index).toString().toInt();
        problems -> SetCurrentProblemAndRender(pid);
    }
    else if (col == 6)
    {
        if (StatusModel -> data(index).toString().isEmpty()) return ;
        QModelIndex tmp = StatusModel -> index(row, 0);
        QString sid_str = StatusModel -> data(tmp).toString();
        QString instr = "SELECT SubmitAnswer FROM Status WHERE Id = " + sid_str + ";";
        DataBase::Record rec = DataBase::SelectInstr(instr);
        QMessageBox::information(this, " ", rec[0][0]);
    }
}

void MainWindow::EditProblemTabelClicked(const QModelIndex &index)
{
    if(!index.isValid()) return;
    if (!Session::AvoidQuickClick(this)) return ;
    int col = index.column();
    int row = index.row();
    QModelIndex tmp = EditProblemModel -> index(row, 0);
    QString id_str = EditProblemModel -> data(tmp).toString();
    if (col == 3)
        EditOrAddProblem(id_str.toInt());
    else if (col == 4)
    {
        tmp = EditProblemModel -> index(row, 1);
        QString Name = EditProblemModel -> data(tmp).toString();
        QString Action = EditProblemModel -> data(index).toString();
        int ret = QMessageBox::warning(this, "Confirm", "Are You Sure to " + Action + " Problem " + id_str + " - " + Name + "?", QMessageBox::Yes | QMessageBox::No);
        if (ret == QMessageBox::Yes)
        {
            Action = (Action == "Hide" ? "Hiding" : "Showing");
            QString instr = "Update Problems SET Hidden = 1 - Hidden WHERE Id = " + id_str + ";";
            bool res = DataBase::DeleteInstr(instr);
            if (res == true)
            {
                QMessageBox::information(this, "Information", "Succeeded in " + Action + " Problem " + id_str + " - " + Name);
                Render();
            }
            else QMessageBox::information(this, "Error", "Failed in " + Action + " Problem " + id_str + " - " + Name);
        }
    }
}

void MainWindow::AddProblemButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    EditOrAddProblem();
}

MainWindow::~MainWindow()
{
    delete ui;
}
