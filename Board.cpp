#include "Board.h"
#include "ui_Board.h"
#include <memory>
#include <iostream>
#include <cmath>
#include "Points.h"

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

std::shared_ptr<QString> Board::toNote(QPoint& coord)
{
    char x = std::ceil(coord.x() / (450.f/8.f)) + 96;
    char y = std::ceil(coord.y() / (450.f/8.f)) + 48;

    std::shared_ptr<QString> note = std::make_shared<QString>(QChar(x) + y);
    return note;
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), BoardFig);
}

void Board::drawCells()
{
    for (int f = 0; f < 8; ++f) {
        for (int c = 0; c < 8; ++c) {
            std::shared_ptr<QLabel> newCell = std::make_shared<QLabel>(this);
            this->Cells.push_back(newCell);
            newCell->setGeometry(c*55+10, f*55+10, 40, 45);
        }
    }
}

void Board::drawPieces()
{
    char type;

    for (int f = 0; f < BoardData.size(); ++f) {
        for (int c = 0; c < BoardData[f].size(); ++c) {
            type = BoardData[f][c];
            if (type != 'x'){
                std::shared_ptr<Piece> newPiece = createPiece(type);
                this->Pieces.push_back(newPiece);
                newPiece->setGeometry(c*55+10, f*55+10, 40, 45);
                newPiece->setAlignment(Qt::AlignHCenter);
                newPiece->setCursor(Qt::PointingHandCursor);
                newPiece->show();

            }
        }
    }
}

std::shared_ptr<Piece> Board::createPiece (char type)
{
    std::shared_ptr<Piece> newPiece = nullptr;

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
        newPiece = std::make_shared<King>(this, true);
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

    if(child == nullptr || !(dynamic_cast<Piece*>(child)))
    {
        return;
    }

    auto childP = dynamic_cast<Piece*>(child);
    childP->coordinate = QPoint(child->pos().x(), child->pos().y());

    QByteArray data;
    QDataStream dataStream(&data, QIODevice::WriteOnly);
    dataStream << QPoint(event->pos());

    QMimeData* mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata", data);

    QDrag* drag = new QDrag(this);
    QPixmap pixmap = childP->pixmap(Qt::ReturnByValue);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - childP->pos());
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
        QPoint n = e->pos() - offset + p->coordinate;

        int newX = ((n.x())/ 55) * 55 + 10;
        int newY = ((n.y())/ 55) * 55 + 10;

        QPoint newPosition(newX, newY);

        bool flag = false;
        int i;

        if ( (p->coordinate != newPosition) && (p->shouldMove(newPosition)) )
        {

            for(i = 0; i < Pieces.size(); ++i) {
                if ( (std::abs(Pieces[i]->x() - newPosition.x()) <= 2)
                     && (std::abs(Pieces[i]->y() - newPosition.y()) <= 2)) {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                if(Pieces[i]->colour != p->colour)
                {
                    if (p->couldEat(newPosition))
                    {
                        emit printMoves(newPosition);
                        emit removePieces(Pieces[i]->type, Pieces[i]->colour);
                        p->move(newPosition);
                        p->coordinate = newPosition;
                        Pieces.removeAt(i);
                    }
                }
            }
            else
            {
                if (p->couldNotEat(newPosition))
                {
                    emit printMoves(newPosition);
                    p->move(newPosition);
                    p->coordinate = newPosition;
                }
            }

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
