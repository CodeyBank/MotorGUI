#ifndef MEMORYMODEL_H
#define MEMORYMODEL_H

#include <QAbstractItemModel>
#include <QAbstractListModel>
#include <QList>
#include <QQmlEngine>
#include "se_memoryrecord.h"



class MemoryModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit MemoryModel(QObject *parent = nullptr);

    enum {
        NameRole = Qt::UserRole,
        AddressRole,
        AttributeRole,
        TypeRole,
        SizeRole,
        ValueRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent)const override;
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QModelIndex parent(const QModelIndex &index) const override ;
    QHash<int, QByteArray> roleNames() const override;


public slots:
    void updateData(const QString &name,
                    const qint32 &address,
                    const quint8 &attribute,
                    const quint8 &type,
                    const qint8 &size,
                    const QString &value);

    void modifyData(const QString &name,
                    const qint32 &address,
                    const quint8 &attribute,
                    const quint8 &type,
                    const qint8 &size,
                    const QString &value);

    void clear();


signals:

private:

    QList<SE_MemoryRecord *> m_data;


};

#endif // MEMORYMODEL_H
