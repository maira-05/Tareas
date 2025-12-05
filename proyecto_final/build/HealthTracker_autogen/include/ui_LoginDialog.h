/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *vboxLayout;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        vboxLayout = new QVBoxLayout(LoginDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        usernameEdit = new QLineEdit(LoginDialog);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        vboxLayout->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(LoginDialog);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        vboxLayout->addWidget(passwordEdit);

        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        vboxLayout->addWidget(loginButton);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Login", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Usuario", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Contrase\303\261a", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginDialog", "Iniciar Sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
