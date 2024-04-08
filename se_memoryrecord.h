#ifndef SE_MEMORYRECORD_H
#define SE_MEMORYRECORD_H

#include <QObject>

class SE_MemoryRecord : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(qint8 size READ size WRITE setSize NOTIFY addressChanged)
    Q_PROPERTY(QString attribute READ attribute WRITE setAttribute NOTIFY attributeChanged)
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit SE_MemoryRecord(QObject *parent = nullptr);

    SE_MemoryRecord(const QString &name,
                    const QString &attribute,
                    const QString &value,
                    const QString &address,
                    const qint8 &size,
                    const QString &type,
                    QObject *parent=nullptr);

    QString name() const;
    void setName(const QString &name);
    QString attribute() const;
    void setAttribute(const QString &attribute);
    QString type() const;
    void setType(const QString &type);
    qint8 size() const;
    void setSize(const qint8 &size);
    QString address() const;
    void setAddress(const QString &address);
    QString value() const;
    void setValue(const QString &value);

signals:
    void nameChanged();
    void addressChanged();
    void typeChanged();
    void valueChanged();
    void attributeChanged();
    void sizeChanged();

private:
    QString m_name;
    QString m_attribute;
    QString m_value;
    QString m_type;
    qint8 m_size;
    QString m_address;

};

#endif // SE_MEMORYRECORD_H
