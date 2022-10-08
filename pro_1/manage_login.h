#ifndef MANAGE_LOGIN_H
#define MANAGE_LOGIN_H

#include <QWidget>

namespace Ui {
class manage_login;
}

class manage_login : public QWidget
{
    Q_OBJECT

public:
    explicit manage_login(QWidget *parent = nullptr);
    ~manage_login();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::manage_login *ui;
};

#endif // MANAGE_LOGIN_H
