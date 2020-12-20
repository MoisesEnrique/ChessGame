#include "Pawn.h"
#include <iostream>

Pawn::Pawn(QWidget* parent, bool colour) : Piece(parent, colour)
{
    if (colour){
        Icon.load("../ChessGame/Icons/Pawn_white.png");
    }
    else
        Icon.load("../ChessGame/Icons/Pawn_black.png");

    this->setPixmap(this->Icon.scaled(QSize(35,45), Qt::KeepAspectRatio));

}

Pawn::~Pawn()
{

}
