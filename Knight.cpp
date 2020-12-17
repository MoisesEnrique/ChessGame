#include "Knight.h"

Knight::Knight(QWidget* parent) : Piece(parent)
{
    Icon.load("../ChessGame/Icons/Knight.png");
    this->setPixmap(Icon.scaled(20,100, Qt::KeepAspectRatio));
}
