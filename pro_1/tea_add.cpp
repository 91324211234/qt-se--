#include "tea_add.h"
#include "ui_tea_add.h"
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
#include <QVector>
QVector<QString> sts;
int maxcid=0;
tea_add::tea_add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tea_add)
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
        ui->textBrowser->append(query.value(0).toString());
        sts.push_back(query.value(0).toString());
    }
    str=QString("select course.name,course.cid from course");
    query.exec(str);
    while(query.next())
    {
        maxcid=maxcid>query.value(1).toInt()?maxcid:query.value(1).toInt();
    }
    maxcid++;
}

tea_add::~tea_add()
{
    delete ui;
}

void tea_add::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        QMessageBox::information(this,"提示","请输入课程名");
    }
    else if(ui->lineEdit_2->text()=="")
    {
        QMessageBox::information(this,"提示","请选择开课学期");
    }
    else
    {
        QString cname=ui->lineEdit->text();
        QString cterm=ui->lineEdit_2->text();
        int flag=1;
        for(auto i:sts)
        {
            if(i==cname)
            {
                flag=0;break;
            }
        }
        if(flag)
        {
            QString str=QString("insert into course values('%1','%2','%3',0,'%4','%5')").arg(maxcid).arg(cname).arg(message::gid).arg(message::gdepart).arg(cterm);
            QSqlQuery query;
            query.exec(str);
            QMessageBox::information(this,"提示"," 登记完成！");
            ui->textBrowser->clear();
            ui->textBrowser->setText("您当前已开设课程:");
            str=QString("select course.name,course.cid from tea join course on tea_id=tid where tea_id='%1'").arg(message::gid);
            query.exec(str);
            sts.clear();
            while(query.next())
            {
                ui->textBrowser->append(query.value(0).toString());
                sts.push_back(query.value(0).toString());
                maxcid=maxcid>query.value(1).toInt()?maxcid:query.value(1).toInt();
            }
            maxcid++;
        }
        else
        {
            QMessageBox::information(this,"提示","已有该课程");
        }
    }

}

void tea_add::on_pushButton_2_clicked()
{
    this->close();
    tea_main *pic=new tea_main();
    pic->show();
}
