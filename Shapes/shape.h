#ifndef SHAPE_H
#define SHAPE_H

#include <QPointF>
class Shape
{
public:
    Shape();
    virtual void Draw();
    virtual void Update(QPointF _last);

protected:
    QPointF start,end;
    float size{1};
};

#endif // SHAPE_H
