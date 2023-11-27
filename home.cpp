#include "home.h"
#include "ui_home.h"
#include "mainwindow.h"


const int DB_SIZE = 100;
extern int nextTuple;
extern QString fName[DB_SIZE];
extern QString Email[DB_SIZE];
extern QString Uname[DB_SIZE];
extern QString Pass[DB_SIZE];
extern int LogedInUserID;


Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);

    // User info setup:
    ui->lineEdit->setText(Uname[LogedInUserID]);
    ui->lineEdit_6->setText(fName[LogedInUserID]);
    ui->lineEdit_8->setText(Email[LogedInUserID]);

}

Home::~Home()
{
    delete ui;
}

