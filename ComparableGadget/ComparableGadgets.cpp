#include "ComparableGadgets.h"

#include <TestGadget.h>

void registerComparableGadgets() {
    qRegisterComparableGadget<ChildGadget>();
    qRegisterComparableGadget<TestGadget>();
}
