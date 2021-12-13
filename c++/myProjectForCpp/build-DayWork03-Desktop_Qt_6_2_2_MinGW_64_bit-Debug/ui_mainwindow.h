/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(290, 0, 511, 331));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\261\225\345\274\200 </p>\n"
"<p style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://www.bilibili.com/\"><span style=\" font-family:'Courier New'; font-size:x-large; font-weight:700; text-decoration: underline; color:#0000ff;\">bilibili</span></a><span style=\" font-family:'Courier New'; font-size:x-large; font-weight:700;\">   </span><a href=\"https://bbs.9shenmi.com/\"><span style=\" font-family:'Courier New'; font-size:x-large; font-weig"
                        "ht:700; text-decoration: underline; color:#0000ff;\">kfol</span></a><span style=\" font-family:'Courier New'; font-size:x-large; font-weight:700;\">   </span><a href=\"https://github.com/\"><span style=\" font-family:'Courier New'; font-size:x-large; font-weight:700; text-decoration: underline; color:#0000ff;\">gitHub</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://www.acwing.com/\"><span style=\" font-family:'Courier New'; font-size:x-large; font-weight:700; text-decoration: underline; color:#0000ff;\">acWing</span></a><span style=\" font-family:'Courier New'; font-size:x-large; font-weight:700;\">   </span><a href=\"https://bangumi.tv/\"><span style=\" font-family:'Courier New'; font-size:x-large; font-weight:700; text-decoration: underline; color:#0000ff;\">bangumi</span></a><span style=\" font-family:'Courier New'; font-size:x-large; font-weight:700;\">   </span><a href=\"https://galge.fun/\"><spa"
                        "n style=\" font-family:'Courier New'; font-size:x-large; font-weight:700; text-decoration: underline; color:#0000ff;\">2DFan</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
