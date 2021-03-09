#include "GUILearn.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUILearn w;
    w.show();
    return a.exec();
}
