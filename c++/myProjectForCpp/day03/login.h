#ifndef LOGIN_H
#define LOGIN_H

#include "mainwindow.h"
#include <QString>
#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:

    MainWindow* m;

    explicit Login(QWidget *parent = 0);
    ~Login();

signals:
    void success(QString* username);

private slots:
    void on_exitLogin_clicked();

    void on_LoginLib_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
