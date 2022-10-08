#ifndef TEA_REGIS_H
#define TEA_REGIS_H

#include <QWidget>
#include <QSqlDatabase>
#include "global.h"

namespace Ui {
class tea_regis;
}

class tea_regis : public QWidget
{
    Q_OBJECT

public:
    explicit tea_regis(QWidget *parent = nullptr);
    ~tea_regis();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tea_regis *ui;
};

#endif // TEA_REGIS_H
