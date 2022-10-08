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
class message;
tea::tea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tea)
{
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("123456"); //填写自己的密码
    if(!db.open()) {
       qDebug() << "error!\n";
    } else {
       qDebug() << "Open";
    }
    ui->setupUi(this);
}

tea::~tea()
{
    delete ui;
}

void tea::on_pushButton_clicked()
{
    if(ui->lineEditNum->text()=="")
    {
        QMessageBox::information(this,"提示","请输入用户名");
    }
    else if(ui->lineEditNum_2->text()=="")
    {
        QMessageBox::information(this,"提示","请输入密码");
    }
    else
    {
        int num=ui->lineEditNum->text().toInt();
        QString str=QString("select * from tea where tea_id='%1'").arg(num);
        QSqlQuery query;
        query.exec(str);
        QString name;
        int number;
        QString pwd=ui->lineEditNum_2->text();
        QString check;
        while(query.next())
        {
            message::gid=query.value(0).toInt();
            number=query.value(0).toInt();
            message::display=query.value(1).toString();
            name=query.value(1).toString();
            message::gpwd=query.value(2).toString();
            check=query.value(2).toString();
            message::gdepart=query.value(3).toString();
        }
        if(name==NULL)
        {
            QMessageBox::information(this,"提示","无该教工号");
            ui->lineEditNum->clear();
            ui->lineEditNum_2->clear();
        }
        else if(pwd!=check)
        {
            QMessageBox::information(this,"提示","密码错误");
            ui->lineEditNum_2->clear();
        }
        else
        {
            QMessageBox::information(this,"提示","登陆成功！");
            //转到教师功能界面
            this->close();
            tea_main *pic=new tea_main();
            pic->show();
        }
    }

}

void tea::on_pushButton_3_clicked()
{
    MainWindow *pic=new MainWindow();
    this->close();
    pic->show();
}

void tea::on_pushButton_2_clicked()
{
    tea_regis *pic=new tea_regis();
    this->close();
    pic->show();
}
