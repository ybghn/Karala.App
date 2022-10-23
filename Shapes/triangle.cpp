#include "triangle.h"
#include <GL/gl.h>

Triangle::Triangle(QPointF _start, QPointF _end)
{
    start = _start;
    end = _end;
}

/*
 * if start.y() > end.y()
    *0  (start.x()+end.x())/2 ,    start.y()
*1______*2
*
*
*/
void Triangle::Draw()
{
    if(start.y()<end.y())
    {
        glBegin(GL_TRIANGLES);
        glVertex2f((start.x()+end.x())/2,start.y());
        glVertex2f(start.x(),end.y());
        glVertex2f(end.x(),end.y());
        glEnd();
    }
    else{
        glBegin(GL_TRIANGLES);
        glVertex2f((start.x()+end.x())/2,end.y());
        glVertex2f(end.x(),start.y());
        glVertex2f(start.x(),start.y());
        glEnd();
    }



}

void Triangle::Update(QPointF _last)
{
end = _last;
}
