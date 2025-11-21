#ifndef CSVEXPORTER_H
#define CSVEXPORTER_H

#include <QString>
#include <QVector>
#include "HealthRecord.h"

class CSVExporter
{
public:
    static bool exportRecords(const QVector<HealthRecord> &records, const QString &filePath);
};

#endif // CSVEXPORTER_H
