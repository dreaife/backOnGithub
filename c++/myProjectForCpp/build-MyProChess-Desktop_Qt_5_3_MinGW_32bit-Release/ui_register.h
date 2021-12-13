/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QLabel *lab1;
    QLabel *labe2;
    QLabel *lab3;
    QLineEdit *username;
    QLineEdit *password;
    QLineEdit *passwordConfine;
    QPushButton *regiserConfine;
    QPushButton *DisRegister;
    QLabel *label;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(474, 365);
        lab1 = new QLabel(Register);
        lab1->setObjectName(QStringLiteral("lab1"));
        lab1->setGeometry(QRect(90, 80, 81, 21));
        QFont font;
        font.setPointSize(12);
        lab1->setFont(font);
        labe2 = new QLabel(Register);
        labe2->setObjectName(QStringLiteral("labe2"));
        labe2->setGeometry(QRect(90, 130, 81, 21));
        labe2->setFont(font);
        lab3 = new QLabel(Register);
        lab3->setObjectName(QStringLiteral("lab3"));
        lab3->setGeometry(QRect(90, 180, 91, 21));
        lab3->setFont(font);
        username = new QLineEdit(Register);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(240, 80, 131, 21));
        password = new QLineEdit(Register);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(240, 130, 131, 21));
        passwordConfine = new QLineEdit(Register);
        passwordConfine->setObjectName(QStringLiteral("passwordConfine"));
        passwordConfine->setGeometry(QRect(240, 180, 131, 21));
        regiserConfine = new QPushButton(Register);
        regiserConfine->setObjectName(QStringLiteral("regiserConfine"));
        regiserConfine->setGeometry(QRect(90, 250, 93, 28));
        QFont font1;
        font1.setPointSize(10);
        regiserConfine->setFont(font1);
        DisRegister = new QPushButton(Register);
        DisRegister->setObjectName(QStringLiteral("DisRegister"));
        DisRegister->setGeometry(QRect(270, 250, 93, 28));
        DisRegister->setFont(font1);
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 20, 181, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font2.setPointSize(26);
        label->setFont(font2);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", 0));
        lab1->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", 0));
        labe2->setText(QApplication::translate("Register", "\345\257\206\347\240\201", 0));
        lab3->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        regiserConfine->setText(QApplication::translate("Register", "\346\263\250\345\206\214", 0));
        DisRegister->setText(QApplication::translate("Register", "\345\217\226\346\266\210\346\263\250\345\206\214", 0));
        label->setText(QApplication::translate("Register", "\346\263\250\345\206\214\350\264\246\346\210\267", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
