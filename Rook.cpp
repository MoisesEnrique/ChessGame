#include "Rook.h"

Rook::Rook(QWidget* parent) : Piece(parent)
{
    Icon.load("../ChessGame/Icons/Rook.png");
    this->setPixmap(Icon.scaled(20,100, Qt::KeepAspectRatio));
}
