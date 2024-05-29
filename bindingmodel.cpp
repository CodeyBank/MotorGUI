#include "bindingmodel.h"

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
    return 3;
}


QVariant BindingModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    if (index.row() < 0 || index.row() >= m_data.size())
        return QVariant();

    BindingItem *item = m_data.at(index.row());
    switch (role) {
    case NameRole:
        return item->name();
    case TagRole:
        return item->tag();
    case ReadWriteRole:
        return item->readWrite();
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

void BindingModel::addBinding(const QString &name,
                   const QString &tag,
                   const QString &readwrite)
{

    /*
        Before adding the binding to the list, check if it already exists
        if it does call, modifyBinding API
    */

    for(int idx{}; idx<m_data.size(); idx++){
        auto item = m_data[idx];
        if (item->name() == name){
            modifyBinding(idx, name, tag,readwrite);
            return;
        }
    }

    BindingItem *newBinding = new BindingItem();
    newBinding->setName(name);
    newBinding->setTag(tag);
    newBinding->setReadWrite(readwrite);

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(newBinding);
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

void BindingModel::modifyBinding(int row,
                              const QString &name,
                              const QString &tag,
                              const QString &readwrite)
{
    if (row < 0 || row >= m_data.size()) {
        return; // Row index out of bounds
    }

    BindingItem *item = m_data.at(row);
    item->setName(name);
    item->setTag(tag);
    item->setReadWrite(readwrite);

    QModelIndex topLeft = index(row, 0);
    QModelIndex bottomRight = index(row, columnCount() - 1, QModelIndex());
    QVector<int> roles = {NameRole, TagRole, ReadWriteRole};
    emit dataChanged(topLeft, bottomRight, roles);
}




