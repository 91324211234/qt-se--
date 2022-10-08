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
#include "stu_regis.h"
#include "ui_stu_regis.h"
class message;
stu_main::stu_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stu_main)
{
    ui->setupUi(this);
    //QMessageBox::information(this,"提示",message::display);
    ui->label_2->setText(message::display);
    ui->label_3->hide();
    ui->lineEdit->hide();
    ui->pushButton_8->hide();
}

stu_main::~stu_main()
{
    delete ui;
}

void stu_main::getName(QString str)
{
    this->name=str;
}

void stu_main::outName()
{
    QMessageBox::information(this,"tishi",this->name);
}

void stu_main::on_pushButton_4_clicked()
{
    this->close();
    stu_changepwd *pic=new stu_changepwd();
    pic->show();
}

void stu_main::on_pushButton_3_clicked()
{
    ui->textBrowser->setText("已选课程");
    QString str=QString("select course.name from stu join choose on stu_id=sid join course on c_id=cid where stu_id='%1'").arg(message::gid);
    QSqlQuery query;
    query.exec(str);
    QString name;
    while(query.next())
    {
        ui->textBrowser->append(query.value(0).toString());
    }
}

void stu_main::on_pushButton_clicked()
{
    if(message::STUCHOOSE==1)
    {
        this->close();
        stu_choose *pic=new stu_choose();
        pic->show();
    }
    else
        QMessageBox::information(this,"提示","非选课时间！");
}

void stu_main::on_pushButton_2_clicked()
{
    ui->textBrowser->setText("课程 成绩");
    QString str=QString("select course.name,choose.grade from stu join choose on stu_id=sid join course on c_id=cid where stu_id='%1'").arg(message::gid);
    QSqlQuery query;
    query.exec(str);
    QString name;
    while(query.next())
    {
        ui->textBrowser->append(query.value(0).toString()+" "+query.value(1).toString());
    }
}

void stu_main::on_pushButton_5_clicked()
{
    this->close();
    MainWindow *w=new MainWindow();
    w->show();
}

void stu_main::on_pushButton_6_clicked()
{
    if(message::STUCHOOSE==1)
    {
        this->close();
        stu_del *pic=new stu_del();
        pic->show();
    }
    else
        QMessageBox::information(this,"提示","非选课时间！");
}

void stu_main::on_pushButton_7_clicked()
{
    QString str=QString("select wage from bill where sid='%1'").arg(message::gid);
    QSqlQuery query;
    query.exec(str);
    while(query.next())
    {
        ui->textBrowser->append("账单总计：");
        if(query.value(0).toInt()>=0)
            ui->textBrowser->append(query.value(0).toString());
        else
            ui->textBrowser->append("可退款金额:"+QString::number(qAbs(query.value(0).toInt())));
    }
    ui->label_3->show();
    ui->lineEdit->show();
    ui->pushButton_8->show();
}

void stu_main::on_pushButton_8_clicked()
{
    QString str=QString("select bid from consume");
    QSqlQuery query;
    query.exec(str);
    int maxwid=3000;
    while(query.next())
    {
        maxwid=maxwid>query.value(0).toInt()?maxwid:query.value(0).toInt();
    }
    maxwid++;
    int num=ui->lineEdit->text().toInt();
    str=QString("select wage from bill where sid='%1'").arg(message::gid);
    query.exec(str);
    int twage=0;
    while(query.next())
    {
        twage=query.value(0).toInt();
    }
    if(twage<num)
    {
        QMessageBox::information(this,"提示","超出最大所需支付金额");
    }
    else
    {
        str=QString("update bill set wage=wage-'%1' where sid='%2'").arg(num).arg(message::gid);
        query.exec(str);
        str=QString("insert into consume values('%1','%2','%3')").arg(maxwid).arg(message::gid).arg(num);
        maxwid++;
        query.exec(str);
        QMessageBox::information(this,"提示","支付完成！");
        str=QString("select wage from bill where sid='%1'").arg(message::gid);
        query.exec(str);
        while(query.next())
        {
            ui->textBrowser->clear();
            ui->textBrowser->append("账单总计：");
            if(query.value(0).toInt()>=0)
                ui->textBrowser->append(query.value(0).toString());
            else
                ui->textBrowser->append("可退款金额:"+QString(qAbs(query.value(0).toInt())));
        }
    }
}
