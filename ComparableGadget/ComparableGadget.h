#pragma once

#include "ComparableGadgetHelper.h"

#include <QDebug>

class ComparableGadget
{
    Q_GADGET
public:
    ComparableGadget();

    virtual const QMetaObject* getStaticMetaObject() const;

    Q_INVOKABLE virtual QString toString() const;

    virtual bool operator==(const ComparableGadget& other) const;
    virtual bool operator!=(const ComparableGadget& other) const;

protected:
};

Q_DECLARE_METATYPE(ComparableGadget)
