#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification::notificationC()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/USER/Desktop/notif"));

    notifyIcon->show();
    notifyIcon->showMessage("Attention ","ajout effectué",QSystemTrayIcon::Information,15000);
}
