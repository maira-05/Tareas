#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "DatabaseManager.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(DatabaseManager* db, QWidget *parent = nullptr);
    ~LoginDialog();

    int getUserId() const;

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginDialog *ui;
    DatabaseManager* m_db;
    int m_userId = -1;
};

#endif // LOGINDIALOG_H
