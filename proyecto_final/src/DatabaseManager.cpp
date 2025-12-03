#include "../include/DatabaseManager.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
        qDebug() << "No se pudo abrir la base de datos";
}

bool DatabaseManager::addRecord(const HealthRecord &record)
{
    QSqlQuery query;
    query.prepare("INSERT INTO records (user_id, datetime, weight, systolic, diastolic, glucose) "
                  "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(record.userId());
    query.addBindValue(record.dateTime());
    query.addBindValue(record.weight());
    query.addBindValue(record.systolic());
    query.addBindValue(record.diastolic());
    query.addBindValue(record.glucoseLevel());
    return query.exec();
}

QList<HealthRecord> DatabaseManager::getUserRecords(int userId)
{
    QList<HealthRecord> list;
    QSqlQuery q;
    q.prepare("SELECT id, datetime, weight, systolic, diastolic, glucose FROM records WHERE user_id = ?");
    q.addBindValue(userId);
    q.exec();

    while (q.next()) {
        HealthRecord r;
        r.setId(q.value(0).toInt());
        r.setUserId(userId);
        r.setDateTime(q.value(1).toDateTime());
        r.setWeight(q.value(2).toDouble());
        r.setSystolic(q.value(3).toInt());
        r.setDiastolic(q.value(4).toInt());
        r.setGlucoseLevel(q.value(5).toDouble());
        list.append(r);
    }

    return list;
}

int DatabaseManager::authenticate(const QString &username, const QString &password)
{
    QSqlQuery q;
    q.prepare("SELECT id FROM users WHERE username = ? AND password = ?");
    q.addBindValue(username);
    q.addBindValue(password);
    q.exec();

    if (q.next())
        return q.value(0).toInt();

    return -1;
}
