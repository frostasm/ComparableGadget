#pragma once

#include "ComparableGadget/ComparableGadget.h"
#include "ChildGadget.h"


class TestGadget : public ComparableGadget
{
    Q_GADGET
    COMPARABLE_GADGET(TestGadget)
    Q_PROPERTY(float vFloat MEMBER vFloat)
    Q_PROPERTY(double vDouble MEMBER vDouble)
    Q_PROPERTY(quint8 vQuint8 MEMBER vQuint8)
    Q_PROPERTY(QString vString MEMBER vString)
    Q_PROPERTY(ChildGadget vChild MEMBER vChild)

public:
    float vFloat{};
    double vDouble{0.1};
    quint8 vQuint8{25};

    QString vString{"string"};

    ChildGadget vChild;
};

Q_DECLARE_METATYPE(TestGadget);
