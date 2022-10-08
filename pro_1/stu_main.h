#ifndef STU_MAIN_H
#define STU_MAIN_H

#include <QWidget>
#include "global.h"
namespace Ui {
class stu_main;
}

class stu_main : public QWidget
{
    Q_OBJECT

public:
    explicit stu_main(QWidget *parent = nullptr);
    void getName(QString str);
    void outName();
    ~stu_main();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::stu_main *ui;
    QString name;
};

#endif // STU_MAIN_H
