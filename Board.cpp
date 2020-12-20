#include "Board.h"
#include <memory>
#include <iostream>
#include <cmath>
#include "ui_Board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    BoardFig.load("../ChessGame/Icons/board.png");
    setAcceptDrops(true);
    drawPieces();

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

void Board::drawPieces()
{
    char type;

    for (int f = 0; f < BoardData.size(); ++f) {
        for (int c = 0; c < BoardData[f].size(); ++c) {
            type = BoardData[f][c];
            if (type != '0'){
                std::shared_ptr<Piece> newPiece = createPiece(type);
                if(newPiece->colour)
                    this->white_pieces.push_back(newPiece);
                else
                    this->black_pieces.push_back(newPiece);
                newPiece->setGeometry(c*55+10, f*55+10, 40, 45);
                newPiece->setCursor(Qt::PointingHandCursor);
                newPiece->show();

            }
        }
    }
}

std::shared_ptr<Piece> Board::createPiece (char type)
{
    std::shared_ptr<Piece> newPiece = std::make_shared<Pawn>(this, true);

    switch (type) {
    case 'R':
        newPiece = std::make_shared<Rook>(this, false);
        break;
    case 'H':
        newPiece = std::make_shared<Knight>(this, false);
        break;
    case 'B':
        newPiece = std::make_shared<Bishop>(this, false);
        break;
    case 'Q':
        newPiece = std::make_shared<Queen>(this, false);
        break;
    case 'K':
        newPiece = std::make_shared<King>(this, false);
        break;
    case 'P':
        newPiece = std::make_shared<Pawn>(this, false);
        break;
    case 'r':
        newPiece = std::make_shared<Rook>(this, true);
        break;
    case 'h':
        newPiece = std::make_shared<Knight>(this, true);
        break;
    case 'b':
        newPiece = std::make_shared<Bishop>(this, true);
        break;
    case 'q':
        newPiece = std::make_shared<Queen>(this, true);
        break;
    case 'k':
        newPiece = std::make_shared<Rook>(this, true);
        break;
    case 'p':
        newPiece = std::make_shared<Pawn>(this, true);
        break;
    }
    return newPiece;

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

    auto childP = static_cast<Piece*>(child);
    childP->coordinate = QPoint(child->pos().x(), child->pos().y());

    dataStream << QPoint(event->pos());

    QMimeData* mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata", data);

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}

void Board::dragMoveEvent(QDragMoveEvent* event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Board::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }

}

void Board::dropEvent(QDropEvent* e)
{
    if (e->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = e->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPoint offset; // posición de donde se hizo click
        dataStream >> offset;

        Piece* p = static_cast<Piece*>(childAt(offset));

        //if (p->coordinate == )
        QPoint n = e->pos() - offset + p->coordinate;

        int newX = ((n.x())/ 55) * 55 + 10;
        int newY = ((n.y())/ 55) * 55 + 10;

        QPoint newPosition(newX, newY);

        //std::cout << p->coordinate.x() << ", " << p->coordinate.y() << std::endl;
        //std::cout << "to " << newPosition.x() << ", " <<newPosition.y() << std::endl;


        if (p->coordinate != newPosition)
        {
            std::cout << "Lo hace" << std::endl;
            p->move(newPosition);
            p->coordinate = newPosition;
            p->show();

            for(int i = 0; i < white_pieces.size(); ++i)
            {
                if ( (std::abs(white_pieces[i]->x() - p->coordinate.x()) <= 2)
                     && (std::abs(white_pieces[i]->y() - p->coordinate.y()) <= 2))
                {
                    white_pieces.removeAt(i);
                    break;
                }
            }

        }else if (p->coordinate == newPosition){
            std::cout << "no lo hace" << std::endl;
        }


        if (e->source() == this) {
            e->setDropAction(Qt::MoveAction);
            e->accept();
        } else {
            e->acceptProposedAction();
        }
    } else {
        e->ignore();
    }
}
