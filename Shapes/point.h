#ifndef POINT_H
#define POINT_H

#include "shape.h"
#include <QVector>
#include <QOpenGLFunctions>
class Point : public Shape
{
public:
    Point(QPointF _start,QPointF _end);

    // Shape interface
public:
    void Draw() override;
    void Update(QPointF _last) override;

private:
    QVector<QPointF> points;
};

#endif // POINT_H
