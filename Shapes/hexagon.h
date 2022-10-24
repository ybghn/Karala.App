#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"
#include <QOpenGLContext>
#include <QOpenGLFunctions>


class Hexagon : public Shape
{
public:
    Hexagon(QPointF _start,QPointF _end);
    ~Hexagon();

    // Shape interface
public:
    void Draw() override;
    void Update(QPointF _last) override;


private:
    unsigned int vbo;
    void CreateData();
    float vertices[12]; // 6*2
    QOpenGLFunctions* f;
};
#endif // HEXAGON_H
