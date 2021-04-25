#include <QCoreApplication>

#include <QDebug>

#include "ComparableGadget/ComparableGadgets.h"
#include "TestGadget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    registerComparableGadgets();

    ChildGadget ch1;
    QList<ChildGadget> childs = {ch1, ch1};
    TestGadget t1, t2;
    t1.vChilds = childs;
//    t2.vChilds = childs;

    qDebug().noquote() << "t1.toString():" <<  QVariant::fromValue(t1).toString();
//    qDebug() << "t1:" <<  t1 << endl << "t2:" << t2;
//    qDebug() << "equal:" << (t1 == t2 ? "true" : "false");

    return 0;
}
