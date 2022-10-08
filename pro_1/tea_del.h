#ifndef TEA_DEL_H
#define TEA_DEL_H

#include <QWidget>
#include <QSqlDatabase>
#include "global.h"

namespace Ui {
class tea_del;
}

class tea_del : public QWidget
{
    Q_OBJECT

public:
    explicit tea_del(QWidget *parent = nullptr);
    ~tea_del();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tea_del *ui;
    QSqlDatabase db;
};

#endif // TEA_DEL_H
