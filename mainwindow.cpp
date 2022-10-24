#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{



    ui->setupUi(this);
    shapeCounter = new ShapeCounter(ui);
    ConnectShapeButtons();
    CreateCanvas();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateCanvas()
{
    canvas = new Canvas(shapeCounter,this);
    canvas->show();
}

void MainWindow::ConnectShapeButtons()
{
    QObject::connect(ui->lineBtn,&QPushButton::clicked,this,&MainWindow::SelectTypeOfShape);
    QObject::connect(ui->boxBtn,&QPushButton::clicked,this,&MainWindow::SelectTypeOfShape);
    QObject::connect(ui->circleBtn,&QPushButton::clicked,this,&MainWindow::SelectTypeOfShape);
    QObject::connect(ui->penBtn,&QPushButton::clicked,this,&MainWindow::SelectTypeOfShape);
    QObject::connect(ui->tirangleBtn,&QPushButton::clicked,this,&MainWindow::SelectTypeOfShape);
    QObject::connect(ui->hexagonBtn,&QPushButton::clicked,this,&MainWindow::SelectTypeOfShape);

}

void MainWindow::SelectTypeOfShape()
{
    auto tempBtn = (QPushButton*)sender();
    if(tempBtn)
    {

        canvas->SetTypeOfShape(tempBtn->text());

    }
}


