#include "tea_give.h"
#include "ui_tea_give.h"
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

QVector<int> stst;
int gmaxcid=0;
QVector<int> tmpstu;
tea_give::tea_give(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tea_give)
{
    ui->setupUi(this);
    ui->textBrowser->setText("您当前已开设课程:");
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
    QString str=QString("select course.name,course.cid from tea join course on tea_id=tid where tea_id='%1'").arg(message::gid);
    QSqlQuery query;
    query.exec(str);

    while(query.next())
    {
        ui->textBrowser->append(query.value(1).toString()+" "+query.value(0).toString());
        stst.push_back(query.value(1).toInt());
        gmaxcid=gmaxcid>query.value(1).toInt()?gmaxcid:query.value(1).toInt();
    }
    gmaxcid++;
    ui->label_2->hide();
    ui->lineEdit_2->hide();
    ui->pushButton_3->hide();
}

tea_give::~tea_give()
{
    delete ui;
}
int give_num;
void tea_give::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        QMessageBox::information(this,"提示","请输入课程号");
    }
    else
    {
        give_num=ui->lineEdit->text().toInt();
        int flag=0;
        for(auto i:stst)
        {
            if(i==give_num)
            {
                flag=1;break;
            }
        }
        if(flag)
        {
            ui->lineEdit->clear();
            ui->label_2->show();
            ui->lineEdit_2->show();
            ui->pushButton->hide();
            ui->pushButton_3->show();
            ui->textBrowser->setText("选择该课程的学生:\n学号 姓名 成绩");
            QString str=QString("select sid,name,grade from choose join stu on sid=stu_id where c_id='%1'").arg(give_num);
            QSqlQuery query;
            query.exec(str);
            while(query.next())
            {
                ui->textBrowser->append(query.value(0).toString()+" "+query.value(1).toString()+" "+query.value(2).toString());
                tmpstu.push_back(query.value(0).toInt());
            }
            ui->label->setText("学号");
        }
        else
        {
            QMessageBox::information(this,"提示","无该课程");
        }
    }
}

void tea_give::on_pushButton_2_clicked()
{
    this->close();
    tea_main *pic=new tea_main();
    pic->show();
}

void tea_give::on_pushButton_3_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        QMessageBox::information(this,"提示","请输入学号");
    }
    else if(ui->lineEdit_2->text()=="")
    {
        QMessageBox::information(this,"提示","请输入成绩");
    }
    else
    {
        int sid=ui->lineEdit->text().toInt();
        int sgrade=ui->lineEdit_2->text().toInt();
        int flag=0;
        for(auto i:tmpstu)
        {
            if(i==sid)
            {
                flag=1;break;
            }
        }
        if(flag)
        {
            QString str=QString("update choose set grade='%1' where sid='%2' and c_id='%3'").arg(sgrade).arg(sid).arg(give_num);
            QSqlQuery query;
            query.exec(str);
            QMessageBox::information(this,"提示","登记成功！");
            ui->textBrowser->setText("选择该课程的学生:\n学号 姓名 成绩");
            str=QString("select sid,name,grade from choose join stu on sid=stu_id where c_id='%1'").arg(give_num);
            query.exec(str);
            while(query.next())
            {
                ui->textBrowser->append(query.value(0).toString()+" "+query.value(1).toString()+" "+query.value(2).toString());
            }
        }
        else
        {
            QMessageBox::information(this,"提示","无该学生");
        }
    }

}
