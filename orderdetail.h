#ifndef ORDERDETAIL_H
#define ORDERDETAIL_H

#include <QWidget>
#include <QString>

#include <QMessageBox>
namespace Ui {
class orderDetail;
}

class orderDetail : public QWidget
{
    Q_OBJECT

public:
    explicit orderDetail(QWidget *parent = nullptr);
    QString getNumberOrder(){
      return numberOrder ;
    }
    void setNumberOrder(QString _numberOrder){
        numberOrder=_numberOrder;
    }

    ~orderDetail();
public slots:
    void receiveString(const QString&);
private:
    Ui::orderDetail *ui;
    QString numberOrder;
    QMessageBox msgBox;
     orderDetail* _orderDetail;
};

#endif // ORDERDETAIL_H
