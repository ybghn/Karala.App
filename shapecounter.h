#ifndef SHAPECOUNTER_H
#define SHAPECOUNTER_H


#include "ui_mainwindow.h"
#include <QLabel>

class ShapeCounter
{
public:
    ShapeCounter(Ui::MainWindow *ui);

    void AddLine();
    void AddPen();
    void AddBox();
    void AddCircle();
    void AddTriangle();
    void AddHexagon();
private:
    Ui::MainWindow *ui;

    int lineCount{0};
    int penCount{0};
    int boxCount{0};
    int circleCount{0};
    int triangleCouunt{0};

    int hexagonCount{0};
};



#endif // SHAPECOUNTER_H
