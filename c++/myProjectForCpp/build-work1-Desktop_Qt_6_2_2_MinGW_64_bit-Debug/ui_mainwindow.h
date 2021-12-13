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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *logButton;
    QPushButton *exitButton;
    QLabel *username;
    QLineEdit *usernameEdit;
    QLabel *password;
    QLineEdit *passwordEdit;
    QPushButton *cancelButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(559, 382);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        logButton = new QPushButton(centralwidget);
        logButton->setObjectName(QString::fromUtf8("logButton"));
        logButton->setGeometry(QRect(110, 220, 75, 24));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(350, 220, 75, 24));
        username = new QLabel(centralwidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(110, 70, 71, 21));
        usernameEdit = new QLineEdit(centralwidget);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        usernameEdit->setGeometry(QRect(230, 70, 113, 21));
        password = new QLabel(centralwidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(110, 130, 71, 16));
        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(230, 130, 113, 21));
        passwordEdit->setContextMenuPolicy(Qt::PreventContextMenu);
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(230, 220, 75, 24));
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
        logButton->setText(QCoreApplication::translate("MainWindow", "login", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        username->setText(QCoreApplication::translate("MainWindow", "username", nullptr));
        password->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        passwordEdit->setText(QString());
        cancelButton->setText(QCoreApplication::translate("MainWindow", "cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
