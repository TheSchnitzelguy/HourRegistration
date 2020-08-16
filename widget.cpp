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


void Widget::on_SubmitButton_clicked(bool checked)
{
    qDebug() << "submit button pressed!";
    //QMessageBox::information(this, "Message", "Submit", QMessageBox::Ok);

    QMessageBox::StandardButton button;
    QMessageBox message;

    button = QMessageBox::question(this, "Urenregistratie", "Ingevoerde uren bij maand rekenen?", QMessageBox::Yes | QMessageBox::No);


    if(button == QMessageBox::Yes)
    {
        //push to database
        qDebug() << "Hours pushed to database";
        message.information(this, "Info", "Uren zijn succesvol doorgevoerd!");
    }
    else
    {
        qDebug() << "Hour mutation cancelled";
        message.warning(this, "Info", "Uren zijn niet doorgevoerd!");
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





void Widget::on_reportButton_clicked(bool checked)
{
   // QString selectedMonth = ui->WorkDate->date().toString("MM");
    int selectedMonth = ui->WorkDate->date().month();
    QString longMonth;

    QString  months[12] = {"januari", "februari", "maart", "april", "mei", "juni", "juli", "augustus", "september", "october", "november", "december"};
    for (int i = 0; i < 12; i++)
    {
       longMonth = months[selectedMonth]; //TODO: fix one month too far bug
    }




  QMessageBox::question(this, "Urenregistratie", QString("Wilt u een rapport van de maand %1 exporteren?").arg(longMonth), QMessageBox::Yes | QMessageBox::No);
  qDebug() << "selectedMonth: " << longMonth;
}
//QMessageBox::information(nullptr/*or parent*/, "Title",  String("This machine calculated all prime numbers under %1 %2 times in %3 seconds") .arg(MAX_PRIME).arg(NUM_OF_CORES).arg(run_time));
