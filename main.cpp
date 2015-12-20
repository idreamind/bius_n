#include "TestView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestView w;
    w.show();

    return a.exec();
}
