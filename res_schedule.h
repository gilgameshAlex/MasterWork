#ifndef RES_SCHEDULE_H
#define RES_SCHEDULE_H

#include <QDebug>

class res_Schedule
{
public:
    int idSchedule;
    int codeSchedule;
    int idFaculty;
    int idDay;
    int idSubjectTeacher;
    int idHall;
    int idAlarm;

    res_Schedule();

    void printSchedule(res_Schedule *, int, int);
};

#endif // RES_SCHEDULE_H
