#include "memorymodel.h"
#include "seprotocol.h"

MemoryModel::MemoryModel(QObject *parent) : QAbstractListModel(parent)
{
/*    qInfo()<<"Memory model instantiated";
    SE_MemoryRecord *data = new SE_MemoryRecord("variable","RW", "500", 323002, 8, "sU16",parent);
    m_data.push_back(data)*/;

}

int MemoryModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return m_data.size();
}

int MemoryModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return 6;
}


QVariant MemoryModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    if (index.row() < 0 || index.row() >= m_data.size())
        return QVariant();

    SE_MemoryRecord *item = m_data.at(index.row());
    switch (role) {
    case NameRole:
        return item->name();
    case AttributeRole:
        return item->attribute();
    case ValueRole:
        return item->value();
    case AddressRole:
        return item->address();
    case TypeRole:
        return item->type();
    case SizeRole:
        return item->size();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> MemoryModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[AttributeRole] = "attribute";
    roles[AddressRole] = "address";
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    roles[ValueRole] = "value";
    return roles;
}

void MemoryModel::updateData(const QString &name,
                             const qint32 &address,
                             const quint8 &attribute,
                             const quint8 &type,
                             const qint8 &size,
                             const QString &value)
{

    SE_MemoryRecord *data = new SE_MemoryRecord;
    data->setName(name);

    QString attr = convertAttribute_ToString(attribute);
    data->setAttribute(attr);

    data->setValue(value);

    QString hexAddress = QString("%1").arg(address, 2, 16, QLatin1Char('0'));
    data->setAddress("0x"+hexAddress);
    data->setSize(size);

    QString tp = convertDT_MAP_ToString(type);
    data->setType(tp);

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(data);
    endInsertRows();

    // Emit dataChanged signal for all roles for the newly inserted row
    QModelIndex topLeft = QAbstractListModel::index(rowCount() - 1, 0); // Top-left index of the new row
    QModelIndex bottomRight = QAbstractListModel::index(rowCount() - 1, columnCount(QModelIndex()) - 1); // Bottom-right index of the new row
    emit dataChanged(topLeft, bottomRight);

}


QModelIndex MemoryModel::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || row >= m_data.size() || column < 0 || column >= columnCount(QModelIndex()) || parent.isValid())
        return QModelIndex();

    return createIndex(row, column);
}

QModelIndex MemoryModel::parent(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return QModelIndex(); // This model does not have hierarchical data, so the parent is always invalid
}

//modifiedData(data.name, data.address, data.attribute,data.type, data.size, data.value)
void MemoryModel::modifyData(const QString &name,
                             const qint32 &address,
                             const quint8 &attribute,
                             const quint8 &type,
                             const qint8 &size,
                             const QString &value)
{


    for(int i=0; i< rowCount(); i++){
        if (m_data[i]->name() == name){
            auto data = m_data[i];
            data->setValue(value);
            m_data[i] = data;
            // qInfo()<< "found item in the model";
            // m_data[i]->setAddress(address);
            // m_data[i]->setAttribute(convertAttribute_ToString((attribute)));
            // m_data[i]->setValue(value);
            // m_data[i]->setSize(size);
            // m_data[i]->setType(type);s

            // Emit dataChanged signal for all roles for the newly inserted row
            QModelIndex topLeft = QAbstractListModel::index(i, 0); // Top-left index of the new row
            QModelIndex bottomRight = QAbstractListModel::index(i, columnCount(QModelIndex()) - 1);
            emit dataChanged(topLeft, bottomRight);
        }
    }

}

void MemoryModel::clear()
{
    beginResetModel();
    m_data.clear();
    endResetModel();
}
