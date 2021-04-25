#pragma once

#include <QObject>

template <typename T>
inline int qRegisterComparableGadget()
{
    const int id = qRegisterMetaType<T>();
    QMetaType::registerEqualsComparator<T>();
    QMetaType::registerDebugStreamOperator<T>();

    return id;
}

#define COMPARABLE_GADGET(name) \
    static int _qMetaId()  { return QMetaType::type(#name); } \
public: \
    name() { Q_ASSERT_X(_qMetaId() != 0, __func__, \
                        "Add code to register " #name " into global function registerComparableGadgets()!"); } \
    const QMetaObject* getStaticMetaObject() const override { return &name::staticMetaObject; } \
private:


#define DECLARE_COMPARABLE_GADGET_METATYPE(name) \
    Q_DECLARE_METATYPE(name); \
    inline QDebug operator<<(QDebug d, const name &g) { d << qUtf8Printable(g.toString()); return d; }
