#include "createschedule.h"
#include "ui_createschedule.h"



#include "genetic.h"
#include "ubd_faculty.h"
#include "ubdc_ranks.h"

CreateSchedule::CreateSchedule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateSchedule)
{
    ui->setupUi(this);
    ;
    db = QSqlDatabase::addDatabase("QPSQL");

    QSettings settings("GatesB", "MakeMeSchedule");
    db.setHostName(settings.value("SETTING/ADDRESS_DB","").toString());
    db.setDatabaseName(settings.value("SETTING/NAME_DB","").toString());
    db.setUserName(settings.value("SETTING/USER_DB","").toString());
    db.setPassword(settings.value("SETTING/PASSWORD_DB","").toString());
    db.setPort(settings.value("SETTING/PORT_DB","").toInt());
    qDebug() << "CreateSchedule";

}

CreateSchedule::~CreateSchedule()
{
    delete ui;
}

void CreateSchedule::valueChanged()
{
    ui->progressBar->setValue(ui->progressBar->value() + 1);
}

void CreateSchedule::on_createSchedule_clicked()
{
    if (db.open())
    {
        /*int size;
        ubd_Faculty *fac = new ubd_Faculty [fac->getQuatityRow()];
        fac->downloadFromDB_All(fac);
        for(int i = 0; i < fac->getQuatityRow(); i++){
            fac[i].debugData();
        }
        ubdc_Ranks *rank = new ubdc_Ranks [rank->getQuantityRow()];
        rank->downloadFromDB_All(rank);
        for(int i = 0; i < rank->getQuantityRow(); i++){
            rank[i].debugData();
        }
        size = (new ubd_Groups)->getQuantityRow();
        ubd_Groups *gro = new ubd_Groups [size];
        gro->downloadFromDB_All(gro, 7);
        for(int i = 0; i < gro->getQuantityRow(); i++){
            gro[i].debugData();
        }*/
        Genetic gena;
        gena.setSizePopulation(ui->sizePopulation->text().toInt());
        gena.setQuatityStudyDays(ui->quantityDay->text().toInt());
        ui->progressBar->setValue(0);
        connect(&gena, SIGNAL(_ChangeValue()), this, SLOT(valueChanged()));
        gena.StartGenetic();
    }
    else
    {
        qDebug() << "Off";
    }


    db.close();
}
