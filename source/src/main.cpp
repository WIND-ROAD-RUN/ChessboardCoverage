#include "ChessboardCoverage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessboardCoverage w;
    w.show();
    return a.exec();
}
