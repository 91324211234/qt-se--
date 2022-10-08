#ifndef STU_CHANGEPWD_H
#define STU_CHANGEPWD_H

#include <QWidget>
#include <QSqlDatabase>
#include "global.h"

namespace Ui {
class stu_changepwd;
}

class stu_changepwd : public QWidget
{
    Q_OBJECT

public:
    explicit stu_changepwd(QWidget *parent = nullptr);
    ~stu_changepwd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::stu_changepwd *ui;
    QSqlDatabase db;
};

#endif // STU_CHANGEPWD_H
