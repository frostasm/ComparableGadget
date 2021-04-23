#include <QCoreApplication>

#include <QDebug>

#include "ComparableGadget/ComparableGadgets.h"
#include "TestGadget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    registerComparableGadgets();

    TestGadget t1, t2;
//    t1.vString = "";

    qDebug() << "equal:" << (t1 == t2 ? "true" : "false");

//    return a.exec();
    return 0;
}
