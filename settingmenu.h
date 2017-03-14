#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QMainWindow>
#include "mainmenu.h"

namespace Ui {
class SettingMenu;
}

class SettingMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingMenu(QWidget *parent = 0);
    ~SettingMenu();

private slots:
    void on_exitSetting_clicked();

    void on_mainMenu_clicked();

    void on_checkConnectDB_clicked();

    void on_saveChange_clicked();

    void on_clearFields_clicked();

private:
    Ui::SettingMenu *ui;

signals:
    void signalSettingToMainMenu();
};

#endif // SETTINGMENU_H
