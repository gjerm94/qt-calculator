#include <QApplication>
#include <limits>


#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    MainWindow window;

    window.setFixedSize(403, 294);
    window.show();

    return app.exec();
}
