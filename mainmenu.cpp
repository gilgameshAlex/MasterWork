#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "settingmenu.h"
#include "lookdatabase.h"
#include "createschedule.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_exitMainMenu_clicked()
{
    this->close();
}

void MainMenu::on_settingMenu_clicked()
{
    this->setVisible(false);
    SettingMenu *settingMenu = new SettingMenu;
    settingMenu->setGeometry(this->geometry());
    connect(settingMenu, SIGNAL(signalSettingToMainMenu()), this, SLOT(slotToMainMenu()));
    settingMenu->show();
    settingMenu->setFocus();
}

void MainMenu::slotToMainMenu()
{
    this->setVisible(true);
    this->setFocus();
}

void MainMenu::on_lookDataBase_clicked()
{
    this->setVisible(false);
    LookDataBase *lookBD = new LookDataBase;
    lookBD->setGeometry(this->geometry());
    connect(lookBD, SIGNAL(signalSettingToMainMenu()), this, SLOT(slotToMainMenu()));
    lookBD->show();
    lookBD->setFocus();
}

void MainMenu::on_editDataBase_clicked()
{
    this->setVisible(false);
    CreateSchedule *editDB  = new CreateSchedule;
    editDB->setGeometry(this->geometry());
    editDB->show();
    editDB->setFocus();
}
