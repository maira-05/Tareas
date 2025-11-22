#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(DatabaseManager *db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
    , m_db(db)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

int LoginDialog::getUserId() const
{
    return m_userId;
}

void LoginDialog::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    int id = m_db->authenticate(username, password);

    if (id != -1) {
        m_userId = id;
        accept();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o contraseña incorrectos");
    }
}
