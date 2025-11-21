#include "HealthAnalyzer.h"

double HealthAnalyzer::promedioSistolica(const QVector<HealthRecord> &records)
{
    if (records.isEmpty()) return 0;

    double suma = 0;
    for (const auto &r : records)
        suma += r.systolic();

    return suma / records.size();
}

double HealthAnalyzer::promedioDiastolica(const QVector<HealthRecord> &records)
{
    if (records.isEmpty()) return 0;

    double suma = 0;
    for (const auto &r : records)
        suma += r.diastolic();

    return suma / records.size();
}

double HealthAnalyzer::promedioGlucosa(const QVector<HealthRecord> &records)
{
    if (records.isEmpty()) return 0;

    double suma = 0;
    for (const auto &r : records)
        suma += r.glucoseLevel();

    return suma / records.size();
}
