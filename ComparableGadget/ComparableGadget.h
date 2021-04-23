#pragma once

#include "ComparableGadgetHelper.h"

class ComparableGadget
{
    Q_GADGET
public:
    ComparableGadget();

    virtual const QMetaObject* getStaticMetaObject() const = 0;

    virtual QString toString() const;

    virtual bool operator==(const ComparableGadget& other) const;
    virtual bool operator!=(const ComparableGadget& other) const;

protected:
};
