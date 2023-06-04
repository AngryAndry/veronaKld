#include "form.h"
#include "ui_form.h"

#include <QPushButton>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    orderForm = new order();
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButtonOrder_clicked()
{
    orderForm->show();  // Показываем окно заказов
    orderForm->connectDB();
    this->close();    // Закрываем основное окно
}

