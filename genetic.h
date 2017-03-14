#ifndef GENETIC_H
#define GENETIC_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>

#include "res_schedule.h"
#include "ubd_groups.h"
#include "ubd_subjectteacher.h"
#include "ubd_lecturehalls.h"
#include "ubdc_schedulealarm.h"

class Genetic : public QObject
{
Q_OBJECT

signals:
    void _ChangeValue();

private:
    int sizePopulation; //Размер популяции
    int currentFaculty; //Факультет для которого составляется расписание
    int quatityStudyDays; //Кол-во учебных дней
    int codeCurrentFaculty;
    int sizeSchedule;//Формируется из размера популяции * кол-во учебных дней
    int sizeST;
    ubd_Groups * Groups; //Группы студентов
    ubd_SubjectTeacher * SubjectTeacher; //Назначения п-п
    ubd_LectureHalls * LectureHalls;
    ubdc_ScheduleAlarm * Alarm;


public:
    res_Schedule *schedule;
    int * schedulePenalty;

    Genetic();
    ~Genetic();

    void setSizePopulation(int);
    void setQuatityStudyDays(int);
    void setCurrentFaculty(int);
    void setCodeCurrentFaculty(int);

    bool CreateFirstPopulation();
    bool CreateNewGen(int);
    bool Mutation(int, int);
    bool Crossing();
    bool Criteria();
    bool StartGenetic();

};

#endif // GENETIC_H
