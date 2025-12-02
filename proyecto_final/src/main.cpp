#include <QApplication>
#include "../include/LoginDialog.h"
#include "../include/MainWindow.h"
#include "../include/DatabaseManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Crear base de datos
    DatabaseManager db;

    // --- Mostrar login ---
    LoginDialog loginDialog(&db);   // ✔ PASAR BASE DE DATOS
    if (loginDialog.exec() != QDialog::Accepted) {
        return 0; // Usuario canceló
    }

    int userId = loginDialog.getUserId();

    // --- Abrir ventana principal ---
    MainWindow w(userId, &db);     // ✔ PASAR USERID Y DB
    w.show();

    return a.exec();
}
