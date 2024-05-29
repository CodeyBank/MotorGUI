#ifndef BINDINGMODEL_H
#define BINDINGMODEL_H

#include "bindingitem.h"
#include <QObject>
#include <QQmlEngine>
#include <QAbstractListModel>
#include <QList>
#include <QMap>
#include <QQmlEngine>



class BindingModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit BindingModel(QObject *parent = nullptr);

    enum {
        NameRole = Qt::UserRole,
        TagRole,
        ReadWriteRole,
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent= QModelIndex())const override;
    QModelIndex index(int row, int column, const QModelIndex &parent=QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QModelIndex parent(const QModelIndex &index) const override ;
    QHash<int, QByteArray> roleNames() const override;


public slots:
    void addBinding(const QString &name,
                    const QString &tag,
                    const QString &readwrite);

    void modifyBinding(int row,
                       const QString &name,
                       const QString &tag,
                       const QString &readwrite);

private:
    QList<BindingItem*> m_data;


};

#endif // BINDINGMODEL_H
