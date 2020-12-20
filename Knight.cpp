#include "Knight.h"

Knight::Knight(QWidget* parent, bool colour) : Piece(parent, colour)
{
    if (colour)
        Icon.load("../ChessGame/Icons/Knight_white.png");
    else
        Icon.load("../ChessGame/Icons/Knight_black.png");

    this->setPixmap(this->Icon.scaled(QSize(45,45), Qt::KeepAspectRatio));

}
