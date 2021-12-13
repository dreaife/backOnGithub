#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("记事本");
    this->setWindowIcon( QIcon(":/SRC/FAVOICON.png"));
    menubar =menuBar();
    toolbar = new QToolBar(this);
    toolbar->setAllowedAreas(Qt::TopToolBarArea);
    toolbar->setMovable(false);
    addToolBar(toolbar);

    file = new QMenu("文件",this);edit = new QMenu("编辑",this);
    view = new QMenu("视图");form = new QMenu("格式");
    help = new QMenu("帮助");
    menubar->addMenu(file);
    menubar->addMenu(edit);
    menubar->addMenu(form);
    menubar->addMenu(view);
    menubar->addMenu(help);
    this->save = new QAction("保存");open = new QAction("打开");
    saveOther = new QAction("另存为");
    file->addAction(save);
    file->addAction(saveOther);
    file->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(saveOther);
    toolbar->addAction(open);
    editArea = new QTextEdit(this);
    this->setCentralWidget(editArea);

    connect(open,&QAction::triggered,this,&MainWindow::openFileAction);
    connect(save,&QAction::triggered,this,&MainWindow::saveFileAction);
    connect(saveOther,&QAction::triggered,this,&MainWindow::saveOtherFileAction);

}

void MainWindow::openFileAction(){
    path = QFileDialog::getOpenFileName(this,"选择文件","D:/codeS/backOnGithub/c++/myProjectForCpp/DayWork03","*.txt");
    qDebug()<<path;
    QFile file(path);
    if(path.isEmpty()) return qDebug()<<"文件未选择",void();
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QByteArray arry = file.readAll();
        this->editArea->clear();
        editArea->setText(QString(arry));
    } file.close();
}

void MainWindow::saveFileAction(){
    QFile file(path);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QString context = editArea->toPlainText();
        QTextStream stream(&file);
        stream.autoDetectUnicode();
        stream<<context;
        stream.flush();
        file.close();
    }
}

void MainWindow::saveOtherFileAction(){
    QString path = QFileDialog::getSaveFileName(this,"选择文件","D:/codeS/backOnGithub/c++/myProjectForCpp/DayWork03","*.txt");
    QFile file(path);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QString context = editArea->toPlainText();
        QTextStream stream(&file);
        stream.autoDetectUnicode();
        stream<<context;
        stream.flush();
        file.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

