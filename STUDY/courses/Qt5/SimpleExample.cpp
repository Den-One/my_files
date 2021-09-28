#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Every program have to be here
    QApplication app(argc, argv);

    // it's main vidjet of your window
    MainWindow window;

    window.resize(250, 150);
    window.setWindowTitle("Simple example");
    window.show();

    return app.exec();
}
