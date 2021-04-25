#include <QCoreApplication>

#include <QDebug>

#include "ComparableGadget/ComparableGadgets.h"
#include "TestGadget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    registerComparableGadgets();

    TestGadget t1, t2;
    ChildGadget ch1;
    qDebug() << t1;

    qDebug() << "equal:" << (t1 == t2 ? "true" : "false");

    return 0;
}
