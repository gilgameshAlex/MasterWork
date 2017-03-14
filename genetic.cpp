#include "genetic.h"
#include "time.h"
Genetic::Genetic()
{
    sizePopulation = 50;
    currentFaculty = 7;
    quatityStudyDays = 6;
    SubjectTeacher = new ubd_SubjectTeacher [(new ubd_SubjectTeacher)->getQuantityRow()];
    LectureHalls = new ubd_LectureHalls [(new ubd_LectureHalls)->getQuantityRow()];
    Alarm = new ubdc_ScheduleAlarm [(new ubdc_ScheduleAlarm)->getQuantityRow()];
    sizeST = (new ubd_SubjectTeacher)->getQuantityRow();
}

Genetic::~Genetic()
{
    delete [] SubjectTeacher;
    delete [] LectureHalls;
    delete [] Alarm;
    delete [] schedule;
    delete [] schedulePenalty;
}

void Genetic::setSizePopulation(int size)
{
    this->sizePopulation = size;
}

void Genetic::setQuatityStudyDays(int quan)
{
    this->quatityStudyDays = quan;
}

void Genetic::setCodeCurrentFaculty(int codeFaculty)
{
    this->codeCurrentFaculty = codeFaculty;
}

bool Genetic::CreateFirstPopulation()
{
    srand(time(NULL));
    SubjectTeacher->downloadFromDB_All(SubjectTeacher, currentFaculty);
    LectureHalls->downloadFromDB_All(LectureHalls, currentFaculty);
    Alarm->downloadFromDB_All(Alarm, currentFaculty);
    for(int i = 0, k = 0; i < sizePopulation; i++)
    {
        for(int j = 0; j < sizeST; j++, k++)
        {
            schedule[k].idSchedule = k;
            schedule[k].codeSchedule = i;
            schedule[k].idFaculty = currentFaculty;
            //-------------------------------------
            schedule[k].idDay = 1 + rand() % quatityStudyDays;
            schedule[k].idSubjectTeacher = SubjectTeacher[j].idST;
            schedule[k].idHall = LectureHalls[0 + rand() % LectureHalls->getQuantityRow()-1].idHall;
            schedule[k].idAlarm = Alarm[0 + rand() % Alarm->getQuantityRow()-1].idAlarm;
        }
    }
    //schedule[0].printSchedule(schedule, sizeSchedule, 1);
    return true;
}

bool Genetic::CreateNewGen(int index)
{
    srand(time(NULL));
    schedule[index].idDay = 1 + rand() % quatityStudyDays;
    schedule[index].idHall = LectureHalls[0 + rand() % LectureHalls->getQuantityRow()-1].idHall;
    schedule[index].idAlarm = Alarm[0 + rand() % Alarm->getQuantityRow()-1].idAlarm;
    return true;
}

bool Genetic::Mutation(int begin, int count)
{
    srand(time(NULL));
    int randomize;
    int index;
    for(int i = begin, j = 0; j < count; i++, j++)
    {
        randomize = 0 + rand() % 1;
        if(randomize == 0 && schedule[i].idDay > 0)
            schedule[i].idDay --;
        else
            schedule[i].idDay ++;
        //-----------------------------------------
        randomize = 0 + rand() % 1;
        index = LectureHalls->getQuantityRow();
        if(randomize == 0 && index - 1 >= 0)
            schedule[i].idHall = LectureHalls[index - 1].idHall;
        else
            schedule[i].idHall = LectureHalls[index + 1].idHall;
        //-----------------------------------------
        randomize = 0 + rand() % 1;
        index = Alarm->getQuantityRow();
        if(randomize == 0 && index - 1 >= 0)
            schedule[i].idAlarm = Alarm[index - 1].idAlarm;
        else
            schedule[i].idAlarm = Alarm[index + 1].idAlarm;
        qDebug() << j;
    }
    return true;
}

bool Genetic::Crossing()
{
    return true;
}

bool Genetic::Criteria()
{
    return true;
}

bool Genetic::StartGenetic()
{
    sizeSchedule = sizePopulation * sizeST;
    schedule = new res_Schedule [sizeSchedule];
    schedulePenalty = new int [sizePopulation];
    this->CreateFirstPopulation();
    for(int i = 0; i < 1000; i++)
    {
        this->Mutation(0, sizeSchedule);
        _ChangeValue();
    }
    qDebug() << "End Genetic";
    return true;
}

