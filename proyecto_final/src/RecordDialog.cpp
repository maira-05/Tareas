#include "RecordDialog.h"
#include "ui_RecordDialog.h"
#include <QDateTime>

RecordDialog::RecordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RecordDialog)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

RecordDialog::~RecordDialog()
{
    delete ui;
}

HealthRecord RecordDialog::getRecord() const
{
    return m_record;
}

void RecordDialog::on_saveButton_clicked()
{
    m_record.dateTime = ui->dateTimeEdit->dateTime();
    m_record.weight = ui->weightSpin->value();
    m_record.systolic = ui->systolicSpin->value();
    m_record.diastolic = ui->diastolicSpin->value();
    m_record.glucoseLevel = ui->glucoseSpin->value();

    accept();
}
