#ifndef CANVAS_H
#define CANVAS_H

#include <QGLWidget>
#include <QGLFunctions>
#include <QDebug>
#include <QVector>
#include <QMouseEvent>
#include <QDebug>
#include <QPointF>
#include <QGLShaderProgram>
#include <QGLShader>
#include <QMatrix4x4>
#include "Shapes/shape.h"
#include "shapecounter.h"
enum DrawingState{
    None,Begin,Moving,End,Cancelled
};
enum ShapeTypes{
    EPoint,// painting with brush
    ELine,
    ETriangle,
    EBox,
    ECircle,
    EHexagon,
    EErase,
};
class Canvas : public QGLWidget , public  QGLFunctions
{
public:
    Canvas(ShapeCounter *shapeCtr,QWidget* _parent = nullptr);
    void AddNewShape(Shape *newShape);
 void SetTypeOfShape(QString _type);
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    void Draw();
    void DefaultShader();
    void CanvasMovement();

    DrawingState drawingState = None;
    ShapeTypes shape = EPoint;
    QVector<Shape*> shapes;
    ShapeCounter *shapeCounter;
    QGLShaderProgram *shaderProgram;
    QGLShader *vertexShader;
    QGLShader* fragmentShader;
    QMatrix4x4 canvasMatrix;
    float w,h;
    const char* fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                       "}\0";
    const char* vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "uniform mat4 canvasMatrix;"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = canvasMatrix*vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;




};

#endif // CANVAS_H
