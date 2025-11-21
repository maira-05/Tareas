#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QVector>
#include "User.h"
#include "HealthRecord.h"

class DatabaseManager
{
public:
    DatabaseManager();
    bool open(const QString &path);
    bool createSchema();

    // Usuarios
    bool createUser(const QString &username, const QString &password);
    User authenticate(const QString &username, const QString &password);

    // Registros de salud
    bool addRecord(const HealthRecord &record);
    QVector<HealthRecord> getRecordsForUser(int userId);

private:
    QSqlDatabase m_db;

    QString hashPassword(const QString &password, const QString &salt) const;
    QString generateSalt() const;
};

#endif // DATABASEMANAGER_H
