#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

#include <QTextEdit>

class Absolute : public QWidget {
public:
    Absolute(QWidget *parent = 0);
};

Absolute::Absolute(QWidget *parent)
    : QWidget(parent) {

    QTextEdit *ledit = new QTextEdit(this);
    ledit->setGeometry(5, 5, 200, 150);
}

int main(int argc, char *argv[])
{
    // Every program have to be here
    QApplication app(argc, argv);

    // it's main vidjet of your window
    Absolute window;

    window.resize(250, 150);
    window.setWindowTitle("Absolute");
    window.setWindowIcon(QIcon("C:/Users/pcuser/QtProjects/images/set.png"));
    window.show();

    return app.exec();
}
