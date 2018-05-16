#ifndef EDITPROBLEM_H
#define EDITPROBLEM_H

#include <QMainWindow>

enum class Action
{
    AddProblem,
    EditProblem
};

const std::map <std::string, int> Limit = {
    {"Name", 16},
    {"Source", 50},
    {"Description", 200},
    {"Answer", 50}
};

namespace Ui {
class EditProblem;
}

class EditProblem : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditProblem(QWidget *parent = 0);
    void Handle(int pid);
    ~EditProblem();

signals:
    void Refresh(bool reest);

private slots:
    void SubmitButtonPressed();

private:
    Ui::EditProblem *ui;
    QString title_;
    int current_pid_;
    Action action_;
    bool CheckLegal();
    bool Update(int pid, QString srcField, QString dest, QString *logs = NULL);
};

#endif // EDITPROBLEM_H
