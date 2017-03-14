#ifndef UBD_SUBJECTTEACHER_H
#define UBD_SUBJECTTEACHER_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>

class ubd_SubjectTeacher
{
private:
    QSqlQuery query;
public:
    int size;

    int idST;
    int idFaculty;
    int idTeacher;
    int idSubject;

    ubd_SubjectTeacher();

    void downloadFromDB_All(ubd_SubjectTeacher *, int);
    int getQuantityRow();
    void downloadFromDB_One(int);

    void debugData();
};

#endif // UBD_SUBJECTTEACHER_H
