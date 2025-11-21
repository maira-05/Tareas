#ifndef HEALTHANALYZER_H
#define HEALTHANALYZER_H

#include <QVector>
#include "HealthRecord.h"

class HealthAnalyzer
{
public:
    static double promedioSistolica(const QVector<HealthRecord> &records);
    static double promedioDiastolica(const QVector<HealthRecord> &records);
    static double promedioGlucosa(const QVector<HealthRecord> &records);
};

#endif // HEALTHANALYZER_H
