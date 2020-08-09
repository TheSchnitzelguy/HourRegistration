#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
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
