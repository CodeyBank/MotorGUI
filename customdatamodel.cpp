#include "customdatamodel.h"

CustomDataModel::CustomDataModel(QObject *parent)
    : QObject(parent)
{
    m_data=0;
}

// int CustomDataModel::rowCount(const QModelIndex &parent) const
// {
//     if (parent.isValid())
//         return 0;
//     return 1; // Single row model
// }

// QVariant CustomDataModel::data(const QModelIndex &index, int role) const
// {
//     if (!index.isValid() || index.row() != 0)
//         return QVariant();

//     if (role == DataRole)
//         return m_data;

//     return QVariant();
// }

void CustomDataModel::setData(const QVariant &data)
{
    if (m_data != data) {
        m_data = data;
        emit dataChanged();
    }
}
