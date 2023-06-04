#include "orderdetail.h"
#include "ui_orderdetail.h"

orderDetail::orderDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderDetail)
{
    ui->setupUi(this);





}
void orderDetail::receiveString(const QString& myString) {

    setNumberOrder(myString);
     ui->modelLB->setText(getNumberOrder());
    msgBox.setWindowTitle("Ошибка");
        msgBox.setText(myString);
        msgBox.setIcon(QMessageBox::Information);

        msgBox.exec();
}
orderDetail::~orderDetail()
{
    delete ui;
}
