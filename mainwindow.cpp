#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->BoardWidget,&Board::removePieces, ui->PointsWidget, &Points::addPieces);
}

MainWindow::~MainWindow()
{
    delete ui;
}

