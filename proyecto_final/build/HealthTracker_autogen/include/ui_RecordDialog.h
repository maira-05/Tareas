/********************************************************************************
** Form generated from reading UI file 'RecordDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDDIALOG_H
#define UI_RECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_RecordDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_2;
    QDoubleSpinBox *weightSpin;
    QLabel *label_3;
    QSpinBox *systolicSpin;
    QLabel *label_4;
    QSpinBox *diastolicSpin;
    QLabel *label_5;
    QSpinBox *glucoseSpin;
    QPushButton *saveButton;

    void setupUi(QDialog *RecordDialog)
    {
        if (RecordDialog->objectName().isEmpty())
            RecordDialog->setObjectName(QString::fromUtf8("RecordDialog"));
        formLayout = new QFormLayout(RecordDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(RecordDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dateTimeEdit = new QDateTimeEdit(RecordDialog);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dateTimeEdit);

        label_2 = new QLabel(RecordDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        weightSpin = new QDoubleSpinBox(RecordDialog);
        weightSpin->setObjectName(QString::fromUtf8("weightSpin"));

        formLayout->setWidget(1, QFormLayout::FieldRole, weightSpin);

        label_3 = new QLabel(RecordDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        systolicSpin = new QSpinBox(RecordDialog);
        systolicSpin->setObjectName(QString::fromUtf8("systolicSpin"));

        formLayout->setWidget(2, QFormLayout::FieldRole, systolicSpin);

        label_4 = new QLabel(RecordDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        diastolicSpin = new QSpinBox(RecordDialog);
        diastolicSpin->setObjectName(QString::fromUtf8("diastolicSpin"));

        formLayout->setWidget(3, QFormLayout::FieldRole, diastolicSpin);

        label_5 = new QLabel(RecordDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        glucoseSpin = new QSpinBox(RecordDialog);
        glucoseSpin->setObjectName(QString::fromUtf8("glucoseSpin"));

        formLayout->setWidget(4, QFormLayout::FieldRole, glucoseSpin);

        saveButton = new QPushButton(RecordDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        formLayout->setWidget(5, QFormLayout::FieldRole, saveButton);


        retranslateUi(RecordDialog);

        QMetaObject::connectSlotsByName(RecordDialog);
    } // setupUi

    void retranslateUi(QDialog *RecordDialog)
    {
        RecordDialog->setWindowTitle(QCoreApplication::translate("RecordDialog", "Nuevo Registro", nullptr));
        label->setText(QCoreApplication::translate("RecordDialog", "Fecha y hora:", nullptr));
        label_2->setText(QCoreApplication::translate("RecordDialog", "Peso (kg):", nullptr));
        label_3->setText(QCoreApplication::translate("RecordDialog", "Presi\303\263n Sist\303\263lica:", nullptr));
        label_4->setText(QCoreApplication::translate("RecordDialog", "Presi\303\263n Diast\303\263lica:", nullptr));
        label_5->setText(QCoreApplication::translate("RecordDialog", "Glucosa:", nullptr));
        saveButton->setText(QCoreApplication::translate("RecordDialog", "Guardar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordDialog: public Ui_RecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDDIALOG_H
