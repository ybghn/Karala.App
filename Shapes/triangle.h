#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle(QPointF _start, QPointF _end);

    // Shape interface
public:
    void Draw() override;
    void Update(QPointF _last) override;
};

#endif // TRIANGLE_H
