#include "mainwindow.h"
#include "ui_mainwindow.h"
/// SIMPLE LOCAL BDD :
typedef struct personne{
    QString Username;
    QString Password;
    QString Email;
}Personne;
// instences :

Personne initialisation(QString name, QString pass, QString email){
    // personne 01
    Personne newP;
    newP.Username = name;
    newP.Password = pass;
    newP.Email = email;
    return newP;
}
Personne p1 = initialisation("rahimo","rah27","wadoudbirouk9@gmail.com");


/// MAIN PROGRAMME
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->hide();
    ui->menubar->hide();
    ui->toolButton->hide();
    ui->toolButton_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    if((ui->lineEdit_2->text()==p1.Username)&&(ui->lineEdit_3->text()==p1.Password))
    {
        ui->lineEdit->setStyleSheet("color: #41af5d;");
        ui->lineEdit->setText("Connected Succesfully");
        ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
        ui->lineEdit_3->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
    }
    else
    {
        ui->lineEdit->setText("Warning : Username or password doesn't work");
        if(ui->lineEdit_2->text()!=p1.Username)
        {
            ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
        }else ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
        if(ui->lineEdit_3->text()!=p1.Password)
        {
            ui->lineEdit_3->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
        }else ui->lineEdit_3->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
    }
}




void MainWindow::on_lineEdit_3_textChanged()
{
    ui->toolButton->show();
}




void MainWindow::on_toolButton_clicked()
{
    ui->lineEdit_3->setEchoMode(QLineEdit::Normal);
    ui->toolButton->hide();
    ui->toolButton_2->show();
}


void MainWindow::on_toolButton_2_clicked()
{
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    ui->toolButton->show();
    ui->toolButton_2->hide();

}


void MainWindow::on_pushButton_2_clicked()
{
    QWidget *register_wdg = new QWidget;
    register_wdg->show();

}

