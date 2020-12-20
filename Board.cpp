#include "Board.h"
#include <memory>
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
                //newPiece->move(c*55.f+10.f, f*56.f+10.f);
                newPiece->setGeometry(c*55.f+10.f, f*56.f+10.f, 47, 47);
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
    //dataStream << QPoint(event->pos() - child->pos());
    dataStream << QPoint(child->pos());

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

void Board::dropEvent(QDropEvent* event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPoint offset;
        dataStream >> offset;

        Piece* p = (Piece*) childAt(offset);
        int xPos = ((event->pos().x())/ 55) * 55 + 10;
        int yPos = ((event->pos().y())/ 55) * 55 + 10;

        QPoint destinyPoint(xPos, yPos);
        p->move(destinyPoint);

        //piece->move(event->pos() - offset);

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
