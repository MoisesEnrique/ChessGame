#include "King.h"

King::King(QWidget* parent, bool colour) : Piece(parent, colour)
{
    type = 'K';
    if (colour)
        Icon.load("../ChessGame/Icons/King_white.png");
    else
        Icon.load("../ChessGame/Icons/King_black.png");

    this->setPixmap(this->Icon.scaled(QSize(45,45), Qt::KeepAspectRatio));

}
