#pragma once

#include "ComparableGadget/ComparableGadget.h"

#include "ChildGadget.h"
#include "SimpleQGadget.h"

class TestGadget : public ComparableGadget
{
    Q_GADGET
    COMPARABLE_GADGET(TestGadget)
    Q_PROPERTY(float vFloat MEMBER vFloat)
    Q_PROPERTY(double vDouble MEMBER vDouble)
    Q_PROPERTY(quint8 vQuint8 MEMBER vQuint8)
    Q_PROPERTY(QString vString MEMBER vString)

    Q_PROPERTY(ChildGadget vChild MEMBER vChild)
    Q_PROPERTY(QList<ChildGadget> vChilds MEMBER vChilds)
//    Q_PROPERTY(SimpleQGadget vSimgleGadget MEMBER vSimgleGadget)

public:
//    QString toString() const override { return ComparableGadget::toString(); };

    float vFloat{};
    double vDouble{0.1};
    quint8 vQuint8{25};

    QString vString{"string"};

    ChildGadget vChild;
    QList<ChildGadget> vChilds;

    SimpleQGadget vSimgleGadget;
};

DECLARE_COMPARABLE_GADGET_METATYPE(TestGadget);
