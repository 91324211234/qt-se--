#ifndef TEA_MAIN_H
#define TEA_MAIN_H

#include <QWidget>

namespace Ui {
class tea_main;
}

class tea_main : public QWidget
{
    Q_OBJECT

public:
    explicit tea_main(QWidget *parent = nullptr);
    ~tea_main();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::tea_main *ui;
};

#endif // TEA_MAIN_H
