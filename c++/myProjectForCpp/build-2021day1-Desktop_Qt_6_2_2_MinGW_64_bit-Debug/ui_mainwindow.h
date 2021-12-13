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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *showArea;
    QLabel *username;
    QLabel *password;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *createButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QPushButton *selectButton;
    QLabel *label;
    QLineEdit *scoreEdit;
    QPushButton *exitButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(492, 596);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        showArea = new QTextBrowser(centralwidget);
        showArea->setObjectName(QString::fromUtf8("showArea"));
        showArea->setGeometry(QRect(50, 300, 391, 251));
        username = new QLabel(centralwidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(50, 40, 69, 20));
        password = new QLabel(centralwidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(50, 100, 69, 20));
        usernameEdit = new QLineEdit(centralwidget);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setGeometry(QRect(190, 40, 191, 27));
        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(190, 100, 191, 27));
        createButton = new QPushButton(centralwidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(11, 210, 121, 29));
        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(170, 210, 141, 29));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(340, 210, 141, 29));
        selectButton = new QPushButton(centralwidget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setGeometry(QRect(80, 260, 141, 29));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 160, 69, 20));
        scoreEdit = new QLineEdit(centralwidget);
        scoreEdit->setObjectName(QString::fromUtf8("scoreEdit"));
        scoreEdit->setGeometry(QRect(190, 160, 191, 27));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(260, 260, 151, 29));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        username->setText(QCoreApplication::translate("MainWindow", "username", nullptr));
        password->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        createButton->setText(QCoreApplication::translate("MainWindow", "create account", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "update account", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "delete account", nullptr));
        selectButton->setText(QCoreApplication::translate("MainWindow", "search all", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "score", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
