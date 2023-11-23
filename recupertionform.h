#ifndef RECUPERTIONFORM_H
#define RECUPERTIONFORM_H

#include <QDialog>
#include "registerform.h"
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class RecupertionForm;
}

class RecupertionForm : public QDialog
{
    Q_OBJECT

public:
    explicit RecupertionForm(QWidget *parent = nullptr);
    ~RecupertionForm();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::RecupertionForm *ui;
    RegisterForm *registerForm;
    QSqlDatabase database;
};

#endif // RECUPERTIONFORM_H
