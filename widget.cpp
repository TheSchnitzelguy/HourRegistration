#include "widget.h"
#include "ui_widget.h"
#include "main.h"
#include <QDebug>
#include <QMessageBox>
#include <QDate>

//QDateEdit *WorkDate;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setDefaultWorkDate();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    qDebug() << "submit button pressed!";
    //QMessageBox::information(this, "Message", "Submit", QMessageBox::Ok);

    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, "Urenregistratie", "Ingevoerde uren bij maand rekenen?", QMessageBox::Yes | QMessageBox::No);


    if(button == QMessageBox::Yes)
    {
        qDebug() << "Hours pushed to database";
    }
    else
    {
        qDebug() << "Hour mutation cancelled";
    }

#ifdef DEBUG
    debugger();
#endif
}



QDate Widget::on_WorkDate_dateChanged()
{
    QDate enteredDate;
    enteredDate = ui->WorkDate->date();

    return  enteredDate;
}


void Widget::setDefaultWorkDate()
{
   QDate actualDate = QDate::currentDate();
   ui->WorkDate->setDate(actualDate);
}

void Widget::debugger()
{
    /*!
     * print the changed work date
    */
    QDate enteredDate = on_WorkDate_dateChanged();
    qDebug() << "Date changed!, new date: " << enteredDate;
}
