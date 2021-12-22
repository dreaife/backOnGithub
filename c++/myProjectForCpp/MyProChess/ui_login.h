/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(470, 372);
        loginGame = new QPushButton(Login);
        loginGame->setObjectName(QString::fromUtf8("loginGame"));
        loginGame->setGeometry(QRect(60, 260, 91, 31));
        NewMemb = new QPushButton(Login);
        NewMemb->setObjectName(QString::fromUtf8("NewMemb"));
        NewMemb->setGeometry(QRect(190, 260, 101, 31));
        password = new QLineEdit(Login);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(200, 180, 171, 31));
        password->setEchoMode(QLineEdit::Password);
        password->setDragEnabled(false);
        password->setReadOnly(false);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 180, 51, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_2->setFont(font);
        username = new QLineEdit(Login);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(200, 120, 171, 31));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 120, 91, 31));
        label->setFont(font);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 50, 289, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font1.setPointSize(29);
        font1.setBold(true);
        font1.setItalic(false);
        label_3->setFont(font1);
        label_3->setCursor(QCursor(Qt::ArrowCursor));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAutoFillBackground(false);
        Quit = new QPushButton(Login);
        Quit->setObjectName(QString::fromUtf8("Quit"));
        Quit->setGeometry(QRect(330, 260, 101, 31));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        loginGame->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        NewMemb->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("Login", "    \344\272\224\345\255\220\346\243\213", nullptr));
        Quit->setText(QCoreApplication::translate("Login", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
