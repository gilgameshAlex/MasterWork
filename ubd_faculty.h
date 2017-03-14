#ifndef UBD_FACULTY_H
#define UBD_FACULTY_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>



class ubd_Faculty
{
private:
    QSqlQuery query;

public:
    int idFaculty;
    QString nameFaculty;
    int codeFaculty;
    QString dean;
    QString adrFaculty;
    QString phoneNumber;

    ubd_Faculty();

    void downloadFromDB_All(ubd_Faculty *);
    int getQuatityRow();
    void downloadFromDB_One(int);

    void debugData();
};

#endif // UBD_FACULTY_H
