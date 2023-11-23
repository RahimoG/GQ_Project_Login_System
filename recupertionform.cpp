#include "recupertionform.h"
#include "ui_recupertionform.h"
#include "mainwindow.h"

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

