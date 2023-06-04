#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "form.h"
#include "ui_form.h"
#include <QStackedWidget>
#include <QSqlError>
#include "dbconnect.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
thirdWindow = new Form();
    ui->setupUi(this);
    DBConnect& dbConnect = DBConnect::instance();

}

MainWindow::~MainWindow()
{


    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
bool check = true;
DBConnect& dbConnect = DBConnect::instance();
QSqlQuery query(dbConnect.db);
   if(!query.exec("SELECT  [surname],[password] FROM [VeronaKLD].[dbo].[User]")){
           qDebug()<<query.lastError().databaseText();
}

    while (query.next()) {
    QString surname = query.value(0).toString();
    QString password = query.value(1).toString();
    qDebug() << surname ;
    qDebug() << password ;
if(surname==ui->loginEdit->text()&&password==ui->passwordEdit->text()){
       check=false;
    }
    }
    if(check==true){
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Неверный логин или пароль!");
        msgBox.setIcon(QMessageBox::Information);

        msgBox.exec();
    }
    else{
        thirdWindow->show();  // Показываем второе окно
        this->close();    // Закрываем основное окно
       }
}
