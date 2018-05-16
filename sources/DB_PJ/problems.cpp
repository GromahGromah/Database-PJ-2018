#include "problems.h"
#include "ui_problems.h"
#include "db.h"
#include "session.h"
#include <QMessageBox>

Problems::Problems(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Problems)
{
    ui->setupUi(this);

    // Set Size
    this -> setMinimumSize(800,600);
    this -> setMaximumSize(800,600);

    // Initialize
    CurrentProbId = -1;
    ui -> ProblemNameLabel -> setFont(QFont("Song", 36, QFont::Bold));
    ui -> ProblemNameLabel -> setAlignment(Qt::AlignCenter);
    ui -> ProblemDescriptionTextEdit -> setReadOnly(true);
    ui -> ProblemDescriptionTextEdit -> setFont(QFont("Song", 16, QFont::Bold));
    ui -> ProblemSolveTextEdit -> setFont(QFont("Song", 16, QFont::Bold));
    QObject::connect(ui -> ProblemSolveSubmitButton, SIGNAL(clicked(bool)), this, SLOT(ProblemSolveSubmitButtonPressed()));
}

void Problems::SetCurrentProblemAndRender(int ProbId)
{
    QString Id_str;
    Id_str.setNum(ProbId);
    QString instr = "SELECT Hidden FROM Problems WHERE Id = " + Id_str + ";";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    if (rec.empty())
    {
        QMessageBox::warning(this, "Error", "This Problem does not Exist.");
        return ;
    }
    else if (rec[0][0].toInt() == 1 && !Session::IsAdmin())
    {
        QMessageBox::warning(this, "Error", "This Problem was Hidden by Admin.");
        return ;
    }
    CurrentProbId = ProbId;
    Render();
}

QString Problems::SearchProblemsInstruction(QString paras, QString pid_str, QString name, QString source, QString suffix)
{
    QString instr = "SELECT " + paras + " FROM Problems";
    bool first = 0;
    if (!pid_str.isEmpty())
        instr = instr + " WHERE Id = " + pid_str;
    else
    {
        if (!name.isEmpty())
        {
            instr = instr + " WHERE Name = '" + name + "'";
            first = 1;
        }
        if (!source.isEmpty())
        {
            instr = instr + (first ? " AND" : " WHERE") + " Source = '" + source + "'";
            first = 1;
        }
    }
    if (!Session::IsAdmin())
        instr = instr + (first ? " AND" : " WHERE") + " Hidden = 0";
    instr = instr + " " + suffix + ";";
    return instr;
}

QString Problems::SearchStatusInstruction(QString paras, QString runid_str, QString pid_str, QString user, QString result, QString suffix)
{
    QString instr = "SELECT " + paras + " FROM Status";
    bool first = 0;
    if (!runid_str.isEmpty())
        instr = instr + " WHERE Id = " + runid_str;
    else
    {
        if (!pid_str.isEmpty())
        {
            instr = instr + " WHERE ProblemId = " + pid_str;
            first = 1;
        }
        if (!user.isEmpty())
        {
            instr = instr + (first ? " AND" : " WHERE") + " UserId = '" + user + "'";
            first = 1;
        }
        if (!result.isEmpty())
            instr = instr + (first ? " AND" : " WHERE") + " Result = '" + result + "'";
    }
    instr = instr + " " + suffix + ";";
    return instr;
}

void Problems::Render()
{
    this -> show();
    // Set Title
    QString Id_str;
    Id_str.setNum(CurrentProbId);
    QString instr = "SELECT Name, Description FROM Problems WHERE Id = " + Id_str + ";";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    this -> setWindowTitle("Problem " + Id_str);
    ui -> ProblemNameLabel -> setText(rec[0][0]);
    ui -> ProblemDescriptionTextEdit -> setText(rec[0][1]);
    ui -> ProblemSolveTextEdit -> clear();
    emit Refresh(true);
}

void Problems::ProblemSolveSubmitButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    if (!Session::IsLogin())
    {
        QMessageBox::warning(this, "Error", "Please Login First.");
        return ;
    }
    QString user_ans = ui -> ProblemSolveTextEdit -> toPlainText();
    if (user_ans.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please Input Your Answer.");
        return ;
    }
    QString Id_str;
    Id_str.setNum(CurrentProbId);
    QString instr = "SELECT Answer FROM Problems WHERE Id = " + Id_str + ";";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    bool result = (user_ans == rec[0][0]);
    QString DateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd h:mm:ss");
    TryAddStatus(Session::GetCurrentUser(), CurrentProbId, user_ans, result, DateTime);
}

void Problems::TryAddStatus(QString user, int pid, QString user_ans, bool result, QString DateTime)
{
    QString Id_str;
    Id_str.setNum(pid);
    QString instr = "SELECT Id FROM Status WHERE UserId = '" + user + "'" +
            " AND ProblemId = " + Id_str +
            " AND SubmitAnswer = '" + user_ans + "';";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    if (rec.size())
    {
        QMessageBox::warning(this, "Oops", "You have Submitted the same answer in RunId " + rec[0][0]);
        return ;
    }
    AddStatus(user, pid, user_ans, result, DateTime);
    Render();
}

void Problems::AddStatus(QString user, int pid, QString user_ans, bool result, QString DateTime)
{
    QString Id_str;
    Id_str.setNum(pid);
    QString instr;
    instr = instr + "INSERT INTO Status(Id, UserId, ProblemId, SubmitAnswer, Result, SubmitDate) VALUES (" +
            "NULL, " +
            "'" + user + "', " +
            Id_str + ", " +
            "'" + user_ans + "', " +
            "'" + (result ? "Correct" : "Wrong Answer") + "', " +
            "'" + DateTime + "'" +
            ");";
    bool res = DataBase::InsertInstr(instr);
    if (!res)
    {
        QMessageBox::warning(this, "Error", "Submit Failed");
        return ;
    }
    QMessageBox::information(this, "Result", result ? "Correct!" : "Wrong Answer.");
    instr = "SELECT Solved, Attempted FROM Users WHERE Id = '" + user + "';";
    DataBase::Record rec = DataBase::SelectInstr(instr);
    int _solved = rec[0][0].toInt() + (result == true), _attempted = rec[0][1].toInt() + 1;
    QString tmp;
    tmp.setNum(_solved);
    Session::Update(user, "Solved", tmp, true);
    tmp.setNum(_attempted);
    Session::Update(user, "Attempted", tmp, true);
}

Problems::~Problems()
{
    delete ui;
}
