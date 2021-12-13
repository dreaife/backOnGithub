#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include<QTextEdit>
#include<QString>
#include<QToolBar>
#include<QDebug>
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    QMenuBar *menubar;
    QToolBar* toolbar;
    QMenu *file,*edit,*form,*view,*help;
    QAction *open,*save,*saveOther;
    QTextEdit *editArea;

    ~MainWindow();

public slots:
    void openFileAction();
    void saveFileAction();
    void saveOtherFileAction();

private:
    Ui::MainWindow *ui;
    QString path;
};
#endif // MAINWINDOW_H
