#include "res_schedule.h"

#include <QPrinter>

res_Schedule::res_Schedule()
{

}

void res_Schedule::printSchedule(res_Schedule *arr, int size, int _codeSchedule)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i].codeSchedule == _codeSchedule)
        {
              qDebug() << "idSchedule = " << arr[i].idSchedule;
              qDebug() << "codeSchedule = " << arr[i].codeSchedule;
              qDebug() << "idFaculty = " << arr[i].idFaculty;
              qDebug() << "idDay = " << arr[i].idDay;
              qDebug() << "idST = " << arr[i].idSubjectTeacher;
              qDebug() << "idHall = " << arr[i].idHall;
              qDebug() << "idAlarm = " << arr[i].idAlarm;
              qDebug() << "_________________________________";
        }
    }
}
