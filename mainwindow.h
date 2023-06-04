#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <form.h>

#include <QMessageBox>
#include <QStackedWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    QStackedWidget *stackedWidget;
Form *thirdWindow;
    Ui::MainWindow *ui;

    QMessageBox msgBox;
};
#endif // MAINWINDOW_H
