#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void slotToMainMenu();

    void on_exitMainMenu_clicked();

    void on_settingMenu_clicked();

    void on_lookDataBase_clicked();

    void on_editDataBase_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
