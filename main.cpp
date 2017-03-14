#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOrganizationName("GatesB");
    QApplication::setOrganizationDomain("vk.com/alexbon");
    QApplication::setApplicationName("AIS University");
    MainMenu w;
    w.showMaximized();
    w.setFocus();

    return a.exec();
}
