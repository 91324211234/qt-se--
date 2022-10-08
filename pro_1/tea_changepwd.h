#ifndef TEA_CHANGEPWD_H
#define TEA_CHANGEPWD_H

#include <QWidget>
#include <QSqlDatabase>
#include "global.h"

namespace Ui {
class tea_changepwd;
}

class tea_changepwd : public QWidget
{
    Q_OBJECT

public:
    explicit tea_changepwd(QWidget *parent = nullptr);
    ~tea_changepwd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tea_changepwd *ui;
    QSqlDatabase db;
};

#endif // TEA_CHANGEPWD_H
