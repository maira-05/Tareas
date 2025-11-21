#ifndef HEALTHRECORD_H
#define HEALTHRECORD_H

#include <QString>
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
    int m_id;
    int m_userId;
    QDateTime m_dateTime;
    double m_weight;
    int m_systolic;
    int m_diastolic;
    double m_glucoseLevel;
};

#endif // HEALTHRECORD_H
