#include "registerform.h"
#include "ui_registerform.h"
#include "mainwindow.h"

RegisterForm::RegisterForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
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

