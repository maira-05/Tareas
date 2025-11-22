#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "RecordDialog.h"
#include "CSVExporter.h"
#include <QMessageBox>

MainWindow::MainWindow(int userId, DatabaseManager *db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_db(db)
    , m_userId(userId)
{
    ui->setupUi(this);

    m_model = new RecordsModel(m_db, m_userId, this);
    ui->tableView->setModel(m_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    RecordDialog dlg;
    if (dlg.exec() == QDialog::Accepted) {

        HealthRecord record = dlg.getRecord();
        record.userId = m_userId;

        m_db->addRecord(record);
        m_model->reload();
    }
}

void MainWindow::on_exportButton_clicked()
{
    CSVExporter exporter;
    exporter.exportUserRecords(m_db, m_userId, "reporte.csv");

    QMessageBox::information(this, "Éxito", "Archivo CSV creado correctamente");
}
