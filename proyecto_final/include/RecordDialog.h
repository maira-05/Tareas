#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>
#include "HealthRecord.h"

namespace Ui {
class RecordDialog;
}

class RecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RecordDialog(QWidget *parent = nullptr);
    ~RecordDialog();

    HealthRecord getRecord() const;

private slots:
    void on_saveButton_clicked();

private:
    Ui::RecordDialog *ui;
    HealthRecord m_record;
};

#endif // RECORDDIALOG_H
