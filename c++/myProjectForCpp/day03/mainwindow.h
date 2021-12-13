#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QDialog>
#include <QMessageBox>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QToolBar * tools;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void trigerTool(QAction* act);

    void showDiag();

    void getText();

    void Pwarn();

    void success(QString* username);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
