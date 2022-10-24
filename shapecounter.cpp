#include "shapecounter.h"

ShapeCounter::ShapeCounter(Ui::MainWindow* _ui)
{
    ui =_ui;

    ui->lineCount->setText(QString::number(lineCount));
    ui->pointCount->setText(QString::number(penCount));
    ui->boxCount->setText(QString::number(boxCount));
    ui->crcleCount->setText(QString::number(circleCount));
    ui->triangleCount->setText(QString::number(triangleCouunt));
    ui->hexagonCount->setText(QString::number(hexagonCount));
}

void ShapeCounter::AddLine()
{
    lineCount++;
    ui->lineCount->setText(QString::number(lineCount));
}

void ShapeCounter::AddPen()
{
    penCount++;
    ui->pointCount->setText(QString::number(penCount));
}

void ShapeCounter::AddBox()
{
    boxCount++;
    ui->boxCount->setText(QString::number(boxCount));
}

void ShapeCounter::AddCircle()
{
    circleCount++;
    ui->crcleCount->setText(QString::number(circleCount));
}

void ShapeCounter::AddTriangle()
{
    triangleCouunt++;
    ui->triangleCount->setText(QString::number(triangleCouunt));

}

void ShapeCounter::AddHexagon()
{
    hexagonCount++;
    ui->hexagonCount->setText(QString::number(hexagonCount));
}
