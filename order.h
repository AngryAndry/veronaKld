#ifndef ORDER_H
#define ORDER_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include "orderdetail.h"
namespace Ui {
class order;
}

class order : public QWidget
{
    Q_OBJECT

public:
    explicit order(QWidget *parent = nullptr);
      void connectDB();
      QString getNumberOrder(){
        return numberOrder ;
      }
      void setNumberOrder(QString _numberOrder){
          numberOrder=_numberOrder;
      }
    ~order();

private slots:
      void on_tableOrders_doubleClicked(const QModelIndex &index);
signals:
    void stringSent(const QString);
private:
    Ui::order *ui;
    QMessageBox msgBox;
orderDetail * orderDetailForm;
    QString numberOrder;

};

#endif // ORDER_H
