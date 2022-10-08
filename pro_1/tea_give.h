#ifndef TEA_GIVE_H
#define TEA_GIVE_H

#include <QWidget>
#include <QSqlDatabase>
#include "global.h"

namespace Ui {
class tea_give;
}

class tea_give : public QWidget
{
    Q_OBJECT

public:
    explicit tea_give(QWidget *parent = nullptr);
    ~tea_give();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::tea_give *ui;
    QSqlDatabase db;
};

#endif // TEA_GIVE_H
