/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *mutateButton;
    QDateEdit *WorkDate;
    QLabel *workLabel;
    QPushButton *reportButton;
    QTimeEdit *startTime;
    QTimeEdit *endTime;
    QLabel *startLabel;
    QLabel *endLabel;
    QCheckBox *pauseBox;
    QTimeEdit *pauseTime;
    QLabel *label;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        mutateButton = new QPushButton(Widget);
        mutateButton->setObjectName(QString::fromUtf8("mutateButton"));
        mutateButton->setGeometry(QRect(310, 520, 141, 31));
        WorkDate = new QDateEdit(Widget);
        WorkDate->setObjectName(QString::fromUtf8("WorkDate"));
        WorkDate->setGeometry(QRect(340, 50, 110, 26));
        WorkDate->setMaximumTime(QTime(19, 59, 59));
        WorkDate->setDate(QDate(2000, 1, 1));
        workLabel = new QLabel(Widget);
        workLabel->setObjectName(QString::fromUtf8("workLabel"));
        workLabel->setGeometry(QRect(350, 20, 81, 16));
        reportButton = new QPushButton(Widget);
        reportButton->setObjectName(QString::fromUtf8("reportButton"));
        reportButton->setGeometry(QRect(550, 520, 191, 31));
        startTime = new QTimeEdit(Widget);
        startTime->setObjectName(QString::fromUtf8("startTime"));
        startTime->setGeometry(QRect(150, 150, 118, 26));
        endTime = new QTimeEdit(Widget);
        endTime->setObjectName(QString::fromUtf8("endTime"));
        endTime->setGeometry(QRect(330, 150, 118, 26));
        startLabel = new QLabel(Widget);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));
        startLabel->setGeometry(QRect(180, 130, 62, 17));
        endLabel = new QLabel(Widget);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));
        endLabel->setGeometry(QRect(360, 130, 62, 17));
        pauseBox = new QCheckBox(Widget);
        pauseBox->setObjectName(QString::fromUtf8("pauseBox"));
        pauseBox->setGeometry(QRect(530, 130, 61, 21));
        pauseTime = new QTimeEdit(Widget);
        pauseTime->setObjectName(QString::fromUtf8("pauseTime"));
        pauseTime->setGeometry(QRect(510, 150, 118, 26));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 230, 211, 31));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 520, 121, 31));
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(170, 270, 431, 121));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "UrenRegistrator", nullptr));
        mutateButton->setText(QApplication::translate("Widget", "Uren doorvoeren", nullptr));
        workLabel->setText(QApplication::translate("Widget", "Werkdatum", nullptr));
        reportButton->setText(QApplication::translate("Widget", "Maandrapport genereren", nullptr));
        startLabel->setText(QApplication::translate("Widget", "Starttijd", nullptr));
        endLabel->setText(QApplication::translate("Widget", "Eindtijd", nullptr));
        pauseBox->setText(QApplication::translate("Widget", "Pauze", nullptr));
        label->setText(QApplication::translate("Widget", "Opmerkingen/Werkzaamheden", nullptr));
        pushButton->setText(QApplication::translate("Widget", "Nieuwe maand", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
