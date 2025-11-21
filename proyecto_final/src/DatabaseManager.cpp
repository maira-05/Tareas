#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>

DatabaseManager::DatabaseManager() {}

bool DatabaseManager::open(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "Error opening DB:" << m_db.lastError();
        return false;
    }
    return true;
}

bool DatabaseManager::createSchema()
{
    QSqlQuery q;

    q.exec("CREATE TABLE IF NOT EXISTS users ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT,"
           "username TEXT UNIQUE,"
           "password_hash TEXT,"
           "salt TEXT)");

    q.exec("CREATE TABLE IF NOT EXISTS health_records ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT,"
           "user_id INTEGER,"
           "date_time TEXT,"
           "weight REAL,"
           "systolic INTEGER,"
           "diastolic INTEGER,"
           "glucose_level REAL)");

    return true;
}

QString DatabaseManager::generateSalt() const
{
    return QString::number(qrand());
}

QString DatabaseManager::hashPassword(const QString &password, const QString &salt) const
{
    QByteArray data = (salt + password).toUtf8();
    return QCryptographicHash::hash(data, QCryptographicHash::Sha256).toHex();
}

bool DatabaseManager::createUser(const QString &username, const QString &password)
{
    QString salt = generateSalt();
    QString hashed = hashPassword(password, salt);

    QSqlQuery q;
    q.prepare("INSERT INTO users(username, password_hash, salt) VALUES(?,?,?)");
    q.addBindValue(username);
    q.addBindValue(hashed);
    q.addBindValue(salt);

    return q.exec();
}

User DatabaseManager::authenticate(const QString &username, const QString &password)
{
    QSqlQuery q;
    q.prepare("SELECT id, password_hash, salt FROM users WHERE username=?");
    q.addBindValue(username);
    q.exec();

    if (q.next()) {
        int id = q.value(0).toInt();
        QString storedHash = q.value(1).toString();
        QString salt = q.value(2).toString();

        QString incomingHash = hashPassword(password, salt);

        if (incomingHash == storedHash)
            return User(id, username);
    }

    return User();
}

bool DatabaseManager::addRecord(const HealthRecord &r)
{
    QSqlQuery q;
    q.prepare("INSERT INTO health_records(user_id, date_time, weight, systolic, diastolic, glucose_level) "
              "VALUES(?,?,?,?,?,?)");

    q.addBindValue(r.userId());
    q.addBindValue(r.dateTime().toString("yyyy-MM-dd HH:mm:ss"));
    q.addBindValue(r.weight());
    q.addBindValue(r.systolic());
    q.addBindValue(r.diastolic());
    q.addBindValue(r.glucoseLevel());

    return q.exec();
}

QVector<HealthRecord> DatabaseManager::getRecordsForUser(int userId)
{
    QVector<HealthRecord> records;

    QSqlQuery q;
    q.prepare("SELECT id, date_time, weight, systolic, diastolic, glucose_level "
              "FROM health_records WHERE user_id=? ORDER BY date_time ASC");

    q.addBindValue(userId);
    q.exec();

    while (q.next()) {
        HealthRecord r;
        r.setId(q.value(0).toInt());
        r.setUserId(userId);
        r.setDateTime(QDateTime::fromString(q.value(1).toString(), "yyyy-MM-dd HH:mm:ss"));
        r.setWeight(q.value(2).toDouble());
        r.setSystolic(q.value(3).toInt());
        r.setDiastolic(q.value(4).toInt());
        r.setGlucoseLevel(q.value(5).toDouble());
        records.append(r);
    }

    return records;
}
