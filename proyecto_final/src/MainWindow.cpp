#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "RecordDialog.h"
#include "CSVExporter.h"

MainWindow::MainWindow(int userId, DatabaseManager *db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_userId(userId)
    , m_db(db)
{
    ui->setupUi(this);

    m_model = new RecordsModel(m_db, m_userId, this);
    ui->tableView->setModel(m_model);
    m_model->reload();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    RecordDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted)
    {
        HealthRecord record = dlg.getRecord();
        record.setUserId(m_userId);   // ✔️ CORRECTO

        m_db->addRecord(record);
        m_model->reload();
    }
}

void MainWindow::on_exportButton_clicked()
{
    CSVExporter exporter;

    QList<HealthRecord> records = m_db->getUserRecords(m_userId);
    QVector<HealthRecord> vec = records.toVector();

    if (exporter.exportRecords(vec, "reporte.csv"))
        QMessageBox::information(this, "Exportación", "Archivo exportado correctamente.");
    else
        QMessageBox::warning(this, "Error", "No se pudo exportar.");
}
