#include "Queen.h"

Queen::Queen(QWidget* parent) : Piece(parent)
{
    Icon.load("../ChessGame/Icons/Queen.png");
    this->setPixmap(Icon.scaled(20, 100, Qt::KeepAspectRatio));
}
