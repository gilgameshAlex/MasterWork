#include "ubd_subjectteacher.h"

ubd_SubjectTeacher::ubd_SubjectTeacher()
{

}

void ubd_SubjectTeacher::downloadFromDB_All(ubd_SubjectTeacher *res, int _idFaculty)
{
    query.exec("SELECT * FROM udb_SubjectTeacher WHERE idFaculty = '" + QString::number(_idFaculty) + "'");
    for(int i = 0; query.next(); i++)
    {
        res[i].idST = query.value(0).toInt();
        res[i].idFaculty = query.value(1).toInt();
        res[i].idTeacher = query.value(2).toInt();
        res[i].idSubject = query.value(3).toInt();
    }
}

void ubd_SubjectTeacher::downloadFromDB_One(int _idST)
{
    query.exec("SELECT * FROM udb_SubjectTeacher WHERE idST = '" + QString::number(_idST) + "'");
    while (query.next())
    {
        this-> idST = query.value(0).toInt();
        this-> idFaculty = query.value(1).toInt();
        this-> idTeacher = query.value(2).toInt();
        this-> idSubject = query.value(3).toInt();
    }
}

int ubd_SubjectTeacher::getQuantityRow()
{
    query.exec("SELECT * FROM udb_SubjectTeacher");
    this->size = query.size();
    return query.size();
}

void ubd_SubjectTeacher::debugData()
{
    qDebug() << "udb_SubjectTeacher";
    qDebug() << idST;
    qDebug() << idFaculty;
    qDebug() << idTeacher;
    qDebug() << idSubject;
    qDebug() << "____________";
}
