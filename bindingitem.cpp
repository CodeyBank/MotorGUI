#include "bindingitem.h"


BindingItem::BindingItem(QObject *parent) :QObject(parent){}

BindingItem::BindingItem(const QString &name,
                         const QString &tag,
                         const QString &readWrite,
                         QObject *parent)
    : QObject(parent),
    m_objName(name),
    m_tagname(tag),
    m_readwrite(readWrite)
{
}

QString BindingItem::name() const
{
    return m_objName;
}

void BindingItem::setName(const QString &name)
{
    if(m_objName != name){
        m_objName = name;
        emit nameChanged();
    }
}

QString BindingItem::tag() const
{
    return m_tagname;
}

void BindingItem::setTag(const QString &tag)
{
    m_tagname = tag;
}

QString BindingItem::readWrite() const
{
    return m_readwrite;
}

void BindingItem::setReadWrite(const QString &readWrite)
{
    m_readwrite = readWrite;
}

