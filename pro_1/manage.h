#ifndef MANAGE_H
#define MANAGE_H

#include <QWidget>
#include <QSqlDatabase>
#include "global.h"

namespace Ui {
class manage;
}

class manage : public QWidget
{
    Q_OBJECT

public:
    explicit manage(QWidget *parent = nullptr);
    ~manage();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::manage *ui;
    QSqlDatabase db;
};

#endif // MANAGE_H
