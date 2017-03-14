#ifndef UBDC_RANKS_H
#define UBDC_RANKS_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>


class ubdc_Ranks
{
public:
    int idRank;
    QString rankName;
    QString cutName;
    int importance;

    ubdc_Ranks();

    void downloadFromDB_All(ubdc_Ranks *);
    int getQuantityRow();
    void downloadFromDB_One(int);

    void debugData();
};

#endif // UBDC_RANKS_H
