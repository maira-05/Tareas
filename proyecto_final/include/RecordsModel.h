#ifndef RECORDSMODEL_H
#define RECORDSMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include "HealthRecord.h"

class RecordsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    RecordsModel(QObject *parent = nullptr);

    void setRecords(const QVector<HealthRecord> &records);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QVector<HealthRecord> m_records;
};

#endif // RECORDSMODEL_H
