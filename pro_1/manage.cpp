#include "manage.h"
#include "ui_manage.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlError>
#include <QSqlTableModel>
class message;
manage::manage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manage)
{
    ui->setupUi(this);
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
}

manage::~manage()
{
    delete ui;
}

void manage::on_pushButton_4_clicked()
{
    this->close();
    MainWindow *w=new MainWindow();
    w->show();
}

void manage::on_pushButton_clicked()
{
    message::STUCHOOSE=0;
    QMessageBox::information(this,"提示","关闭成功");
}

void manage::on_pushButton_2_clicked()
{
    message::STUCHOOSE=1;
    QMessageBox::information(this,"提示","开启成功");
}

void manage::on_pushButton_3_clicked()
{
    QString str=QString("select cid from course where cnt<3");
    QSqlQuery query;
    query.exec(str);
    QVector<int> delco;
    while(query.next())
    {
        delco.push_back(query.value(0).toInt());
    }

    str=QString("delete from course where cnt<3");
    query.exec(str);

    for(auto i:delco)
    {
        str=QString("delete from choose where c_id='%1'").arg(i);
        query.exec(str);
    }
    QMessageBox::information(this,"提示","已关闭课程");
}

QVector<QString> t;
int index=0;
int tsize=0;
void manage::on_pushButton_5_clicked()
{
    QString str=QString("select * from consume");
    QSqlQuery query;
    query.exec(str);
    while(query.next())
    {
        t.push_back(query.value(0).toString()+" "+query.value(1).toString()+" "+query.value(2).toString());
    }
    tsize=t.size();
    for(index=0;index<qMin(tsize,10);index++)
    {
        ui->textBrowser->append(t[index]);
    }
    ui->pushButton_6->show();
    ui->pushButton_7->show();
}

void manage::on_pushButton_6_clicked()
{
    index=qMax(index-10-(index%10),0);int pm=index;
    ui->textBrowser->clear();
    for(index;index<qMin(tsize,pm+10);index++)
    {
        ui->textBrowser->append(t[index]);
    }
}

void manage::on_pushButton_7_clicked()
{
    int pm=index;
    if(index!=tsize)
    {
        ui->textBrowser->clear();
        for(index;index<qMin(tsize,pm+10);index++)
        {
            ui->textBrowser->append(t[index]);
        }
    }

}
