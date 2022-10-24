#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <QtMath>
#include <QOpenGLFunctions>
class Circle : public Shape
{
public:
    Circle(QPointF _start, QPointF _end);

    // Shape interface
public:
    void Draw() override;
    void Update(QPointF _last) override;

private:
    void DrawRightToLeft();
    void DrawLeftToRight();
    const static  int sizeOfPoint{100};
     float vertices[sizeOfPoint*4+1];

};

#endif // CIRCLE_H
