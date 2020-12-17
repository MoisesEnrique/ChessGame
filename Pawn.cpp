#include "Pawn.h"

Pawn::Pawn(QWidget* parent) : Piece(parent)
{
    Icon.load("../ChessGame/Icons/Pawn.png");
    this->setPixmap(Icon.scaled(20,100, Qt::KeepAspectRatio));
}
