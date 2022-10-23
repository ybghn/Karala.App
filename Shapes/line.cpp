#include "line.h"


Line::Line(QPointF _start,QPointF _end)
{
    start = _start;
    end = _end;
    //    size = GetSize
}

void Line::Draw()
{

    glBegin(GL_LINE_STRIP);
        glVertex2d(start.x(),start.y());
        glVertex2d(end.x(),end.y());
    glEnd();

}

void Line::Update(QPointF _last)
{
    end = _last;
}
