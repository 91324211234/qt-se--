#ifndef STU_H
#define STU_H

#include <QWidget>
#include <QSqlDatabase>
#include "global.h"
namespace Ui {
class stu;
}

class stu : public QWidget
{
    Q_OBJECT

public:
    //static QString global_stu;
    explicit stu(QWidget *parent = nullptr);
    ~stu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::stu *ui;
    QSqlDatabase db;
};

#endif // STU_H
