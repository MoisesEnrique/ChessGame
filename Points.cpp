#include "Points.h"
#include "ui_Points.h"

#include <iostream>

Points::Points(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Points)
{
    ui->setupUi(this);

    drawPlayers();
}

Points::~Points()
{
    delete ui;
}

void Points::drawPlayers()
{
    player1 = std::make_shared<Player>(this);
    player1->setGeometry(40, 30, 50, 50);
    player1->show();

    player2 = std::make_shared<Player>(this);
    player2->setGeometry(40, 401, 50, 50);
    player2->show();
}

void Points::addPiecePlayer1(char type)
{
    std::shared_ptr<Piece> removedPiece;
    switch (type) {
    case 'R':
        removedPiece = std::make_shared<Rook>(ui->ListPiecesPlayer1, true);
        break;
    case 'B':
        removedPiece = std::make_shared<Bishop>(ui->ListPiecesPlayer1, true);
        break;
    case 'H':
        removedPiece = std::make_shared<Knight>(ui->ListPiecesPlayer1, true);
        break;
    case 'K':
        removedPiece = std::make_shared<King>(ui->ListPiecesPlayer1, true);
        break;
    case 'Q':
        removedPiece = std::make_shared<Queen>(ui->ListPiecesPlayer1, true);
        break;
    case 'P':
        removedPiece = std::make_shared<Pawn>(ui->ListPiecesPlayer1, true);
        break;
    default:
        break;
    }

    removedPiece->setPixmap(removedPiece->Icon.scaled(QSize(25,25), Qt::KeepAspectRatio));
    removedPiece->setGeometry((player1->DeadPieces.size()%6)*30, (player1->DeadPieces.size()/6)*30, 30, 30);
    removedPiece->show();

    this->player1->DeadPieces.push_back(removedPiece);

}

void Points::addPiecePlayer2(char type)
{
    std::shared_ptr<Piece> removedPiece;
    switch (type) {
    case 'R':
        removedPiece = std::make_shared<Rook>(ui->ListPiecesPlayer2, false);
        break;
    case 'B':
        removedPiece = std::make_shared<Bishop>(ui->ListPiecesPlayer2, false);
        break;
    case 'H':
        removedPiece = std::make_shared<Knight>(ui->ListPiecesPlayer2, false);
        break;
    case 'K':
        removedPiece = std::make_shared<King>(ui->ListPiecesPlayer2, false);
        break;
    case 'Q':
        removedPiece = std::make_shared<Queen>(ui->ListPiecesPlayer2, false);
        break;
    case 'P':
        removedPiece = std::make_shared<Pawn>(ui->ListPiecesPlayer2, false);
        break;
    default:
        break;
    }

    removedPiece->setPixmap(removedPiece->Icon.scaled(QSize(25,25), Qt::KeepAspectRatio));
    removedPiece->setGeometry((player2->DeadPieces.size()%6)*30, (player2->DeadPieces.size()/6)*30, 30, 30);
    removedPiece->show();

    this->player2->DeadPieces.push_back(removedPiece);
}

void Points::addPieces(char type, bool colour)
{
    if (colour)
        addPiecePlayer1(type);
    else
        addPiecePlayer2(type);
}
