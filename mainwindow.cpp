#include "mainwindow.h"
#include "ui_mainwindow.h"

/// SIMPLE LOCAL BDD :
///
///

const int DB_SIZE = 100;
int nextTuple = 0;
QString fName[DB_SIZE];
QString Email[DB_SIZE];
QString Uname[DB_SIZE];
QString Pass[DB_SIZE];
int LogedInUserID;



///
///
///
//
/*
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
*/

/// MAIN PROGRAMME
///
bool eyeShow = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->hide();
    ui->menubar->hide();
    ui->toolButton->hide();
    ui->toolButton_2->hide();


    // First Tuple in the table :
    fName[nextTuple] = "BIROUK Mohamed Abderrahmane";
    Email[nextTuple] = "wadoudbirouk9@gmail.com";
    Uname[nextTuple] = "rahimo";
    Pass[nextTuple] = "rah27";
    nextTuple++;


    // chrono sleep setup
    /*
    using namespace std::this_thread; // sleep_for, sleep_until
    using std::chrono::duration; // nanoseconds, system_clock, seconds
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    /*
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
    */
    bool exist = false;
    ui->lineEdit->setStyleSheet("color: #dd4a4a");
    ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
    ui->lineEdit_3->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");

    for(int i=0; i<nextTuple; i++)
    {
        if(ui->lineEdit_2->text()==Uname[i])
        { // username exist
            exist = true;
            ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
            if(ui->lineEdit_3->text()!=Pass[i])
            {   // pass not false
                ui->lineEdit_3->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
                ui->lineEdit->setText("Warning : The password of \""+ Uname[i] +"\" is wrong.");
            }else{ //password true
                // QMessageBox::information(this, "Connected Succesfully", "Hello "+Uname[i]+"\nYou have been connected succesfuly");

                ui->lineEdit->setStyleSheet("color: #41af5d;");
                ui->lineEdit->setText("Connected Succesfully");

                ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
                ui->lineEdit_3->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #c4ccce; padding-left: 40px;");
                LogedInUserID = i;

                this->hide();
                home = new Home(this);
                home->show();


            }
        }
    }
    if(!exist)
    {
        ui->lineEdit_2->setStyleSheet("color: #09111d;border-radius: 10px; background-color: #dbcacc; padding-left: 40px;");
        ui->lineEdit->setText("Warning : Username doesn't exist.");
    }
}





void MainWindow::on_lineEdit_3_textChanged()
{
    if(!eyeShow)
    {
        ui->toolButton->show();
        eyeShow = false;
    }
    else {
        ui->toolButton_2->show();
        eyeShow = true;
    }
}



void MainWindow::on_toolButton_clicked()
{
    ui->lineEdit_3->setEchoMode(QLineEdit::Normal);
    ui->toolButton->hide();
    ui->toolButton_2->show();
    eyeShow = true;
}


void MainWindow::on_toolButton_2_clicked()
{
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    ui->toolButton->show();
    ui->toolButton_2->hide();
    eyeShow = false;
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    registerForm = new RegisterForm(this);
    registerForm->show();

}


void MainWindow::on_pushButton_clicked()
{
    hide();
    recuperationForm = new RecupertionForm(this);
    recuperationForm->show();
}


