#include "ubd_faculty.h"


ubd_Faculty::ubd_Faculty()
{

}

void ubd_Faculty::downloadFromDB_All(ubd_Faculty *res)
{
    query.exec("SELECT * FROM udb_Faculty");
    for(int i = 0; query.next(); i++)
    {
        res[i].idFaculty = query.value(0).toInt();
        res[i].nameFaculty = query.value(1).toString();
        res[i].codeFaculty = query.value(2).toInt();
        res[i].dean = query.value(3).toString();
        res[i].adrFaculty = query.value(4).toString();
        res[i].phoneNumber = query.value(5).toString();
    }
}

void ubd_Faculty::downloadFromDB_One(int codeFaculty)
{
   query.exec("SELECT * FROM udb_Faculty WHERE codeFaculty = '" + QString::number(codeFaculty) + "'");
   while (query.next())
   {
       this->idFaculty = query.value(0).toInt();
       this->nameFaculty = query.value(1).toString();
       this->codeFaculty = query.value(2).toInt();
       this->dean = query.value(3).toString();
       this->adrFaculty = query.value(4).toString();
       this->phoneNumber = query.value(5).toString();
   }
}

int ubd_Faculty::getQuatityRow()
{
    query.exec("SELECT * FROM udb_Faculty");

    return query.size();
}

void ubd_Faculty::debugData()
{
    qDebug() << "udb_Faculty";
    qDebug() << idFaculty;
    qDebug() << nameFaculty;
    qDebug() << codeFaculty;
    qDebug() << dean;
    qDebug() << adrFaculty;
    qDebug() << phoneNumber;
    qDebug() << "_______________";
}
