#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLabel>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QLabel *text;
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    bool event(QEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
