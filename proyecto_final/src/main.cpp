#include <QApplication>
#include "MainWindow.h"
#include "LoginDialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // --- Mostrar login ---
    LoginDialog loginDialog;
    if (loginDialog.exec() != QDialog::Accepted) {
        return 0; // Usuario canceló
    }

    // --- Crear y mostrar la ventana principal ---
    MainWindow w;
    w.show();

    return app.exec();
}
