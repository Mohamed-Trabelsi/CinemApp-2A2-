#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notificationn::notificationn()
{

}

void notificationn::notificationC()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("/new/prefix1/cinemApp.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","ajout avec succés ",QSystemTrayIcon::Information,15000);
}
void notificationn::notificationS()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("/new/prefix1/cinemApp.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","suppression avec succés ",QSystemTrayIcon::Information,15000);
}
