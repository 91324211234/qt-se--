#include "tea_changepwd.h"
#include "ui_tea_changepwd.h"
#include "tea_main.h"
#include "ui_tea_main.h"
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
#include "tea_add.h"
#include "ui_tea_add.h"
tea_changepwd::tea_changepwd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tea_changepwd)
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

tea_changepwd::~tea_changepwd()
{
    delete ui;
}

void tea_changepwd::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        QMessageBox::information(this,"提示","请输入旧密码");
    }
    else if(message::gpwd!=ui->lineEdit->text())
        QMessageBox::information(this,"提示","错误的旧密码");
    else
    {
        if(ui->lineEdit_2->text()!=ui->lineEdit_3->text())
            QMessageBox::information(this,"提示","两次密码不匹配！");
        else
        {
            QString str=QString("update tea set pwd='%1' where name='%2'").arg(ui->lineEdit_2->text()).arg(message::display);
            QSqlQuery query;
            query.exec(str);
            QMessageBox::information(this,"提示","修改成功！");
            this->close();
            tea_main *pic=new tea_main();
            pic->show();
            message::gpwd=ui->lineEdit_2->text();
        }
    }
}

void tea_changepwd::on_pushButton_2_clicked()
{
    this->close();
    tea_main *pic=new tea_main();
    pic->show();
}
