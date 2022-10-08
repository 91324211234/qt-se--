#include "manage_login.h"
#include "ui_manage_login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manage.h"
#include "ui_manage.h"
#include <QMessageBox>

manage_login::manage_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manage_login)
{
    ui->setupUi(this);
}

manage_login::~manage_login()
{
    delete ui;
}

void manage_login::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *w=new MainWindow();
    w->show();
}

void manage_login::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        QMessageBox::information(this,"提示","请输入用户名");
    }
    else if(ui->lineEdit_2->text()=="")
    {
        QMessageBox::information(this,"提示","请输入密码");
    }
    if(ui->lineEdit->text()=="root"&&ui->lineEdit_2->text()=="123456")
    {
        QMessageBox::information(this,"提示","登陆成功！");
        this->close();
        manage *pic=new manage();
        pic->show();
    }
    else {
        QMessageBox::information(this,"提示","错误的验证信息");
    }
}
