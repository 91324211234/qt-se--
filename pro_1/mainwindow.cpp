#include "manage_login.h"
#include "ui_manage_login.h"
#include "global.h"
#include "manage.h"
#include "ui_manage.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stu.h"
#include "ui_stu.h"
#include "tea.h"
#include "ui_tea.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlError>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qDebug()<<QSqlDatabase::drivers();
    //连接到mysql数据库
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
    //学生或老师登录
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"提示","以学生身份继续");
    this->close();
    stu *pic=new stu();
    pic->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"提示","以教师身份继续");
    this->close();
    tea *pic=new tea();
    pic->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this,"提示","以管理员身份继续");
    this->close();
    manage_login *pic=new manage_login();
    pic->show();
}
