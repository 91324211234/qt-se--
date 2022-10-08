#include "stu_choose.h"
#include "ui_stu_choose.h"
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
int st[20];
int stcnt=0;
int thisterm;
stu_choose::stu_choose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stu_choose)
{
    ui->setupUi(this);
    ui->textBrowser->setText("以下课程本学期有空余名额:\n");
    QString strpre=QString("select Term from stu where stu_id='%1'").arg(message::gid);
    QSqlQuery querypre;
    querypre.exec(strpre);
    while(querypre.next())
    {
        thisterm=querypre.value(0).toInt();
    }
    QString str=QString("select course.cid,course.name from course where cnt<10&&term='%1'").arg(thisterm);
    QSqlQuery query;
    query.exec(str);
    QString name;
    while(query.next())
    {
        ui->textBrowser->append(query.value(0).toString()+" "+query.value(1).toString());
        st[stcnt]=query.value(0).toInt();
        stcnt++;
    }
    str=QString("select c_id from choose join course on c_id=cid where sid='%1' and term='%2'").arg(message::gid).arg(thisterm);
    query.exec(str);
    QVector<int> thiscourse;
    while(query.next())
    {
        //ui->textBrowser->append(prequery.value(0).toString()+" "+prequery.value(1).toString());
        thiscourse.push_back(query.value(0).toInt());
    }
    if(thiscourse.size()>=4)
        ui->textBrowser->append("本学期可选课程已满！");
}

stu_choose::~stu_choose()
{
    delete ui;
}

void stu_choose::on_pushButton_clicked()
{
    this->close();
    stu_main *pic=new stu_main();
    pic->show();
}

void stu_choose::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text()=="")
        QMessageBox::information(this,"提示","请输入课程号");
    else
    {
        QString prestr=QString("select c_id from choose join course on c_id=cid where sid='%1' and term='%2'").arg(message::gid).arg(thisterm);
        QSqlQuery prequery;
        prequery.exec(prestr);
        QVector<int> thiscourse;
        while(prequery.next())
        {
            //ui->textBrowser->append(prequery.value(0).toString()+" "+prequery.value(1).toString());
            thiscourse.push_back(prequery.value(0).toInt());
        }
        if(thiscourse.size()>=4)
            QMessageBox::information(this,"提示","本学期可选课程已满！");
        else
        {
            int ccid=ui->lineEdit->text().toInt();
            QString str=QString("select course.name from choose join course on c_id=cid where course.cid='%1' and choose.sid='%2'").arg(ccid).arg(message::gid);
            //QMessageBox::information(this,"提示",QString(ccid));
            QString name;
            QSqlQuery query;
            query.exec(str);
            while(query.next())
            {
                name=query.value(0).toString();
            }
            if(name==NULL)
            {
                str=QString("select course.name from course where course.cid='%1'").arg(ccid);
                QString flag;
                query.exec(str);
                while(query.next())
                {
                    flag=query.value(0).toString();
                    //QMessageBox::information(this,"",flag);
                }
                if(flag!=NULL)
                {
                    int stflag=0;
                    for(int i=0;i<stcnt;i++)
                    {
                        if(st[i]==ccid)
                        {
                            stflag=1;break;
                        }
                    }
                    if(stflag)
                    {
                        QString str1=QString("insert into choose values('%1','%2','no')").arg(message::gid).arg(ccid);
                        QString str2=QString("update course set cnt=cnt+1 where cid='%1'").arg(ccid);
                        QSqlQuery query1;
                        query1.exec(str1);
                        query1.exec(str2);
                        str1=QString("select * from bill where sid='%1'").arg(message::gid);
                        query1.exec(str1);
                        if(query1.next())
                            str1=QString("update bill set wage=wage+200 where sid='%1'").arg(message::gid);
                        else
                            str1=QString("insert into bill values('%1',200)").arg(message::gid);
                        query1.exec(str1);
                        QMessageBox::information(this,"提示","选课成功！");
                        str=QString("select c_id from choose join course on c_id=cid where sid='%1' and term='%2'").arg(message::gid).arg(thisterm);
                        query.exec(str);
                        QVector<int> thiscourse;
                        while(query.next())
                        {
                            //ui->textBrowser->append(prequery.value(0).toString()+" "+prequery.value(1).toString());
                            thiscourse.push_back(query.value(0).toInt());
                        }
                        if(thiscourse.size()>=4)
                            ui->textBrowser->append("本学期可选课程已满！");
                        //str1=QString("")
                    }
                    else
                    {
                        QMessageBox::information(this,"提示","课程已满！");
                    }
                }
                else
                {
                    QMessageBox::information(this,"提示","无该课程或课程已满！");
                }
            }
            else
            {
                QMessageBox::information(this,"提示","不可重复选课");
            }
        }
    }

}
