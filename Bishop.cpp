#include "Bishop.h"

Bishop::Bishop(QWidget* parent, bool colour) : Piece(parent, colour)
{
    type = 'B';
    if (colour)
        Icon.load("../ChessGame/Icons/Bishop_white.png");
    else
        Icon.load("../ChessGame/Icons/Bishop_black.png");

    this->setPixmap(this->Icon.scaled(QSize(45,45), Qt::KeepAspectRatio));

}
