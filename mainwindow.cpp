#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->BoardWidget,&Board::printMoves, ui->SummaryWidget, &Summary::printMoves);
    connect(ui->BoardWidget,&Board::removePieces, ui->PointsWidget, &Points::addPieces);
   // connect(ui->SummaryWidget,&Summary::OnClickSalir, ui->BoardWidget, &Board::OnClickSalir);
}

MainWindow::~MainWindow()
{
    delete ui;
}

