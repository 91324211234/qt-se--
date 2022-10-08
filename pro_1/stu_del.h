#ifndef STU_DEL_H
#define STU_DEL_H

#include <QWidget>

namespace Ui {
class stu_del;
}

class stu_del : public QWidget
{
    Q_OBJECT

public:
    explicit stu_del(QWidget *parent = nullptr);
    ~stu_del();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::stu_del *ui;
};

#endif // STU_DEL_H
