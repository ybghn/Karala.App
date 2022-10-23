#include "canvas.h"
#include "Shapes/line.h"
#include "Shapes/box.h"
#include "Shapes/triangle.h"
#include "Shapes/circle.h"
#include "Shapes/point.h"

#define initPos event->localPos(),event->localPos()

Canvas::Canvas(QWidget* _parent)
{
    setParent(_parent);
    QRect geometry(QPoint(200,50),QSize(512,512));
    setGeometry(geometry);
    w = geometry.width();
    h = geometry.height();
    qDebug() << this->geometry();
}

void Canvas::initializeGL()
{

    DefaultShader();
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2,0.2,0.2,1);
//    glMatrixMode(GL_MODELVIEW); // why ?


}

void Canvas::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);

}

void Canvas::paintGL()
{
    qDebug() << "paintGL Function ";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    CanvasMovement();
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    shaderProgram->bind();
    glLineWidth(5);
    Draw();

}

void Canvas::Draw()
{

    qDebug() << shapes.length();
    for (auto *shape : qAsConst(shapes)) {
        shape->Draw();
    }
}


void Canvas::AddNewShape(Shape * newShape)
{
    shapes.append(newShape);
}


// Mouse Events
void Canvas::mousePressEvent(QMouseEvent *event)
{
    drawingState = Moving;
    switch (shape) {
    case ELine:
    {
        Line * line = new Line(initPos);
        AddNewShape(line);
        drawingState = Moving;
        break;
    }
    case EBox:
    {
        Box* box = new Box(initPos);
        AddNewShape(box);
        drawingState =Moving;
        break;
    }
    case ETriangle:
    {
        Triangle *triangle = new Triangle(initPos);
        AddNewShape(triangle);
        drawingState = Moving;
        break;
    }
    case ECircle:
    {
        Circle *circle = new Circle(initPos);
        AddNewShape(circle);
        drawingState = Moving;
        break;
    }
    case EPoint:
    {
        Point * point = new Point(initPos);
        AddNewShape(point);
        drawingState = Moving;
        break;
    }
    default:
        break;
    }
}
void Canvas::mouseMoveEvent(QMouseEvent *event)
{

    if (drawingState == Moving)
    {
        shapes.last()->Update(event->localPos());
        qDebug()<< event->localPos();
    }
    updateGL();


}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {

        if(drawingState == Moving)
        {

            drawingState = End;
        }
        updateGL();
    }

}


void Canvas::DefaultShader()
{

    qDebug() << "Shaders are creating ...";
    vertexShader= new QGLShader(QGLShader::Vertex) ;
    vertexShader->compileSourceCode(vertexShaderSource);

    qDebug() << "Vertex Shader Log : " << vertexShader->log();

    fragmentShader= new QGLShader(QGLShader::Fragment) ;
    fragmentShader->compileSourceCode(fragmentShaderSource);
    qDebug() << "fragment Shader Log : " << fragmentShader->log();

    shaderProgram = new QGLShaderProgram();

    shaderProgram->addShader(vertexShader);
    shaderProgram->addShader(fragmentShader);
    shaderProgram->link();
    qDebug()<< "Shader status : "<< shaderProgram->log();
//    shaderProgram->bind();



}

void Canvas::CanvasMovement()
{
    QMatrix4x4 model ,view,projection;
    model.setToIdentity();
    view.setToIdentity();
    view.translate(QVector3D(0,0,-100));



    //    view.lookAt(QVector3D(0,0,-100),QVector3D(0,0,0),QVector3D(0,1,0));
    projection.setToIdentity();
    projection.ortho(0,w,h,0,0.1,101);

    canvasMatrix = projection*view*model;
    shaderProgram->setUniformValue(shaderProgram->uniformLocation("canvasMatrix"),canvasMatrix);



}
