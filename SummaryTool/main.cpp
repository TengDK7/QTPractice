#include "SummaryToolForm.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SummaryToolForm w;

    w.show();
    return a.exec();
}
