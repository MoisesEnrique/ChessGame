#include "Knight.h"

Knight::Knight(QWidget* parent, bool colour) : Piece(parent, colour)
{
    type = 'H';
    if (colour)
        Icon.load("../ChessGame/Icons/Knight_white.png");
    else
        Icon.load("../ChessGame/Icons/Knight_black.png");

    this->setPixmap(this->Icon.scaled(QSize(45,45), Qt::KeepAspectRatio));

}

bool Knight::shouldMove(QPoint& final)
{
    unsigned difC = std::abs(this->toNote()->toStdString()[0] - toNote(final)->toStdString()[0]);
    unsigned difR = std::abs(this->toNote()->toStdString()[1] - toNote(final)->toStdString()[1]);

    return ( (difC == 1) && (difR == 2) ) ||
           ( (difC == 2) && (difR == 1) ) ;

}
