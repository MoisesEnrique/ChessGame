#include "Summary.h"
#include "ui_Summary.h"
#include <QVBoxLayout>

Summary::Summary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Summary)
{
    ui->setupUi(this);
    ui->logTable->setColumnCount(2);
    ui->logTable->setRowCount(0);
    ui->logTable->setColumnWidth(0,12);
    ui->logTable->horizontalHeader()->hide();
}

Summary::~Summary()
{
    delete ui;
}

void Summary::printMoves(QPoint& final)
{

    char x = std::ceil(final.x() / (450.f/8.f)) + 96;
    char y = std::ceil(final.y() / (450.f/8.f)) + 48;

    QTableWidgetItem* it = new QTableWidgetItem(QString(QChar(x)) + y);

    if(rowOrColum)
    {
        ui->logTable->setRowCount(ui->logTable->rowCount() + 1);
        ui->logTable->setItem(ui->logTable->rowCount() - 1, 0, it);
        rowOrColum = false;
    }
    else
    {
        ui->logTable->setItem(ui->logTable->rowCount() - 1, 1, it);
        rowOrColum = true;
    }

}
