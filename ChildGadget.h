#pragma once

#include "ComparableGadget/ComparableGadget.h"

#include <QDebug>

class ChildGadget : public ComparableGadget
{
    Q_GADGET
    COMPARABLE_GADGET(ChildGadget)
    Q_PROPERTY(float vFloat MEMBER vFloat)
    Q_PROPERTY(double vDouble MEMBER vDouble)
    Q_PROPERTY(quint8 vQuint8 MEMBER vQuint8)
    Q_PROPERTY(QString vString MEMBER vString)
public:

    float vFloat{0.0};
    double vDouble{0.1};
    quint8 vQuint8{25};

    QString vString{"string"};
};

Q_DECLARE_METATYPE(ChildGadget)

