#pragma once

#include <QObject>
#include "ComparableGadget/ComparableGadget.h"

class SimpleQGadget: public ComparableGadget
{
    Q_GADGET
//    COMPARABLE_GADGET(SimpleQGadget)
    Q_PROPERTY(bool test MEMBER test)
public:
//    SimpleQGadget();

    bool test{false};

//    bool operator==(const SimpleQGadget &o) const {
//        return test == o.test;
//    }

//    bool operator!=(const SimpleQGadget &o) const {
//        return test != o.test;
//    }
};


//DECLARE_COMPARABLE_GADGET_METATYPE(SimpleQGadget)
