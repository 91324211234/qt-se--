#ifndef TEA_H
#define TEA_H

#include <QWidget>
#include <QSqlDatabase>
#include "global.h"
namespace Ui {
class tea;
}

class tea : public QWidget
{
    Q_OBJECT

public:
    explicit tea(QWidget *parent = nullptr);
    ~tea();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tea *ui;
    QSqlDatabase db;
};

#endif // TEA_H
