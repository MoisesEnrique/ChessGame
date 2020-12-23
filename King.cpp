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

bool King::shouldMove(QPoint& final)
{
    unsigned difC = std::abs(this->toNote()->toStdString()[0] - toNote(final)->toStdString()[0]);
    unsigned difR = std::abs(this->toNote()->toStdString()[1] - toNote(final)->toStdString()[1]);

    if ( ( (difC == 1) && (difR == 0) ) ||
         ( (difC == 0) && (difR == 1) ) ||
         ( (difC == 1) && (difR == 1) ) )
    {
        return true;
    }

    return false;

}
