#include "ubdc_schedulealarm.h"

ubdc_ScheduleAlarm::ubdc_ScheduleAlarm()
{

}

void ubdc_ScheduleAlarm::downloadFromDB_All(ubdc_ScheduleAlarm *res, int _idFaculty)
{
    query.exec("SELECT * FROM udbc_ScheduleAlarm WHERE idFaculty = '" + QString::number(_idFaculty) + "'");
    for(int i = 0; query.next(); i++)
    {
        res[i].idAlarm = query.value(0).toInt();
        res[i].idFaculty = query.value(1).toInt();
        res[i].pairNumber = query.value(2).toInt();
        res[i].timeBegin = query.value(3).toTime();
        res[i].timeEnd = query.value(4).toTime();
    }
}

void ubdc_ScheduleAlarm::downloadFromDB_One(int _idAlarm)
{
    query.exec("SELECT * FROM udbc_ScheduleAlarm WHERE idAlarm = '" + QString::number(_idAlarm) + "'");
    while (query.next())
    {
        this-> idAlarm= query.value(0).toInt();
        this-> idFaculty = query.value(1).toInt();
        this-> pairNumber = query.value(2).toInt();
        this-> timeBegin = query.value(3).toTime();
        this-> timeEnd = query.value(4).toTime();
    }
}

int ubdc_ScheduleAlarm::getQuantityRow()
{
    query.exec("SELECT * FROM udbc_ScheduleAlarm");
    this->size = query.size();
    return query.size();
}

void ubdc_ScheduleAlarm::debugData()
{
    qDebug() << "udbc_ScheduleAlarm";
    qDebug() << idAlarm;
    qDebug() << idFaculty;
    qDebug() << pairNumber;
    qDebug() << timeBegin;
    qDebug() << timeEnd;
    qDebug() << "____________";
}
