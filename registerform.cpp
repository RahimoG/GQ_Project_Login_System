#include "registerform.h"
#include "ui_registerform.h"
#include "mainwindow.h"

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
    qDebug() << QSqlDatabase::drivers();
    // ADDING TUPELES TO THE DB:
    //Connection to DB:
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("loclhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("qt_login_system");

    //connection check:
    if(database.open()){
        // recicing data from formular:
        QMessageBox::information(this, "Not connected","connection to db");

    }else{
        QMessageBox::information(this, "Not connected","No connection to db");
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

