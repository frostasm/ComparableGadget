#pragma once

#include "ComparableGadgetHelper.h"

#include <QDebug>

/*
Child class example:

#include <ComparableGadget/ComparableGadget.h>

class Child : public ComparableGadget
{
    Q_GADGET
    COMPARABLE_GADGET(Child)
    Q_PROPERTY(QString name MEMBER name);
public:

    QString name;
};

DECLARE_COMPARABLE_GADGET_METATYPE(Child)
*/

class ComparableGadget
{
    Q_GADGET
public:
    ComparableGadget();
    virtual ~ComparableGadget();

    virtual const QMetaObject* getStaticMetaObject() const;

    Q_INVOKABLE virtual QString toString() const;

    virtual bool operator==(const ComparableGadget& other) const;
    virtual bool operator!=(const ComparableGadget& other) const;

protected:
};

Q_DECLARE_METATYPE(ComparableGadget)
