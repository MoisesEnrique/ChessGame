#include "Bishop.h"

Bishop::Bishop(QWidget* parent) : Piece(parent)
{
    Icon.load("../ChessGame/Icons/Bishop.png");
    this->setPixmap(Icon.scaled(20,100, Qt::KeepAspectRatio));
}
