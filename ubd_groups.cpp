#include "ubd_groups.h"


ubd_Groups::ubd_Groups()
{

}

void ubd_Groups::downloadFromDB_All(ubd_Groups *res, int _idFaculty)
{
    query.exec("SELECT * FROM udb_Groups WHERE idFaculty = '" + QString::number(_idFaculty) + "'");
    for(int i = 0; query.next(); i++)
    {
        res[i].idGroup = query.value(0).toInt();
        res[i].idFaculty = query.value(1).toInt();
        res[i].numberGroup = query.value(2).toInt();
        res[i].quantityStudents = query.value(3).toInt();
        res[i].trend = query.value(4).toString();
    }
}

void ubd_Groups::downloadFromDB_One(int idGroup)
{
    query.exec("SELECT * FROM udb_Groups WHERE idGroup = '" + QString::number(idGroup) + "'");
    while (query.next())
    {
        this-> idGroup= query.value(0).toInt();
        this-> idFaculty = query.value(1).toInt();
        this-> numberGroup = query.value(2).toInt();
        this-> quantityStudents = query.value(3).toInt();
        this-> trend = query.value(4).toString();
    }
}

int ubd_Groups::getQuantityRow()
{
    query.exec("SELECT * FROM udb_Groups");
    this->size = query.size();
    return query.size();
}

void ubd_Groups::debugData()
{
    qDebug() << "udb_Groups";
    qDebug() << idGroup;
    qDebug() << idFaculty;
    qDebug() << numberGroup;
    qDebug() << quantityStudents;
    qDebug() << trend;
    qDebug() << "____________";
}
