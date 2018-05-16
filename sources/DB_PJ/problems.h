#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <QMainWindow>

namespace Ui {
class Problems;
}

class Problems : public QMainWindow
{
    Q_OBJECT

public:
    explicit Problems(QWidget *parent = 0);
    void SetCurrentProblemAndRender(int ProbId);
    static QString SearchProblemsInstruction(QString paras, QString pid_str, QString name, QString source, QString suffix);
    static QString SearchStatusInstruction(QString paras, QString runid_str, QString pid_str, QString user, QString result, QString suffix);
    ~Problems();

signals:
    void Refresh(bool reest);

private slots:
    void ProblemSolveSubmitButtonPressed();

private:
    void Render();
    void TryAddStatus(QString user, int pid, QString user_ans, bool result, QString DateTime);
    void AddStatus(QString user, int pid, QString user_ans, bool result, QString DateTime);
    Ui::Problems *ui;
    int CurrentProbId;
};

#endif // PROBLEMS_H
