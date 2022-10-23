#ifndef BOX_H
#define BOX_H

#include "shape.h"
#include <QOpenGLFunctions>
class Box : public Shape
{
public:
    Box(QPointF _start,QPointF _end);

    // Shape interface
public:
    void Draw() override;
    void Update(QPointF _last) override;
};

#endif // BOX_H
