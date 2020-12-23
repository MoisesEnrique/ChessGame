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

bool Bishop::shouldMove(QPoint& final)
{
    unsigned difC = std::abs(this->toNote()->toStdString()[0] - toNote(final)->toStdString()[0]);
    unsigned difR = std::abs(this->toNote()->toStdString()[1] - toNote(final)->toStdString()[1]);

    if (difC == difR)
    {
        return true;
    }
    return false;

}
