#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"
#include <QCoreApplication>
#include <QTime>
#include <ctime>
#include <QEventLoop>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initSence();
    Map map;
    void paintEvent(QPaintEvent *);
    void updatePosition();

    QTimer timer;
    void startGame();








private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
