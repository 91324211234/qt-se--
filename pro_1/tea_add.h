#ifndef TEA_ADD_H
#define TEA_ADD_H

#include <QWidget>
#include <QSqlDatabase>
#include "global.h"

namespace Ui {
class tea_add;
}

class tea_add : public QWidget
{
    Q_OBJECT

public:
    explicit tea_add(QWidget *parent = nullptr);
    ~tea_add();

private slots:
    void on_pushButton_clicked();

    
    void on_pushButton_2_clicked();

private:
    Ui::tea_add *ui;
    QSqlDatabase db;
};

#endif // TEA_ADD_H
