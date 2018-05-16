#include "db.h"
#include "session.h"
#include "problems.h"
#include "editproblem.h"
#include "ui_editproblem.h"
#include <QMessageBox>

EditProblem::EditProblem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditProblem)
{
    ui->setupUi(this);
    ui -> EditOrAddProblemLabel -> setAlignment(Qt::AlignCenter);
    ui -> EditOrAddProblemLabel -> setFont(QFont("Song", 24, QFont::Bold));
    ui -> NameLineEdit -> setFont(QFont("Song", 16, QFont::Bold));
    ui -> SourceLineEdit -> setFont(QFont("Song", 16, QFont::Bold));
    ui -> DescriptionTextEdit -> setFont(QFont("Song", 16, QFont::Bold));
    ui -> AnswerLineEdit -> setFont(QFont("Song", 16, QFont::Bold));

    // Set Size
    this -> setMinimumSize(800,600);
    this -> setMaximumSize(800,600);

    // Set Slots
    QObject::connect(ui -> SubmitButton, SIGNAL(clicked(bool)), this, SLOT(SubmitButtonPressed()));
}

void EditProblem::Handle(int pid)
{
    QString Description;
    if (pid == 0)
    {
        QString instr = "SELECT * FROM Problems";
        DataBase::Record rec = DataBase::SelectInstr(instr);
        pid = rec.size() + 1;
        QString id_str;
        id_str.setNum(pid);
        Description = "Adding Problem with Id " + id_str;
        ui -> NameLineEdit -> clear();
        ui -> SourceLineEdit -> clear();
        ui -> DescriptionTextEdit -> clear();
        ui -> AnswerLineEdit -> clear();
        action_ = Action::AddProblem;
    }
    else
    {
        QString id_str;
        id_str.setNum(pid);
        QString instr = "SELECT Name, Source, Description, Answer FROM Problems WHERE Id = " + id_str + ";";
        DataBase::Record rec = DataBase::SelectInstr(instr);
        if (rec.empty())
        {
            QMessageBox::warning(this, "Error", "Some Unexpected Error Happened, Please Contact Gromah.");
            return ;
        }
        Description = "Editing Problem " + id_str + " - " + rec[0][0];
        ui -> NameLineEdit -> setText(rec[0][0]);
        ui -> SourceLineEdit -> setText(rec[0][1]);
        ui -> DescriptionTextEdit -> setText(rec[0][2]);
        ui -> AnswerLineEdit -> setText(rec[0][3]);
        action_ = Action::EditProblem;
    }
    // Set Title
    this -> setWindowTitle(Description);
    ui -> EditOrAddProblemLabel -> setText(Description);
    // Store
    current_pid_ = pid;
    title_ = Description;
    // Prepared and Show Window
    this -> show();
}

void EditProblem::SubmitButtonPressed()
{
    if (!Session::AvoidQuickClick(this)) return ;
    if (!CheckLegal()) return;
    bool res = true;
    QString Name = ui -> NameLineEdit -> text();
    QString Source = ui -> SourceLineEdit -> text();
    QString Description = ui -> DescriptionTextEdit -> toPlainText();
    QString Answer = ui -> AnswerLineEdit -> text();
    if (action_ == Action::AddProblem)
    {
        QString instr = "INSERT INTO Problems(Id, Name, Description, Source, Answer, Hidden) VALUES (";
        instr = instr + "NULL, " +
                "'" + Name + "', " +
                "'" + Description + "', " +
                "'" + Source + "', " +
                "'" + Answer + "', " +
                "0" +
                ");";
        res = DataBase::InsertInstr(instr);
    }
    else
    {
        res &= Update(current_pid_, "Name", Name);
        res &= Update(current_pid_, "Source", Source);
        res &= Update(current_pid_, "Description", Description);
        res &= Update(current_pid_, "Answer", Answer);
    }
    if (res == true)
    {
        QMessageBox::information(this, "Information", "Succeeded in " + title_ + ".");
        emit Refresh(true);
        this -> close();
        Handle(current_pid_);
    }
    else QMessageBox::warning(this, "Error", "Failed in " + title_ + ".");
}

bool EditProblem::CheckLegal()
{
    QString Name = ui -> NameLineEdit -> text();
    if (Name.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please Input Name.");
        return false;
    }
    else if (Name.size() > Limit.find("Name") -> second)
    {
        QString l_str;
        l_str.setNum(Limit.find("Name") -> second);
        QMessageBox::warning(this, "Error", "Input Name is Too Long (Exceed " + l_str + ").");
        return false;
    }
    QString Source = ui -> SourceLineEdit -> text();
    if (Source.size() > Limit.find("Source") -> second)
    {
        QString l_str;
        l_str.setNum(Limit.find("Source") -> second);
        QMessageBox::warning(this, "Error", "Input Source is Too Long (Exceed " + l_str + ").");
        return false;
    }
    QString Description = ui -> DescriptionTextEdit -> toPlainText();
    if (Description.size() > Limit.find("Description") -> second)
    {
        QString l_str;
        l_str.setNum(Limit.find("Description") -> second);
        QMessageBox::warning(this, "Error", "Input Description is Too Long (Exceed " + l_str + ").");
        return false;
    }
    QString Answer = ui -> AnswerLineEdit -> text();
    if (Answer.size() > Limit.find("Answer") -> second)
    {
        QString l_str;
        l_str.setNum(Limit.find("Answer") -> second);
        QMessageBox::warning(this, "Error", "Input Answer is Too Long (Exceed " + l_str + ").");
        return false;
    }
    return true;
}

bool EditProblem::Update(int pid, QString srcField, QString dest, QString *logs)
{
    QString id_str;
    id_str.setNum(pid);
    QString instr = "UPDATE Problems SET " + srcField + " = '" + dest + "' WHERE Id = " + id_str + ";";
    bool res = DataBase::UpdateInstr(instr);
    if (logs != NULL)
    {
        if (res == true)
            *logs = "Update Succeeded.";
        else *logs = "Update Failed.";
    }
    return res;
}

EditProblem::~EditProblem()
{
    delete ui;
}
