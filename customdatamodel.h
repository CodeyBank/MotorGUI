#ifndef CUSTOMDATAMODEL_H
#define CUSTOMDATAMODEL_H

#include <QObject>
// #include <QAbstractListModel>
#include <QVariant>

class CustomDataModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant data READ data WRITE setData NOTIFY dataChanged FINAL)
public:
    enum CustomRoles {
        DataRole = Qt::UserRole + 1
    };

    explicit CustomDataModel(QObject *parent = nullptr);

    // int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    // QVariant data(const QModelIndex &index, int role) const ;

public slots:
    void setData(const QVariant &data);
    QVariant data(){
        // qInfo()<<"Data requested";
        return m_data;
    }

signals:
    void dataChanged();

private:
    QVariant m_data;
};

#endif // CUSTOMDATAMODEL_H
