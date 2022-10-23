#include "circle.h"

Circle::Circle(QPointF _start, QPointF _end)
{
start =_start;
end = _end;
}
// Formula of elipse
// (x^2 / a^2 ) + (y^2 / b^2) = 1
void Circle::Draw()
{

    float a2 = qAbs (start.x() - end.x()); // 2a
    float b2 = qAbs(start.y()-end.y()); // 2b
    float xMid = (start.x() + end.x()) * 0.5;
    float yMid = qAbs(start.y()+end.y())*0.5;

    for (int i = 0; i < 2*sizeOfPoint-1; i+=2) {
        vertices[i] =  start.x() + (a2/sizeOfPoint)*i/2;
        vertices[i+1] = -1*((b2/2) * qSqrt( 1- qPow((vertices[i]-xMid)/(a2/2),2) ) -yMid);
    }

    for (int i = 0; i < 2*sizeOfPoint-1; i+=2) {
        vertices[2*sizeOfPoint+i] =  end.x() - (a2/sizeOfPoint)*i/2;
        vertices[2*sizeOfPoint+i+1] = 1*((b2/2) * qSqrt( 1- qPow((vertices[i]-xMid)/(a2/2),2) ) +yMid);
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2,GL_FLOAT,0,vertices);

    glDrawArrays(GL_POLYGON,0,2*sizeOfPoint);

    glDisableClientState(GL_VERTEX_ARRAY);

}

void Circle::Update(QPointF _last)
{
end = _last;
}
