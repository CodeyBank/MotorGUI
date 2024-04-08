#include "bindingitem.h"


BindingItem::BindingItem(QObject *parent) :QObject(parent){}

BindingItem::BindingItem(const QString &name,
                         const QString &tag,
                         const bool &readWrite,
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

// QString BindingItem::attribute() const
// {
//     return m_attribute;
// }

// void BindingItem::setAttribute(const QString &attribute)
// {
//     if(m_attribute != attribute){
//         m_attribute = attribute;
//         emit attributeChanged();
//     }

// }

// QString BindingItem::type() const
// {
//     return m_type;
// }

// void BindingItem::setType(const QString &type)
// {
//     if(m_type != type){
//         m_type = type;
//         emit typeChanged();
//     }
// }

// QString BindingItem::tag() const
// {
//     return tagname;
// }

// void BindingItem::setSize(const qint8 &size)
// {
//     if(m_size != size){
//         m_size = size;
//         emit sizeChanged();
//     }
// }

// QString BindingItem::address() const
// {
//     return m_address;
// }

