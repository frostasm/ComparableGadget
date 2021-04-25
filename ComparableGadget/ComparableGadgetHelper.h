#pragma once

#include <QList>
#include <QObject>

template <typename T>
inline bool qRegisterComparableGadget()
{
    const int typeId = qRegisterMetaType<T>();
    Q_ASSERT(typeId > 0);

    const int typeIdList = qRegisterMetaType<QList<T>>();
    Q_ASSERT(typeIdList > 0);

    const bool comparatorOk = QMetaType::registerEqualsComparator<T>();
    Q_ASSERT(comparatorOk);

    const bool comparatorListOk = QMetaType::registerEqualsComparator<QList<T>>();
    Q_ASSERT(comparatorListOk);

    const bool debugStreamOk = QMetaType::registerDebugStreamOperator<T>();
    Q_ASSERT(debugStreamOk);

    const bool debugStreamListOk = QMetaType::registerDebugStreamOperator<QList<T>>();
    Q_ASSERT(debugStreamListOk);

    return typeId > 0 && typeIdList > 0 && comparatorOk && comparatorListOk && debugStreamOk && debugStreamListOk;
}

#define COMPARABLE_GADGET(name) \
public: \
    Q_INVOKABLE name() { Q_ASSERT_X(QMetaType::type(#name) != 0, __func__, "Add registration code " \
    "qRegisterComparableGadget<" #name ">() and call registerComparableGadgets function at application startup!"); } \
    const QMetaObject* getStaticMetaObject() const override { return &name::staticMetaObject; } \
private:


#define DECLARE_COMPARABLE_GADGET_METATYPE(name) \
    Q_DECLARE_METATYPE(name); \
    Q_DECLARE_METATYPE(QList<name>); \
    inline QDebug operator<<(QDebug d, const name &g) { d << qUtf8Printable(g.toString()); return d; } \
    inline QDebug operator<<(QDebug d, const QList<name> &l) { for (const auto& g: l) d << qUtf8Printable(g.toString()) << ", "; return d; }
