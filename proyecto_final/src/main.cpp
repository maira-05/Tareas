#include <QApplication>
#include "DatabaseManager.h"
#include "LoginDialog.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager db("health.db");

    LoginDialog login(&db);
    if (login.exec() != QDialog::Accepted)
        return 0;

    int userId = login.getUserId();

    MainWindow w(userId, &db);
    w.show();

    return a.exec();
}
