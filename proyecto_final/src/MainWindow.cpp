#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "RecordDialog.h"
#include "CSVExporter.h"
#include <QMessageBox>
#include <QIcon>

MainWindow::MainWindow(int userId, DatabaseManager *db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_userId(userId)
    , m_db(db)
{
    ui->setupUi(this);

    // ✔️ Establecer ícono de la aplicación
    setWindowIcon(QIcon(":/icon.jpg"));

    // ✔️ Modelo de registros
    m_model = new RecordsModel(m_db, m_userId, this);
    ui->tableView->setModel(m_model);
    m_model->reload();

    // ====================================================
    // ✔️ Cálculo de estadísticas
    // ====================================================
    QList<HealthRecord> list = m_db->getUserRecords(m_userId);

    if (!list.isEmpty())
    {
        double suma = 0;

        // ⚠️ reemplazo de getBloodPressure()
        double minBP = (list.first().systolic() + list.first().diastolic()) / 2.0;
        double maxBP = minBP;

        for (const auto &r : list)
        {
            // ⚠️ reemplazo de getBloodPressure()
            double bp = (r.systolic() + r.diastolic()) / 2.0;
            suma += bp;

            if (bp < minBP) minBP = bp;
            if (bp > maxBP) maxBP = bp;
        }

        double promedio = suma / list.size();

        // ✔️ Tendencia (primer vs último registro)
        QString tendencia;

        // ⚠️ reemplazo de getBloodPressure()
        double inicial = (list.first().systolic() + list.first().diastolic()) / 2.0;
        double finalBP = (list.last().systolic() + list.last().diastolic()) / 2.0;

        if (finalBP > inicial)
            tendencia = "La presión arterial ha aumentado.";
        else if (finalBP < inicial)
            tendencia = "La presión arterial ha disminuido.";
        else
            tendencia = "La presión arterial se mantiene estable.";

        // ✔️ Mostrar estadísticas en el label
        ui->labelStats->setText(
            QString("Promedio: %1   |   Mínimo: %2   |   Máximo: %3   |   %4")
            .arg(promedio)
            .arg(minBP)
            .arg(maxBP)
            .arg(tendencia)
        );
    }
    else
    {
        ui->labelStats->setText("No hay datos disponibles.");
    }
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
        record.setUserId(m_userId);

        m_db->addRecord(record);
        m_model->reload();

        // ====================================================
        // ✔️ Recalcular estadísticas después de agregar registro
        // ====================================================
        QList<HealthRecord> list = m_db->getUserRecords(m_userId);

        if (!list.isEmpty())
        {
            double suma = 0;

            // ⚠️ reemplazo de getBloodPressure()
            double minBP = (list.first().systolic() + list.first().diastolic()) / 2.0;
            double maxBP = minBP;

            for (const auto &r : list)
            {
                // ⚠️ reemplazo de getBloodPressure()
                double bp = (r.systolic() + r.diastolic()) / 2.0;
                suma += bp;

                if (bp < minBP) minBP = bp;
                if (bp > maxBP) maxBP = bp;
            }

            double promedio = suma / list.size();

            // Tendencia simple
            QString tendencia;

            // ⚠️ reemplazo de getBloodPressure()
            double inicial = (list.first().systolic() + list.first().diastolic()) / 2.0;
            double finalBP = (list.last().systolic() + list.last().diastolic()) / 2.0;

            if (finalBP > inicial)
                tendencia = "La presión arterial ha aumentado.";
            else if (finalBP < inicial)
                tendencia = "La presión arterial ha disminuido.";
            else
                tendencia = "La presión arterial se mantiene estable.";

            ui->labelStats->setText(
                QString("Promedio: %1   |   Mínimo: %2   |   Máximo: %3   |   %4")
                .arg(promedio)
                .arg(minBP)
                .arg(maxBP)
                .arg(tendencia)
            );
        }
        else
        {
            ui->labelStats->setText("No hay datos disponibles.");
        }
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
