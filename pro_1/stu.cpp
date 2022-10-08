#include "global.h"
#include "stu.h"
#include "ui_stu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stu_main.h"
#include "ui_stu_main.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlError>
#include <QSqlTableModel>
#include "stu_regis.h"
#include "ui_stu_regis.h"

//QString stu::global_stu="";
class message;
stu::stu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stu)
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
    //message::display=ui->lineEditNum->text();
}

stu::~stu()
{
    delete ui;
}

void stu::on_pushButton_clicked()
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
        QString str=QString("select * from stu where stu_id='%1'").arg(num);
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
            check=query.value(2).toString();
            message::gpwd=query.value(2).toString();
        }
        if(name==NULL)
        {
            QMessageBox::information(this,"提示","无该学号");
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
            //转到学生功能界面
            this->close();
            stu_main *pic=new stu_main();
            pic->show();
        }
    }
}

void stu::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *pic=new MainWindow();
    pic->show();
}

void stu::on_pushButton_3_clicked()
{
    this->close();
    stu_regis *pic=new stu_regis();
    pic->show();
}
