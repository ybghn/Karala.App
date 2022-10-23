#include "point.h"


Point::Point(QPointF _start,QPointF _end)
{
start = _start;
end = _end;

}

void Point::Draw()
{

      glBegin(GL_LINE_STRIP);

    for (auto  i: qAsConst(points)) {

       glVertex2f(i.x(),i.y());

    }
     glEnd();
}

void Point::Update(QPointF _last)
{
points.append(_last);
}
