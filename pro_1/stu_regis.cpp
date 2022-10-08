#include "stu_regis.h"
#include "ui_stu_regis.h"
#include "global.h"
#include "stu_main.h"
#include "ui_stu_main.h"
#include "stu.h"
#include "ui_stu.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlError>
#include <QSqlTableModel>
#include "stu_changepwd.h"
#include "ui_stu_changepwd.h"
#include "stu_choose.h"
#include "ui_stu_choose.h"
#include "stu_del.h"
#include "ui_stu_del.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

stu_regis::stu_regis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stu_regis)
{
    ui->setupUi(this);
}

stu_regis::~stu_regis()
{
    delete ui;
}

void stu_regis::on_pushButton_2_clicked()
{
    QString str=QString("select stu_id from stu");
    QSqlQuery query;
    query.exec(str);
    int num=1001;
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
    if(pass1!=pass2)
    {
        QMessageBox::information(this,"提示","两次密码不一致");
    }
    else
    {
        str=QString("insert into stu values('%1','%2','%3',1)").arg(num).arg(name).arg(pass1);
        query.exec(str);
        QMessageBox::information(this,"提示","注册成功,你的学号是"+QString::number(num));
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit->clear();
    }
}

void stu_regis::on_pushButton_clicked()
{
    this->close();
    stu *pic=new stu();
    pic->show();
}
