#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QDate>

//QDateEdit *WorkDate;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    on_WorkDate_setDefaultDate();
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
}



void Widget::on_WorkDate_dateChanged(const QDate &date)
{

}


void Widget::on_WorkDate_setDefaultDate()
{
   QDate actualDate = QDate::currentDate();
    ui->WorkDate->setDate(actualDate);
}

