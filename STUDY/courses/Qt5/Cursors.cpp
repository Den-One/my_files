#include "mainwindow.h"
#include <QApplication>
#include <QIcon>
#include <QGridLayout>
#include <QFrame>

class Cursors: public QWidget {
public:
    Cursors(QWidget *parent = 0);
};

Cursors::Cursors(QWidget *parent)
    : QWidget(parent) {

    QFrame *frame1 = new QFrame(this); // make widget
    frame1->setFrameStyle(QFrame::Box); // set frames
    frame1->setCursor(Qt::SizeAllCursor); // set Cursor

    QFrame *frame2 = new QFrame(this); // make widget
    frame2->setFrameStyle(QFrame::Box); // set frames
    frame2->setCursor(Qt::WaitCursor); // set Cursor

    QFrame *frame3 = new QFrame(this); // make widget
    frame3->setFrameStyle(QFrame::Box); // set frames
    frame3->setCursor(Qt::PointingHandCursor); // set Cursor

    // groups all frames in one line
    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(frame1, 0, 0);
    grid->addWidget(frame2, 0, 1);
    grid->addWidget(frame3, 0, 2);

    setLayout(grid);
}

int main(int argc, char *argv[])
{
    // Every program have to be here
    QApplication app(argc, argv);

    // it's main vidjet of your window
    Cursors window;

    window.resize(250, 150);
    window.setWindowTitle("Cursors");
    window.setWindowIcon(QIcon("C:/Users/pcuser/QtProjects/images/set.png"));
    window.show();

    return app.exec();
}
