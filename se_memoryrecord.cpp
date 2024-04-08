#include "se_memoryrecord.h"

SE_MemoryRecord::SE_MemoryRecord(QObject *parent) :QObject(parent){}

SE_MemoryRecord::SE_MemoryRecord(const QString &name,
                        const QString &attribute,
                        const QString &value,
                        const QString &address,
                        const qint8 &size,
                        const QString &type,
                        QObject *parent)
    : QObject(parent),
    m_name(name),
    m_attribute(attribute),
    m_value(value),
    m_type(type),
    m_size(size),
    m_address(address)
{
}

QString SE_MemoryRecord::name() const
{
    return m_name;
}

void SE_MemoryRecord::setName(const QString &name)
{
    if(m_name != name){
        m_name = name;
        emit nameChanged();
    }
}

QString SE_MemoryRecord::attribute() const
{
    return m_attribute;
}

void SE_MemoryRecord::setAttribute(const QString &attribute)
{
    if(m_attribute != attribute){
        m_attribute = attribute;
        emit attributeChanged();
    }

}

QString SE_MemoryRecord::type() const
{
    return m_type;
}

void SE_MemoryRecord::setType(const QString &type)
{
    if(m_type != type){
        m_type = type;
        emit typeChanged();
    }
}

qint8 SE_MemoryRecord::size() const
{
    return m_size;
}

void SE_MemoryRecord::setSize(const qint8 &size)
{
    if(m_size != size){
        m_size = size;
        emit sizeChanged();
    }
}

QString SE_MemoryRecord::address() const
{
    return m_address;
}

void SE_MemoryRecord::setAddress(const QString &address)
{
    if(m_address != address){
        m_address = address;
        emit addressChanged();
    }
}

QString SE_MemoryRecord::value() const
{
    return m_value;
}

void SE_MemoryRecord::setValue(const QString &value)
{
    if(m_value != value){
        m_value = value;
        emit valueChanged();
    }
}
