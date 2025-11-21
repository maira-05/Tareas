#include "HealthRecord.h"

HealthRecord::HealthRecord()
    : m_id(-1),
      m_userId(-1),
      m_weight(0),
      m_systolic(0),
      m_diastolic(0),
      m_glucoseLevel(0)
{}

int HealthRecord::id() const { return m_id; }
int HealthRecord::userId() const { return m_userId; }
QDateTime HealthRecord::dateTime() const { return m_dateTime; }
double HealthRecord::weight() const { return m_weight; }
int HealthRecord::systolic() const { return m_systolic; }
int HealthRecord::diastolic() const { return m_diastolic; }
double HealthRecord::glucoseLevel() const { return m_glucoseLevel; }

void HealthRecord::setId(int id) { m_id = id; }
void HealthRecord::setUserId(int userId) { m_userId = userId; }
void HealthRecord::setDateTime(const QDateTime &dt) { m_dateTime = dt; }
void HealthRecord::setWeight(double w) { m_weight = w; }
void HealthRecord::setSystolic(int s) { m_systolic = s; }
void HealthRecord::setDiastolic(int d) { m_diastolic = d; }
void HealthRecord::setGlucoseLevel(double g) { m_glucoseLevel = g; }
