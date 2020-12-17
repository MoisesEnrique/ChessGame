#include "King.h"

King::King(QWidget* parent) : Piece(parent)
{
    Icon.load("../ChessGame/Icons/King.png");
    this->setPixmap(Icon.scaled(20,100, Qt::KeepAspectRatio));
}
