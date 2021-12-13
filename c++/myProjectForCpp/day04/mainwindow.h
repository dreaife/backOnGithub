#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QPushButton>
#include <QTextEdit>
#include <QPainter>
#include <QPaintDevice>
#include <QPaintEngine>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPushButton* btn;

    QTextEdit* text;

    //bool event(QEvent *e);

    bool eventFilter(QObject *obj, QEvent *event);

    void paintEvent(QPaintEvent* );

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
