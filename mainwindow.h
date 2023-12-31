#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registerform.h"
#include "recupertionform.h"
#include "home.h"

#include <QtSql>
#include <QSqlDatabase>

#include <QMessageBox>

#include <chrono>
#include <thread>
#include <unistd.h>
#include <iostream>

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
    void on_pushButton_3_clicked();
    void on_lineEdit_3_textChanged();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;

    QSqlDatabase database;

    RegisterForm *registerForm;
    RecupertionForm *recuperationForm;
    Home *home;

};
#endif // MAINWINDOW_H
