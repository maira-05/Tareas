#include "RecordDialog.h"
#include "ui_RecordDialog.h"
#include <QDateTime>

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
