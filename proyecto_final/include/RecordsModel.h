#ifndef RECORDSMODEL_H
#define RECORDSMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "DatabaseManager.h"

class RecordsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    RecordsModel(DatabaseManager *db, int userId, QObject *parent = nullptr);

    int rowCount(const QModelIndex&) const override;
    int columnCount(const QModelIndex&) const override;
    QVariant data(const QModelIndex &, int) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void reload();
    void setRecords(const QList<HealthRecord> &records);

private:
    DatabaseManager* m_db;
    int m_userId;
    QList<HealthRecord> m_records;
};

#endif
