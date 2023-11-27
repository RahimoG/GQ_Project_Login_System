#include "registerform.h"
#include "ui_registerform.h"
#include "mainwindow.h"
// MY DB :


const int DB_SIZE = 100;
extern int nextTuple;
extern QString fName[DB_SIZE];
extern QString Email[DB_SIZE];
extern QString Uname[DB_SIZE];
extern QString Pass[DB_SIZE];




//




bool eyeShowR = false;
RegisterForm::RegisterForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
    ui->toolButton_2->hide();
    ui->toolButton->hide();
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

void RegisterForm::on_pushButton_2_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void RegisterForm::on_pushButton_3_clicked()
{
    ui->lineEdit->setStyleSheet("color: #dd4a4a");
    bool done = true;
    if(ui->lineEdit_5->text() == ""){
        ui->lineEdit_5->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
        ui->lineEdit->setText("Warning : Email is requaried.");
        done = false;
    }else{
        ui->lineEdit_5->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
        for(int i=0; i<nextTuple;i++)
        {
            if (Email[i] == ui->lineEdit_5->text()){
                ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
                ui->lineEdit->setText("Warning : This Email is used before.");
                done = false;
            }
        }
    }
    if(ui->lineEdit_4->text() == ""){
        ui->lineEdit_4->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
        ui->lineEdit->setText("Warning : Full Name is requaried.");
        done = false;
    }else{
        ui->lineEdit_4->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
    }
    if(ui->lineEdit_3->text() == ""){
        ui->lineEdit_3->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
        ui->lineEdit->setText("Warning : Password is requaried.");
        done = false;
    }else{
        ui->lineEdit_3->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
    }
    if(ui->lineEdit_2->text() == ""){
        ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
        ui->lineEdit->setText("Warning : Username is requaried.");
        done = false;
    }else{
        ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
        for(int i=0; i<nextTuple;i++)
        {
            if (Uname[i] == ui->lineEdit_2->text()){
                ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
                ui->lineEdit->setText("Warning : This username is used before.");
                done = false;
            }
        }
    }
    if(done){
        ui->lineEdit->setStyleSheet("color: #41af5d;");
        ui->lineEdit->setText("Account created Succesfully.");
        if(nextTuple<DB_SIZE)
        {
            fName[nextTuple] = ui->lineEdit_4->text();
            Uname[nextTuple] = ui->lineEdit_2->text();
            Email[nextTuple] = ui->lineEdit_5->text();
            Pass[nextTuple] = ui->lineEdit_3->text();
            nextTuple++;
        }
    }
}


void RegisterForm::on_toolButton_2_clicked()
{
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    ui->toolButton->show();
    ui->toolButton_2->hide();
    eyeShowR = false;
}



void RegisterForm::on_toolButton_clicked()
{
    ui->lineEdit_3->setEchoMode(QLineEdit::Normal);
    ui->toolButton->hide();
    ui->toolButton_2->show();
    eyeShowR = true;
}


void RegisterForm::on_lineEdit_3_textChanged()
{
    if(!eyeShowR)
    {
        ui->toolButton->show();
        eyeShowR = false;
    }
    else {
        ui->toolButton_2->show();
        eyeShowR = true;
    }
}

