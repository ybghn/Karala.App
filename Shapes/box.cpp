#include "box.h"


Box::Box(QPointF _start,QPointF _end)
{
start = _start;
end = _end;

}

/*
 * Vertex Order of box
0 ________3
|         |
|         |
|         |
1_________2
*/
void Box::Draw()
{
glBegin(GL_QUADS);
glVertex2f(start.x(),start.y()); //0
glVertex2f(start.x(),end.y());//1
glVertex2f(end.x(),end.y());//2
glVertex2f(end.x(),start.y());//3
glEnd();

}

void Box::Update(QPointF _last)
{
end= _last;
}
