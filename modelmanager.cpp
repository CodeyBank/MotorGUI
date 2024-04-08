#include "modelmanager.h"
#include "qdebug.h"

ModelManager::ModelManager(QObject *parent)
    : QObject(parent)
{
    // m_models["dummy"] =QVariant();
}


QVariant ModelManager::get(const QString &variableName)
{
    if (!m_models.contains(variableName)) {
        CustomDataModel *model = new CustomDataModel(this);
        m_models.insert(variableName, model);
    }
    // qInfo()<<"Model manager is returning new variable "<<variableName;
    return m_models.value(variableName)->data();
}

void ModelManager::update(const QString &variableName, const QVariant &value)
{
    // qInfo()<<"##########Model manager is updating variable "<<variableName;
    if(m_models.contains(variableName)){
        m_models[variableName]->setData(value);
        // qInfo()<<variableName<< ": "<<m_models[variableName]->data();
    }
}
