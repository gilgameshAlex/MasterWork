#include "settingmenu.h"
#include "ui_settingmenu.h"

#include <QSettings>
#include <QMessageBox>

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>

SettingMenu::SettingMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingMenu)
{
    ui->setupUi(this);

    QSettings settings("GatesB", "MakeMeSchedule");
    ui->adrDB->setText(settings.value("SETTING/ADDRESS_DB","").toString());
    ui->portDB->setText(settings.value("SETTING/PORT_DB","").toString());
    ui->nameDB->setText(settings.value("SETTING/NAME_DB","").toString());
    ui->userDB->setText(settings.value("SETTING/USER_DB","").toString());
    ui->passDB->setText(settings.value("SETTING/PASSWORD_DB","").toString());

    ui->adrDB->setPlaceholderText("address database...");
    ui->portDB->setPlaceholderText("port database...");
    ui->nameDB->setPlaceholderText("name database...");
    ui->userDB->setPlaceholderText("user database...");
    ui->passDB->setPlaceholderText("password database...");
    connect(ui->mainMenu, SIGNAL(clicked()), this, SIGNAL(signalSettingToMainMenu()));
}

SettingMenu::~SettingMenu()
{
    delete ui;
}

void SettingMenu::on_exitSetting_clicked()
{

    this->close();
}

void SettingMenu::on_mainMenu_clicked()
{
    this->setVisible(false);
}


void SettingMenu::on_checkConnectDB_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    QSettings settings("GatesB", "MakeMeSchedule");

    ui->adrDB->setPlaceholderText("address DB...");
    ui->portDB->setPlaceholderText("port DB...");
    ui->userDB->setPlaceholderText("user DB...");
    ui->passDB->setPlaceholderText("password DB");

    db.setHostName(settings.value("SETTING/ADDRESS_DB","").toString());
    db.setDatabaseName(settings.value("SETTING/NAME_DB","").toString());
    db.setUserName(settings.value("SETTING/USER_DB","").toString());
    db.setPassword(settings.value("SETTING/PASSWORD_DB","").toString());
    db.setPort(settings.value("SETTING/PORT_DB","").toInt());
    if (db.open())
    {
        ui->statusDB->setText("ON");
        ui->statusDB->setStyleSheet("QLabel { color : green; }");
    }
    else
    {
        ui->statusDB->setText("OFF");
        ui->statusDB->setStyleSheet("QLabel { color : red; }");
    }
    db.close();
}

void SettingMenu::on_saveChange_clicked()
{
    QSettings settings("GatesB", "MakeMeSchedule");
    settings.setValue("SETTING/ADDRESS_DB",ui->adrDB->text());
    settings.setValue("SETTING/PORT_DB",ui->portDB->text());
    settings.setValue("SETTING/NAME_DB",ui->nameDB->text());
    settings.setValue("SETTING/USER_DB",ui->userDB->text());
    settings.setValue("SETTING/PASSWORD_DB",ui->passDB->text());
    settings.sync();
}

void SettingMenu::on_clearFields_clicked()
{
    ui->adrDB->clear();
    ui->portDB->clear();
    ui->nameDB->clear();
    ui->userDB->clear();
    ui->passDB->clear();

    QSettings settings("GatesB", "MakeMeSchedule");
    settings.setValue("SETTING/ADDRESS_DB", "");
    settings.setValue("SETTING/PORT_DB", "");
    settings.setValue("SETTING/NAME_DB", "");
    settings.setValue("SETTING/USER_DB", "");
    settings.setValue("SETTING/PASSWORD_DB", "");
    settings.sync();
}
