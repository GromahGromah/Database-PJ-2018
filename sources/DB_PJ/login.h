#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void TryLogin();
    void TryRegister();

signals:
    void Refresh(bool reest);

private:
    Ui::Login *ui;
    void Clear();
};

#endif // LOGIN_H
