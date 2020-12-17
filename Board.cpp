#include "Board.h"
#include "ui_Board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    BoardFig.load("../ChessGame/Icons/board.png");

    //darle memoria a las piezas   (padre donde se pone la pieza
    piece = std::make_unique<Queen>(this);
    piece->move(50,50);
    piece->show();

}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), BoardFig);
}

void Board::mousePressEvent(QMouseEvent* event)
{
    auto child = childAt(event->pos());

    if(child == nullptr)
    {
        return;
    }

    QByteArray data;
    QDataStream dataStream(&data, QIODevice::WriteOnly);
    dataStream << QPoint(event->pos() - child->pos());

    QMimeData* mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata", data);

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}
