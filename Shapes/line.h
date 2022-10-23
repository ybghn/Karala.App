#ifndef LINE_H
#define LINE_H


#include "shape.h"
#include <QOpenGLFunctions>
class Line : public Shape
{
public:
    Line(QPointF _start,QPointF _end);

    void Draw() override;
    void Update(QPointF _last) override;
protected:
private:

};

#endif // LINE_H
