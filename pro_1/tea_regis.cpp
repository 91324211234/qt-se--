#include "tea.h"
#include "ui_tea.h"
#include "tea_regis.h"
#include "ui_tea_regis.h"
#include "global.h"
#include "stu.h"
#include "ui_stu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stu_main.h"
#include "ui_stu_main.h"
#include "tea_main.h"
#include "ui_tea.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlError>
#include <QSqlTableModel>

tea_regis::tea_regis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tea_regis)
{
    ui->setupUi(this);
}

tea_regis::~tea_regis()
{
    delete ui;
}

void tea_regis::on_pushButton_clicked()
{
    tea *pic=new tea();
    this->close();
    pic->show();
}

void tea_regis::on_pushButton_2_clicked()
{
    QString str=QString("select tea_id from tea");
    QSqlQuery query;
    query.exec(str);
    int num=2001;
    while(query.next())
    {
        if(query.value(0).toInt()>num)
        {
            num=query.value(0).toInt();
        }
    }
    num++;
    QString name=ui->lineEdit->text();
    int pass1=ui->lineEdit_2->text().toInt();
    int pass2=ui->lineEdit_3->text().toInt();
    QString dept=ui->lineEdit_4->text();
    if(pass1!=pass2)
    {
        QMessageBox::information(this,"提示","两次密码不一致");
    }
    else
    {
        str=QString("insert into tea values('%1','%2','%3','%4')").arg(num).arg(name).arg(pass1).arg(dept);
        query.exec(str);
        QMessageBox::information(this,"提示","注册成功,你的教工号是"+QString::number(num));
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
        ui->lineEdit_4->clear();
    }
}
