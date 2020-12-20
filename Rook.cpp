#include "Rook.h"

Rook::Rook(QWidget* parent, bool colour) : Piece(parent, colour)
{
    if (colour)
        Icon.load("../ChessGame/Icons/Rook_white.png");
    else
        Icon.load("../ChessGame/Icons/Rook_black.png");

    this->setPixmap(this->Icon.scaled(QSize(45,45), Qt::KeepAspectRatio));

}
