/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *user;
    QLabel *mem1;
    QLabel *mem4;
    QLabel *mem2;
    QLabel *mem5;
    QLabel *mem3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(803, 604);
        user = new QLabel(Widget);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(40, 40, 201, 31));
        QFont font;
        font.setPointSize(12);
        user->setFont(font);
        mem1 = new QLabel(Widget);
        mem1->setObjectName(QStringLiteral("mem1"));
        mem1->setGeometry(QRect(320, 130, 171, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        mem1->setFont(font1);
        mem4 = new QLabel(Widget);
        mem4->setObjectName(QStringLiteral("mem4"));
        mem4->setGeometry(QRect(320, 320, 171, 31));
        mem4->setFont(font1);
        mem2 = new QLabel(Widget);
        mem2->setObjectName(QStringLiteral("mem2"));
        mem2->setGeometry(QRect(320, 200, 171, 21));
        mem2->setFont(font1);
        mem5 = new QLabel(Widget);
        mem5->setObjectName(QStringLiteral("mem5"));
        mem5->setGeometry(QRect(320, 380, 181, 21));
        mem5->setFont(font1);
        mem3 = new QLabel(Widget);
        mem3->setObjectName(QStringLiteral("mem3"));
        mem3->setGeometry(QRect(320, 260, 171, 21));
        mem3->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        user->setText(QApplication::translate("Widget", "TextLabel", 0));
        mem1->setText(QApplication::translate("Widget", "1.------------------", 0));
        mem4->setText(QApplication::translate("Widget", "4.------------------", 0));
        mem2->setText(QApplication::translate("Widget", "2.------------------", 0));
        mem5->setText(QApplication::translate("Widget", "5.-----------------", 0));
        mem3->setText(QApplication::translate("Widget", "3.------------------", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
