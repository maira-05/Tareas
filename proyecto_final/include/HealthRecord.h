#ifndef HEALTHRECORD_H
#define HEALTHRECORD_H

#include <QDateTime>

class HealthRecord
{
public:
    HealthRecord();

    int id() const;
    int userId() const;
    QDateTime dateTime() const;
    double weight() const;
    int systolic() const;
    int diastolic() const;
    double glucoseLevel() const;

    void setId(int id);
    void setUserId(int userId);
    void setDateTime(const QDateTime &dt);
    void setWeight(double w);
    void setSystolic(int s);
    void setDiastolic(int d);
    void setGlucoseLevel(double g);

private:
    int m_id = 0;
    int m_userId = 0;
    QDateTime m_dateTime;
    double m_weight = 0.0;
    int m_systolic = 0;
    int m_diastolic = 0;
    double m_glucoseLevel = 0.0;
};

#endif // HEALTHRECORD_H
