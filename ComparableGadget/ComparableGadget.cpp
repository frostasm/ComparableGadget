#include "ComparableGadget.h"

#include <QMetaProperty>
#include <QDebug>

bool isGadgetEqual(const ComparableGadget &lhs, const ComparableGadget &rhs, const QMetaObject &metaObject);

ComparableGadget::ComparableGadget()
{
}

ComparableGadget::~ComparableGadget()
{

}

const QMetaObject *ComparableGadget::getStaticMetaObject() const
{
    Q_ASSERT_X(false, __func__, "Classes inherited from ComparableGadget must use COMPARABLE_GADGET(class name) and "
                                "DECLARE_COMPARABLE_GADGET_METATYPE(class name) macroses!");
    return nullptr;
}

QString ComparableGadget::toString() const
{
    QString result;

    QDebug dbg(&result);
    dbg.nospace().noquote();

    const QMetaObject &mObj = *getStaticMetaObject();
    const int propertyCount = mObj.propertyCount();

    dbg << mObj.className() << "(";
    for (int i = mObj.propertyOffset(); i < propertyCount; ++i) {
        const QMetaProperty prop = mObj.property(i);
        if (!prop.isReadable()) {
            continue;
        }

        dbg << prop.name() << ": ";
        const QVariant thisValue = prop.readOnGadget(this);
        const int vType = prop.type();
//        qDebug() << "test:" <<prop.name() << vType << thisValue;
        switch (vType) {
        case QMetaType::UnknownType:
            dbg << "Invalid";
            break;
        case QMetaType::Bool:
            dbg << (thisValue.toBool() ? "True" : "False");
            break;
        case QMetaType::SChar:
        case QMetaType::Char:
        case QMetaType::Short:
        case QMetaType::Int:
        case QMetaType::Long:
        case QMetaType::LongLong:
            dbg << thisValue.toLongLong();
            break;
        case QMetaType::UChar:
        case QMetaType::UShort:
        case QMetaType::UInt:
        case QMetaType::ULong:
        case QMetaType::ULongLong:
            dbg << thisValue.toULongLong();
            break;
        case QMetaType::Float:
        case QMetaType::Double:
            dbg << thisValue.toDouble();
            break;
        case QMetaType::QChar:
            dbg << thisValue.toChar();
            break;
        case QMetaType::QString:
            dbg << '"' << thisValue.toString() << '"';
            break;
        case QMetaType::User: {
            QMetaType metaType(prop.userType());
            Q_ASSERT_X(metaType.isValid(), __func__, qUtf8Printable(QString("Property(%1) type \"%2\" "
                       "not registered in Qt meta object system!").arg(prop.name(), prop.typeName())));

            const bool isGadget = metaType.flags().testFlag(QMetaType::TypeFlag::IsGadget);
            if (isGadget) {
                const QMetaObject *mo = metaType.metaObject();
                const bool isComparableGadget = mo->inherits(&staticMetaObject);
                Q_ASSERT_X(isComparableGadget, __func__, qUtf8Printable(QString("Property(%1) type \"%2\" is not "
                           "inherited from %3 class").arg(prop.name(), prop.typeName(), staticMetaObject.className())));
                if (isComparableGadget) {
                    const ComparableGadget* gadget = static_cast<const ComparableGadget*>(thisValue.constData());
                    dbg << gadget->toString();
                    break;
                }
            }
            dbg << thisValue;
            break;
        }
        default:
            dbg << thisValue;
            break;
        }

        if (i != (propertyCount - 1)) {
            dbg << "; ";
        }
    }
    dbg << ")";

    return result;
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
        Q_ASSERT_X(otherValue.isValid(), __func__, prop.name());
        const bool equal = thisValue == otherValue;
//        qDebug() << "Compare properties:" << prop.name() << thisValue << otherValue << "equal:" << equal;
        if (!equal) {
            return false;
        }
    }

    return propertyCount == 0 ? (&lhs == &rhs) : true;
}
