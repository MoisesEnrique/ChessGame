#include "Queen.h"

Queen::Queen(QWidget* parent, bool colour) : Piece(parent, colour)
{
    type = 'Q';
    if (colour)
        Icon.load("../ChessGame/Icons/Queen_white.png");
    else
        Icon.load("../ChessGame/Icons/Queen_black.png");

    this->setPixmap(this->Icon.scaled(QSize(45,45), Qt::KeepAspectRatio));

}
