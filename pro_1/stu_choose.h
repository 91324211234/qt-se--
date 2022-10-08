#ifndef STU_CHOOSE_H
#define STU_CHOOSE_H

#include <QWidget>

namespace Ui {
class stu_choose;
}

class stu_choose : public QWidget
{
    Q_OBJECT

public:
    explicit stu_choose(QWidget *parent = nullptr);
    ~stu_choose();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::stu_choose *ui;
};

#endif // STU_CHOOSE_H
