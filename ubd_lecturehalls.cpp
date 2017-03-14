#include "ubd_lecturehalls.h"

ubd_LectureHalls::ubd_LectureHalls()
{

}

void ubd_LectureHalls::downloadFromDB_All(ubd_LectureHalls *res, int _idFaculty)
{
    query.exec("SELECT * FROM udb_LectureHalls WHERE idFaculty = '" + QString::number(_idFaculty) + "'");
    for(int i = 0; query.next(); i++)
    {
        res[i].idHall = query.value(0).toInt();
        res[i].idFaculty = query.value(1).toInt();
        res[i].numberHall = query.value(2).toInt();
        res[i].typeHall = query.value(3).toInt();
        res[i].codePriority = query.value(4).toInt();
        res[i].haveBoard = query.value(5).toBool();
        res[i].haveProjector = query.value(6).toBool();
        res[i].haveSocket = query.value(7).toBool();
        res[i].haveWindows = query.value(8).toBool();
    }
}

void ubd_LectureHalls::downloadFromDB_One(int _idHall)
{
    query.exec("SELECT * FROM udb_LectureHalls WHERE idHall = '" + QString::number(_idHall) + "'");
    while (query.next())
    {
        this-> idHall = query.value(0).toInt();
        this-> idFaculty = query.value(1).toInt();
        this-> numberHall = query.value(2).toInt();
        this-> typeHall = query.value(3).toInt();
        this-> codePriority = query.value(4).toInt();
        this-> haveBoard = query.value(5).toBool();
        this-> haveProjector = query.value(6).toBool();
        this-> haveSocket = query.value(7).toBool();
        this-> haveWindows = query.value(8).toBool();
    }
}

int ubd_LectureHalls::getQuantityRow()
{
    query.exec("SELECT * FROM udb_LectureHalls");
    this->size = query.size();
    return query.size();
}

void ubd_LectureHalls::debugData()
{
    qDebug() << "udb_LectureHalls";
    qDebug() << idHall;
    qDebug() << idFaculty;
    qDebug() << numberHall;
    qDebug() << typeHall;
    qDebug() << codePriority;
    qDebug() << haveBoard;
    qDebug() << haveProjector;
    qDebug() << haveSocket;
    qDebug() << haveWindows;
    qDebug() << "____________";
}
