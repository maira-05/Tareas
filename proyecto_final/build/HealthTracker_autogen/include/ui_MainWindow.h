/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QTableView *tableView;
    QLabel *labelStats;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *labelHeight;
    QLineEdit *lineEditHeight;
    QVBoxLayout *vboxLayout2;
    QLabel *labelWeight;
    QLineEdit *lineEditWeight;
    QVBoxLayout *vboxLayout3;
    QLabel *labelBMI;
    QHBoxLayout *hboxLayout1;
    QPushButton *addButton;
    QPushButton *exportButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        vboxLayout = new QVBoxLayout(centralwidget);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        vboxLayout->addWidget(tableView);

        labelStats = new QLabel(centralwidget);
        labelStats->setObjectName(QString::fromUtf8("labelStats"));

        vboxLayout->addWidget(labelStats);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        labelHeight = new QLabel(centralwidget);
        labelHeight->setObjectName(QString::fromUtf8("labelHeight"));

        vboxLayout1->addWidget(labelHeight);

        lineEditHeight = new QLineEdit(centralwidget);
        lineEditHeight->setObjectName(QString::fromUtf8("lineEditHeight"));

        vboxLayout1->addWidget(lineEditHeight);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        labelWeight = new QLabel(centralwidget);
        labelWeight->setObjectName(QString::fromUtf8("labelWeight"));

        vboxLayout2->addWidget(labelWeight);

        lineEditWeight = new QLineEdit(centralwidget);
        lineEditWeight->setObjectName(QString::fromUtf8("lineEditWeight"));

        vboxLayout2->addWidget(lineEditWeight);


        hboxLayout->addLayout(vboxLayout2);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        labelBMI = new QLabel(centralwidget);
        labelBMI->setObjectName(QString::fromUtf8("labelBMI"));

        vboxLayout3->addWidget(labelBMI);


        hboxLayout->addLayout(vboxLayout3);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        hboxLayout1->addWidget(addButton);

        exportButton = new QPushButton(centralwidget);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));

        hboxLayout1->addWidget(exportButton);


        vboxLayout->addLayout(hboxLayout1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Rastreador de Salud", nullptr));
        labelStats->setText(QCoreApplication::translate("MainWindow", "Estad\303\255sticas:", nullptr));
        labelHeight->setText(QCoreApplication::translate("MainWindow", "Altura (cm):", nullptr));
        labelWeight->setText(QCoreApplication::translate("MainWindow", "Peso (kg):", nullptr));
        labelBMI->setText(QCoreApplication::translate("MainWindow", "IMC: --", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Agregar Registro", nullptr));
        exportButton->setText(QCoreApplication::translate("MainWindow", "Exportar CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
