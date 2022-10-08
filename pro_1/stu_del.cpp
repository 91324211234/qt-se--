#include "stu_del.h"
#include "ui_stu_del.h"
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
QVector<int> has;
stu_del::stu_del(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stu_del)
{
    ui->setupUi(this);
    ui->textBrowser->setText("已选课程");
    QString str=QString("select course.name,cid from stu join choose on stu_id=sid join course on c_id=cid where stu_id='%1'").arg(message::gid);
    QSqlQuery query;
    query.exec(str);
    QString name;
    while(query.next())
    {
        ui->textBrowser->append(query.value(1).toString()+" "+query.value(0).toString());
        has.push_back(query.value(1).toInt());
    }
}

stu_del::~stu_del()
{
    delete ui;
}

void stu_del::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text()=="")
    {
        QMessageBox::information(this,"提示","请输入课程号");
    }
    else
    {
        int ccid=ui->lineEdit->text().toInt();
        int flag=0;
        for(auto i:has)
        {
            if(i==ccid)
            {
                flag=1;break;
            }
        }
        if(flag)
        {
            QString str=QString("delete from choose where c_id='%1'").arg(ccid);
            QSqlQuery query;
            query.exec(str);
            str=QString("update bill set wage=wage-200 where sid='%1'").arg(message::gid);
            query.exec(str);
            ui->textBrowser->setText("已选课程");
            str=QString("select course.name,cid from stu join choose on stu_id=sid join course on c_id=cid where stu_id='%1'").arg(message::gid);
            query.exec(str);
            has.clear();
            while(query.next())
            {
                ui->textBrowser->append(query.value(1).toString()+" "+query.value(0).toString());
                has.push_back(query.value(1).toInt());
            }
            str=QString("update course set cnt=cnt-1 where cid='%1'").arg(ccid);
            query.exec(str);
        }
        else
        {
            QMessageBox::information(this,"提示","未选择该课程");
        }
    }

}

void stu_del::on_pushButton_clicked()
{
    this->close();
    stu_main* pic=new stu_main();
    pic->show();
}
