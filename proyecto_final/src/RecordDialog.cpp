#include "RecordDialog.h"
#include "ui_RecordDialog.h"

RecordDialog::RecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RecordDialog)
{
    ui->setupUi(this);
}

RecordDialog::~RecordDialog()
{
    delete ui;
}

void RecordDialog::on_saveButton_clicked()
{
    // ✔️ FECHA: Usa dateTimeEdit (el que SÍ existe en tu UI)
    m_record.setDateTime(ui->dateTimeEdit->dateTime());

    // ✔️ PESO
    m_record.setWeight(ui->weightSpin->value());

    // ✔️ PRESIÓN ARTERIAL
    m_record.setSystolic(ui->systolicSpin->value());
    m_record.setDiastolic(ui->diastolicSpin->value());

    // ✔️ GLUCOSA: usa setGlucoseLevel() (el que existe)
    m_record.setGlucoseLevel(ui->glucoseSpin->value());

    accept();
}

HealthRecord RecordDialog::getRecord() const
{
    return m_record;
}
