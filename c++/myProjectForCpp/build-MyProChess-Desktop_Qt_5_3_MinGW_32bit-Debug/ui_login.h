/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *loginGame;
    QPushButton *NewMemb;
    QLineEdit *password;
    QLabel *label_2;
    QLineEdit *username;
    QLabel *label;
    QLabel *label_3;
    QPushButton *Quit;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(470, 372);
        loginGame = new QPushButton(Login);
        loginGame->setObjectName(QStringLiteral("loginGame"));
        loginGame->setGeometry(QRect(60, 260, 91, 31));
        NewMemb = new QPushButton(Login);
        NewMemb->setObjectName(QStringLiteral("NewMemb"));
        NewMemb->setGeometry(QRect(190, 260, 101, 31));
        password = new QLineEdit(Login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(200, 180, 171, 31));
        password->setEchoMode(QLineEdit::Password);
        password->setDragEnabled(false);
        password->setReadOnly(false);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 180, 51, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        username = new QLineEdit(Login);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(200, 120, 171, 31));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 120, 91, 31));
        label->setFont(font);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 50, 289, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font1.setPointSize(29);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setCursor(QCursor(Qt::ArrowCursor));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAutoFillBackground(false);
        Quit = new QPushButton(Login);
        Quit->setObjectName(QStringLiteral("Quit"));
        Quit->setGeometry(QRect(330, 260, 101, 31));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0));
        loginGame->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        NewMemb->setText(QApplication::translate("Login", "\346\263\250\345\206\214", 0));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201", 0));
        label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", 0));
        label_3->setText(QApplication::translate("Login", "    \344\272\224\345\255\220\346\243\213", 0));
        Quit->setText(QApplication::translate("Login", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
