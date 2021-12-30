/********************************************************************************
** Form generated from reading UI file 'chessbored.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSBORED_H
#define UI_CHESSBORED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chessBored
{
public:
    QLabel *timeTack;
    QLabel *label;

    void setupUi(QWidget *chessBored)
    {
        if (chessBored->objectName().isEmpty())
            chessBored->setObjectName(QString::fromUtf8("chessBored"));
        chessBored->resize(861, 561);
        timeTack = new QLabel(chessBored);
        timeTack->setObjectName(QString::fromUtf8("timeTack"));
        timeTack->setGeometry(QRect(700, 250, 91, 51));
        QFont font;
        font.setPointSize(12);
        timeTack->setFont(font);
        label = new QLabel(chessBored);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(680, 200, 101, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font1.setPointSize(15);
        label->setFont(font1);

        retranslateUi(chessBored);

        QMetaObject::connectSlotsByName(chessBored);
    } // setupUi

    void retranslateUi(QWidget *chessBored)
    {
        chessBored->setWindowTitle(QCoreApplication::translate("chessBored", "Form", nullptr));
        timeTack->setText(QCoreApplication::translate("chessBored", " \345\200\222\350\256\241\346\227\266", nullptr));
        label->setText(QCoreApplication::translate("chessBored", "\345\200\222\350\256\241\346\227\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chessBored: public Ui_chessBored {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSBORED_H
