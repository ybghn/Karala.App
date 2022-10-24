#include "hexagon.h"
#include <QDebug>
Hexagon::Hexagon(QPointF _start,QPointF _end)
{
    start =_start;
    end=_end;
    f =  QOpenGLContext::currentContext()->functions();



}

Hexagon::~Hexagon()
{



}

void Hexagon::Draw()
{
    CreateData();

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2,GL_FLOAT,0,vertices);
    glDrawArrays(GL_POLYGON,0,6);
    glDisableClientState(GL_VERTEX_ARRAY);

//    f =  QOpenGLContext::currentContext()->functions();

//f->glGenBuffers(1,&vbo);
//    f->glBindBuffer(GL_ARRAY_BUFFER,vbo);
//    f->glBufferData(GL_ARRAY_BUFFER,sizeof(float)*12,vertices,GL_DYNAMIC_DRAW);

//    f->glVertexAttribPointer(0,GL_ARRAY_BUFFER,GL_FLOAT,GL_FALSE,2*sizeof(float),vertices);


//     f->glDrawArrays( GL_LINE_LOOP,0,6);


//    f->glBindBuffer(GL_ARRAY_BUFFER,0);


}

void Hexagon::Update(QPointF _last)
{
    end = _last;
}

void Hexagon::CreateData()
{

    vertices[0] = start.x();
    vertices[1] = (start.y() + end.y())/2;

    vertices[2] = start.x()+    (end.x() - start.x()) /3;
    vertices[3] = end.y();

    vertices[4] =start.x() +2*(end.x() - start.x()) /3;
    vertices[5] = end.y();

    vertices[6] =end.x();
    vertices[7] =vertices[1];

    vertices[8] = vertices[4];
    vertices[9] = start.y();

    vertices[10] =vertices[2];
    vertices[11] = start.y();


}
