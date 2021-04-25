#include "ComparableGadgets.h"

#include <TestGadget.h>

void registerComparableGadgets() {
    qRegisterComparableGadget<TestGadget>();
    qRegisterComparableGadget<ChildGadget>();
}
