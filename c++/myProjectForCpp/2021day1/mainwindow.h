#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QtWidgets>
#include<QMessageBox>
#include<QString>
#include<algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    int num;

    void DataBaseLoad();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_selectButton_clicked();

    void on_createButton_clicked();

    void on_exitButton_clicked();

    void on_updateButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    void initNum();
};
#endif // MAINWINDOW_H
