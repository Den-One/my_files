#ifndef PLUSMINUS_H
#define PLUSMINUS_H

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QPushButton>

class PlusMinus: public QWidget {
    Q_OBJECT // macro must be included in classes
    // witch declare their own signals and slots
public:
    PlusMinus(QWidget *parent = 0); // constructor

private slots:
    void OnPlus(); // slot +
    void OnMinus(); // slot -

private:
    QLabel *lbl; // vidget

};

#endif // PLUSMINUS_H
