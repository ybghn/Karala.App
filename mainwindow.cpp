#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CreateCanvas();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateCanvas()
{
    canvas = new Canvas(this);
    canvas->show();
}

