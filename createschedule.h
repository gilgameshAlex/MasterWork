#ifndef CREATESCHEDULE_H
#define CREATESCHEDULE_H

#include <QMainWindow>
#include <QSettings>
#include <QSqlDatabase>
#include <QDebug>

namespace Ui {
class CreateSchedule;
}

class CreateSchedule : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateSchedule(QWidget *parent = 0);
    ~CreateSchedule();

private slots:
    void on_createSchedule_clicked();
    void valueChanged();

private:
    Ui::CreateSchedule *ui;
    QSqlDatabase db;
};

#endif // CREATESCHEDULE_H
