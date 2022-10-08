#include "tea_del.h"
#include "ui_tea_del.h"
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
QVector<int> del_sts;
tea_del::tea_del(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tea_del)
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
        del_sts.push_back(query.value(1).toInt());
    }
}

tea_del::~tea_del()
{
    delete ui;
}

void tea_del::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        QMessageBox::information(this,"提示","请输入课程号！");
    }
    else
    {
        int did=ui->lineEdit->text().toInt();
        int flag=0;
        for(auto i:del_sts)
        {
            if(i==did)
            {
                flag=1;break;
            }
        }
        if(flag)
        {
            QString str=QString("delete from course where cid='%1'").arg(did);
            QSqlQuery query;
            query.exec(str);
            QMessageBox::information(this,"提示","删除成功！");
            ui->textBrowser->setText("您当前已开设课程:");
            str=QString("select course.name,course.cid from tea join course on tea_id=tid where tea_id='%1'").arg(message::gid);
            query.exec(str);
            del_sts.clear();
            while(query.next())
            {
                ui->textBrowser->append(query.value(1).toString()+" "+query.value(0).toString());
                del_sts.push_back(query.value(1).toInt());
            }
        }
    }

}

void tea_del::on_pushButton_2_clicked()
{
    this->close();
    tea_main *pic=new tea_main();
    pic->show();
}
