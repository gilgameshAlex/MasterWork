#ifndef UBD_LECTUREHALLS_H
#define UBD_LECTUREHALLS_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>

class ubd_LectureHalls
{
private:
    QSqlQuery query;

public:
    int size;

    int idHall;
    int idFaculty;
    int numberHall;
    int typeHall;
    int capacityHall;
    int codePriority;
    bool haveBoard;
    bool haveProjector;
    bool haveSocket;
    bool haveWindows;

    ubd_LectureHalls();

    void downloadFromDB_All(ubd_LectureHalls *, int);
    int getQuantityRow();
    void downloadFromDB_One(int);

    void debugData();
};

#endif // UBD_LECTUREHALLS_H
