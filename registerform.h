#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

    void on_lineEdit_3_textChanged();

private:
    Ui::RegisterForm *ui;
    QSqlDatabase database;
};

#endif // REGISTERFORM_H
