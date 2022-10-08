#ifndef STU_REGIS_H
#define STU_REGIS_H

#include <QWidget>
#include "global.h"

namespace Ui {
class stu_regis;
}

class stu_regis : public QWidget
{
    Q_OBJECT

public:
    explicit stu_regis(QWidget *parent = nullptr);
    ~stu_regis();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::stu_regis *ui;
};

#endif // STU_REGIS_H
