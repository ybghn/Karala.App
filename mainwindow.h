#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>
#include <QMouseEvent>
#include <QPushButton>
#include "canvas.h"
#include "qobjectdefs.h"
#include "shapecounter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    ShapeCounter* shapeCounter;
    void CreateCanvas();
    void ConnectShapeButtons(); // Connect the button click event
    QVector<QPushButton*> shapeButtons;
    Canvas *canvas;
    Ui::MainWindow *ui;

public slots:
    void SelectTypeOfShape();


};
#endif // MAINWINDOW_H
