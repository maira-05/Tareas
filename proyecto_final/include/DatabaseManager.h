#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QList>
#include "HealthRecord.h"
#include "User.h"

class DatabaseManager
{
public:
    explicit DatabaseManager(const QString &path);

    bool addRecord(const HealthRecord &record);
    QList<HealthRecord> getUserRecords(int userId);

    int authenticate(const QString &username, const QString &password);

private:
    QSqlDatabase m_db;
};

#endif
