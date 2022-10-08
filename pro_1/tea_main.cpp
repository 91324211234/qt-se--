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
#include "tea_changepwd.h"
#include "ui_tea_changepwd.h"
#include "tea_give.h"
#include "ui_tea_give.h"
#include "tea_del.h"
#include "ui_tea_del.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
class message;
tea_main::tea_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tea_main)
{
    ui->setupUi(this);
    ui->label_2->setText(message::display);
}

tea_main::~tea_main()
{
    delete ui;
}
//登记课程
void tea_main::on_pushButton_clicked()
{
    this->close();
    tea_add *pic=new tea_add();
    pic->show();
}
//修改密码
void tea_main::on_pushButton_4_clicked()
{
    this->close();
    tea_changepwd *pic=new tea_changepwd();
    pic->show();
}
//登记分数
void tea_main::on_pushButton_2_clicked()
{
    this->close();
    tea_give *pic=new tea_give();
    pic->show();
}

void tea_main::on_pushButton_3_clicked()
{
    this->close();
    tea_del *pic=new tea_del;
    pic->show();
}

void tea_main::on_pushButton_5_clicked()
{
    this->close();
    MainWindow *w=new MainWindow();
    w->show();
}
