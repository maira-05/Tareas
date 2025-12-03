#ifndef CSVEXPORTER_H
#define CSVEXPORTER_H

#include "HealthRecord.h"
#include <QVector>
#include <QString>

class CSVExporter
{
public:
    bool exportRecords(const QVector<HealthRecord> &records,
                       const QString &filePath);
};

#endif
