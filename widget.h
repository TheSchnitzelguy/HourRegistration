#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void debugger();

private slots:
    void on_SubmitButton_clicked(bool checked);
    QDate on_WorkDate_dateChanged();
    void setDefaultWorkDate();



    void on_reportButton_clicked(bool checked);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
