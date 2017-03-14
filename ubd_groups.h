#ifndef UBD_GROUPS_H
#define UBD_GROUPS_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>

class ubd_Groups
{
private:
    QSqlQuery query;

public:
    int size;
    int idGroup;
    int idFaculty;
    int numberGroup;
    int quantityStudents;
    QString trend;

    ubd_Groups();

    void downloadFromDB_All(ubd_Groups *, int);
    int getQuantityRow();
    void downloadFromDB_One(int);

    void debugData();
};

#endif // UBD_GROUPS_H
