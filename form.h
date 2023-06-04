#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QStackedWidget>
#include "order.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButtonOrder_clicked();

private:
    Ui::Form *ui;
    order *orderForm;

};

#endif // FORM_H
