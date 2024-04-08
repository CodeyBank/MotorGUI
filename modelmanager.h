#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <QObject>
#include "customdatamodel.h"

class ModelManager : public QObject
{
    Q_OBJECT

public:
    explicit ModelManager(QObject *parent = nullptr);

public slots:
    QVariant get(const QString &variableName);
    void update(const QString &dataSource, const QVariant &value);

private:
    QMap<QString, CustomDataModel*> m_models; // Map of data sources to models
};

#endif // MODELMANAGER_H
