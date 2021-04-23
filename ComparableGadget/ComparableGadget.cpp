#include "ComparableGadget.h"

#include <QMetaProperty>
#include <QDebug>

bool isGadgetEqual(const ComparableGadget &lhs, const ComparableGadget &rhs, const QMetaObject &metaObject);

ComparableGadget::ComparableGadget()
{
}

QString ComparableGadget::toString() const
{
    QString result;
    return result;
//    QDebug dbg(&result);
//    dbg.noquote().nospace();

//    const QMetaObject &mObj = *getStaticMetaObject();
//    const int propertyCount = mObj.propertyCount();

//    dbg << mObj.className() << "(";
//    for (int i = mObj.propertyOffset(); i < propertyCount; ++i) {
//        const QMetaProperty prop = mObj.property(i);
//        if (!prop.isReadable()) {
//            continue;
//        }
//        const QVariant thisValue = prop.readOnGadget(this);

//    }
}

bool ComparableGadget::operator==(const ComparableGadget &other) const
{
    const QMetaObject *metaObject = getStaticMetaObject();
    return isGadgetEqual(*this, other, *metaObject);
}

bool ComparableGadget::operator!=(const ComparableGadget &other) const
{
    return !(*this == other);
}

bool isGadgetEqual(const ComparableGadget &lhs, const ComparableGadget &rhs, const QMetaObject &metaObject)
{
    const QMetaObject &mObj = metaObject;
    const int propertyCount = mObj.propertyCount();
    for (int i = mObj.propertyOffset(); i < propertyCount; ++i) {
        const QMetaProperty prop = mObj.property(i);
        if (!prop.isReadable()) {
            continue;
        }

        const QVariant thisValue = prop.readOnGadget(&lhs);
        const QVariant otherValue = prop.readOnGadget(&rhs);
        Q_ASSERT_X(thisValue.isValid(), __func__, prop.name());
        const bool equal = thisValue == otherValue;
        qDebug() << "Compare properties:" << prop.name() << thisValue << otherValue << "equal:" << equal;
        if (!equal) {
            return false;
        }
    }

    return propertyCount == 0 ? (&lhs == &rhs) : true;
}
