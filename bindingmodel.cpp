#include "bindingmodel.h"
#include "seprotocol.h"

BindingModel::BindingModel(QObject *parent) : QAbstractListModel(parent)
{
    /*    qInfo()<<"Memory model instantiated";
    SE_MemoryRecord *data = new SE_MemoryRecord("variable","RW", "500", 323002, 8, "sU16",parent);
    m_data.push_back(data)*/;

}

int BindingModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return m_data.size();
}

int BindingModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return 6;
}


QVariant BindingModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    if (index.row() < 0 || index.row() >= m_data.size())
        return QVariant();

    BindingItem *item = m_data.at(index.row());
    switch (role) {
    case NameRole:
        return item->objName();
    case AttributeRole:
        return item->attribute();
    case NameRole:
        return item->value();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> BindingModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[TagRole] = "tag";
    roles[ReadWriteRole] = "readwrite";
    return roles;
}

void BindingModel::updateData(const QString &name,
                             const qint32 &address,
                             const quint8 &attribute)
{

    BindingItem *data = new BindingItem();
    data->setName(name);

    qInfo()<<"toconvert attribute: "<<attribute;
    QString attr = convertAttribute_ToString(attribute);
    qInfo()<<"Converted attribute: "<<attr;
    data->setAttribute(attr);

    data->setValue(value);

    QString hexAddress = QString("%1").arg(address, 2, 16, QLatin1Char('0'));
    data->setAddress("0x"+hexAddress);
    data->setSize(size);

    QString tp = convertDT_MAP_ToString(type);
    qInfo()<<"Converted type: "<<tp;
    data->setType(tp);

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(data);
    endInsertRows();

    // Emit dataChanged signal for all roles for the newly inserted row
    QModelIndex topLeft = QAbstractListModel::index(rowCount() - 1, 0); // Top-left index of the new row
    QModelIndex bottomRight = QAbstractListModel::index(rowCount() - 1, columnCount(QModelIndex()) - 1); // Bottom-right index of the new row
    emit dataChanged(topLeft, bottomRight);

}


QModelIndex BindingModel::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || row >= m_data.size() || column < 0 || column >= columnCount(QModelIndex()) || parent.isValid())
        return QModelIndex();

    return createIndex(row, column);
}

QModelIndex BindingModel::parent(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return QModelIndex(); // This model does not have hierarchical data, so the parent is always invalid
}

// void BindingModel::modifyData(int row, const QString &name, const QString &attribute, const QString &value)
// {
//     if (row < 0 || row >= m_data.size()) {
//         return; // Row index out of bounds
//     }

//     SE_MemoryRecord *data = m_data.at(row);
//     data->setName(name);
//     data->setAttribute(attribute);
//     data->setValue(value);

//     QModelIndex topLeft = index(row, 0);
//     // QModelIndex bottomRight = index(row, columnCount() - 1, QModelIndex());
//     QVector<int> roles = {NameRole, AttributeRole, ValueRole};
//     // emit dataChanged(topLeft, bottomRight, roles);
// }
