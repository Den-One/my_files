#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    // Every program have to be here
    QApplication app(argc, argv);

    // it's main vidjet of your window
    QWidget window;

    window.resize(250, 150);
    window.setWindowTitle("ToolTip");
    window.setWindowIcon(QIcon("C:/Users/pcuser/QtProjects/images/set.png"));
    window.show();

    return app.exec();
}
