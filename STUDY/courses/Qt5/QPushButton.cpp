#include "mainwindow.h"
#include <QApplication>
#include <QIcon>
#include <QWidget>
#include <QPushButton>

class MyButton : public QWidget {
public:
     MyButton(QWidget *parent = 0);
};

MyButton::MyButton(QWidget *parent)
    : QWidget(parent) {

    QPushButton *quitBtn = new QPushButton("Quit", this); // make button
    quitBtn->setGeometry(50, 40, 75, 30); // change size of button

    //При нажатии на кнопку, генерируется сигнал clicked.
    //Слот — это метод, который реагирует на сигнал.
    //В нашем случае это будет слот quit основного объекта
    //приложения. QApp — это глобальный указатель на объект приложения.
    //Он определен в заголовочном файле QApplication.
    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
    }

int main(int argc, char *argv[])
{
    // Every program have to be here
    QApplication app(argc, argv);

    // it's main vidjet of your window
    MyButton window;

    window.resize(250, 150);
    window.setWindowTitle("QPushButton");
    window.setWindowIcon(QIcon("C:/Users/pcuser/QtProjects/images/set.png"));
    window.show();

    return app.exec();
}
