#ifndef BINDINGITEM_H
#define BINDINGITEM_H

#include <QObject>

class BindingItem : public QObject{

    QString m_objName;
    QString m_tagname;
    bool m_readwrite;

    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString tag READ tag WRITE setTag NOTIFY tagChanged)
    Q_PROPERTY(QString readWrite READ readWrite WRITE setReadWrite NOTIFY readWritesChanged)

public:
    explicit BindingItem(QObject *parent = nullptr);

    BindingItem(const QString &name,
                const QString &tag,
                const bool &readWrite,
                QObject *parent=nullptr);

    QString name() const;
    void setName(const QString &name);
    QString tag() const;
    void setTag(const QString &tag);
    bool readWrite() const;
    void setReadWrite(const bool &readWrite);

signals:
    void nameChanged();
    void tagChanged();
    void readWriteChanged();
};

#endif // BINDINGITEM_H
