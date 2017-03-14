#include "ubdc_ranks.h"

ubdc_Ranks::ubdc_Ranks()
{

}

void ubdc_Ranks::downloadFromDB_All(ubdc_Ranks * res)
{
   QSqlQuery query;
   query.exec("SELECT * FROM udbc_Ranks");
   for(int i = 0; query.next(); i++)
   {
       res[i].idRank = query.value(0).toInt();
       res[i].rankName = query.value(1).toString();
       res[i].cutName = query.value(2).toString();
       res[i].importance = query.value(3).toInt();
   }
}

void ubdc_Ranks::downloadFromDB_One(int idRank)
{
   QSqlQuery query;
   query.exec("SELECT * FROM udbc_Ranks WHERE idRank = '" + QString::number(idRank) + "'");
   while (query.next())
   {
       this->idRank = query.value(0).toInt();
       this->rankName = query.value(1).toString();
       this->cutName = query.value(2).toString();
       this->importance = query.value(3).toInt();
   }
}

int ubdc_Ranks::getQuantityRow()
{
    QSqlQuery query;
    query.exec("SELECT * FROM udbc_Ranks");
    qDebug() << "Size Rank -> "<<query.size();
    return query.size();
}

void ubdc_Ranks::debugData()
{
    qDebug() << "____RANK____";
    qDebug() << idRank;
    qDebug() << rankName;
    qDebug() << cutName;
    qDebug() << importance;
    qDebug() << "____________";
}
