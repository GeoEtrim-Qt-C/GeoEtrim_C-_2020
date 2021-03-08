#ifndef CANVASNEW_H
#define CANVASNEW_H

#include <QWidget>



namespace Ui {
class canvasnew;
}

class canvasnew : public QWidget
{
    Q_OBJECT

public:
    explicit canvasnew(QWidget *parent = nullptr);
    ~canvasnew();


private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::canvasnew *ui;


};

#endif // CANVASNEW_H
