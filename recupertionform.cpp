#include "recupertionform.h"
#include "ui_recupertionform.h"
#include "mainwindow.h"
// MY DB :


const int DB_SIZE = 100;
extern int nextTuple;
extern QString fName[DB_SIZE];
extern QString Email[DB_SIZE];
extern QString Uname[DB_SIZE];
extern QString Pass[DB_SIZE];




//

RecupertionForm::RecupertionForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecupertionForm)
{
    ui->setupUi(this);
}

RecupertionForm::~RecupertionForm()
{
    delete ui;
}

void RecupertionForm::on_pushButton_2_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void RecupertionForm::on_pushButton_3_clicked()
{
    ui->textEdit->setStyleSheet("color: #dd4a4a");
    bool exist = false;
    for(int i=0 ; i<nextTuple ; i++)
    {
        if(ui->lineEdit_2->text() == Email[i])
        {
            exist = true;
            ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
            ui->textEdit->setStyleSheet("color: #41af5d;");
            ui->textEdit->setText("Email exist!\nUsername : "+ Uname[i] +"\nPassword : "+ Pass[i]);
        }
    }
    if(!exist){
        ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
        ui->textEdit->setText("Warning : This Email doesn't exist.");
    }
}

