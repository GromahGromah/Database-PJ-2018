#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTime>
#include <QMainWindow>
#include <QStandardItem>
#include <QStandardItemModel>
#include "login.h"
#include "problems.h"
#include "editproblem.h"

class Administration
{
public:
    Administration() : user_(""), field_(""), input_("") {}
    void Clear() {user_ = field_ = input_ = "";}
    void SetAdminUser(QString user) {user_ = user;}
    void SetAdminField(QString field) {field_ = field;}
    void SetAdminInput(QString input) {input_ = input;}
    QString GetAdminUser() {return user_;}
    QString GetAdminField() {return field_;}
    QString GetAdminInput() {return input_;}

private:
    QString user_;
    QString field_;
    QString input_;
};

class SearchSessionClass
{
public:
    SearchSessionClass() : ProbField_(""), ProbInput_(""), StatusField_(""), StatusInput_("") {}
    void SetProbSession(QString field, QString input)
    {
        ProbField_ = field, ProbInput_ = input;
    }
    void SetStatusSession(QString field, QString input)
    {
        StatusField_ = field, StatusInput_ = input;
    }
    void Clear()
    {
        ProbField_ = ProbInput_ = StatusField_ = StatusInput_ = "";
    }
    QString GetProbField() {return ProbField_;}
    QString GetProbInput() {return ProbInput_;}
    QString GetStatusField() {return StatusField_;}
    QString GetStatusInput() {return StatusInput_;}
private:
    QString ProbField_, ProbInput_;
    QString StatusField_, StatusInput_;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Start();
    void Render();

private slots:
    void ReceiveRefresh(bool reset);
    void HostButtonPressed();
    void LoginButtonPressed();
    void LogoutButtonPressed();
    void SearchUserButtonPressed();
    void ProblemsSearchButtonPressed();
    void StatusSearchButtonPressed();
    void AdminSearchUserButtonPressed();
    void OrzButtonPressed();
    void EditProfileSubmitButtonPressed();
    void EditUserSubmitButtonPressed();
    void EditProblemSubmitButtonPressed();
    void RankListTabelClicked(const QModelIndex &index);
    void ProblemsTabelClicked(const QModelIndex &index);
    void StatusTabelClicked(const QModelIndex &index);
    void EditProblemTabelClicked(const QModelIndex &index);
    void AddProblemButtonPressed();

private:
    void AdminRender();
    void Add(QStandardItemModel *model, int row, int col, QString s);
    void Orz(QString user);
    void GenerateLoginGroupBoxes();
    void GenerateUserTableView();
    void GenerateProblemTableView();
    void GenerateStatusTableView();
    void GenerateConfigHostGroupBox();
    void GenerateUserProfileGroupBox();
    void GenerateUserEditGroupBox();
    void GenerateProblemEditGroupBox();
    void InitUserEditGroupBox();
    void EditProfileInit();
    void EditOrAddProblem(int pid = 0);
    Ui::MainWindow *ui;
    Login *login;
    Problems *problems;
    EditProblem *editProblem;
    QStandardItemModel *MainTableModel;
    QStandardItemModel *RankListModel;
    QStandardItemModel *ProblemsModel;
    QStandardItemModel *StatusModel;
    QStandardItemModel *EditProblemModel;
    Administration Admin;
    SearchSessionClass SearchSession;
};

#endif // MAINWINDOW_H
