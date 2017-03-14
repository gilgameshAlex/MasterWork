#ifndef UBDC_SCHEDULEALARM_H
#define UBDC_SCHEDULEALARM_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QTime>



class ubdc_ScheduleAlarm
{
private:
    QSqlQuery query;

public:
    int size;

    int idAlarm;
    int idFaculty;
    int pairNumber;
    QTime timeBegin;
    QTime timeEnd;

    ubdc_ScheduleAlarm();

    void downloadFromDB_All(ubdc_ScheduleAlarm *, int);
    int getQuantityRow();
    void downloadFromDB_One(int);

    void debugData();
};

#endif // UBDC_SCHEDULEALARM_H
