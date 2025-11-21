#include "RecordsModel.h"

RecordsModel::RecordsModel(QObject *parent)
    : QAbstractTableModel(parent)
{}

void RecordsModel::setRecords(const QVector<HealthRecord> &records)
{
    beginResetModel();
    m_records = records;
    endResetModel();
}

int RecordsModel::rowCount(const QModelIndex &) const
{
    return m_records.size();
}

int RecordsModel::columnCount(const QModelIndex &) const
{
    return 6; // fecha, peso, sistólica, diastólica, glucosa
}

QVariant RecordsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) return {};

    const HealthRecord &r = m_records[index.row()];

    switch (index.column()) {
    case 0: return r.dateTime().toString("yyyy-MM-dd HH:mm");
    case 1: return r.weight();
    case 2: return r.systolic();
    case 3: return r.diastolic();
    case 4: return r.glucoseLevel();
    default: return {};
    }
}

QVariant RecordsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return {};

    switch (section) {
    case 0: return "Fecha";
    case 1: return "Peso";
    case 2: return "Sistólica";
    case 3: return "Diastólica";
    case 4: return "Glucosa";
    }

    return {};
}
