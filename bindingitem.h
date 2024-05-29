#ifndef BINDINGITEM_H
#define BINDINGITEM_H

#include <QObject>

class BindingItem : public QObject{

    QString m_objName;
    QString m_tagname;
    QString m_readwrite;

    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString tag READ tag WRITE setTag NOTIFY tagChanged)
    Q_PROPERTY(QString readWrite READ readWrite WRITE setReadWrite NOTIFY readWriteChanged)

public:
    explicit BindingItem(QObject *parent = nullptr);

    BindingItem(const QString &name,
                const QString &tag,
                const QString &readWrite,
                QObject *parent=nullptr);

    QString name() const;
    void setName(const QString &name);
    QString tag() const;
    void setTag(const QString &tag);
    QString readWrite() const;
    void setReadWrite(const QString &readWrite);

signals:
    void nameChanged();
    void tagChanged();
    void readWriteChanged();
};

#endif // BINDINGITEM_H
