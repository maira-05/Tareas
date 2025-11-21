#include "CSVExporter.h"
#include <QFile>
#include <QTextStream>

bool CSVExporter::exportRecords(const QVector<HealthRecord> &records, const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "id,userId,dateTime,weight,systolic,diastolic,glucose\n";

    for (const auto &r : records) {
        out << r.id() << ","
            << r.userId() << ","
            << r.dateTime().toString("yyyy-MM-dd HH:mm:ss") << ","
            << r.weight() << ","
            << r.systolic() << ","
            << r.diastolic() << ","
            << r.glucoseLevel() << "\n";
    }

    return true;
}
