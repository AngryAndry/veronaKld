#include "order.h"
#include "dbconnect.h"
#include "ui_order.h"
#include <QStackedWidget>
#include <QSqlError>
#include <QPushButton>
order::order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::order)
{

    orderDetailForm  = new orderDetail();
    ui->setupUi(this);
connect(ui->tableOrders, SIGNAL(doubleClicked(QModelIndex)),this,SLOT(OnDoubleClicked(QModelIndex)));
connect(this,SIGNAL(stringSent(QString)),orderDetailForm,SLOT(receiveString(QString)));

}
void order::connectDB(){
    DBConnect& dbConnect = DBConnect::instance();
        QSqlQuery query(dbConnect.db);
        query.clear();

 if(!query.exec("SELECT  [number],[status],[model] FROM [VeronaKLD].[dbo].[Order]")){
         qDebug()<<query.lastError().databaseText();
}
 int i = 0;
 while (query.next()) {
     int rowCount = ui->tableOrders->rowCount();
     ui->tableOrders->insertRow(rowCount);
     ui->tableOrders->setItem(i, 2, new QTableWidgetItem(query.value(1).toString()));
     ui->tableOrders->setItem(i, 1, new QTableWidgetItem(query.value(2).toString()));
     ui->tableOrders->setItem(i, 0, new QTableWidgetItem(query.value(0).toString()));
     i++;

 }

 ui->tableOrders->setEditTriggers(QAbstractItemView::NoEditTriggers);


}
order::~order()
{
    delete ui;
}

void order::on_tableOrders_doubleClicked(const QModelIndex &index)
{
    setNumberOrder((index.model()->data(index.model()->index(index.row(),0)).toString()));
    //orderDetailForm->setNumberOrder(getNumberOrder());

    emit stringSent(getNumberOrder());
   orderDetailForm->show();
 //    orderDetailForm->show();  // Показываем окно заказов
   // orderDetailForm->connectDB();
   /*msgBox.setWindowTitle("Ошибка");
    msgBox.setText(getNumberOrder());
    msgBox.setIcon(QMessageBox::Information);

    msgBox.exec();*/
}
/*void order::sendString() {
    QString myString =getNumberOrder();
    emit stringSent(myString);
}*/
