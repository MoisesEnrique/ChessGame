#include "Rook.h"

Rook::Rook(QWidget* parent, bool colour) : Piece(parent, colour)
{
    type = 'R';
    if (colour)
        Icon.load("../ChessGame/Icons/Rook_white.png");
    else
        Icon.load("../ChessGame/Icons/Rook_black.png");

    this->setPixmap(this->Icon.scaled(QSize(45,45), Qt::KeepAspectRatio));

}

bool Rook::shouldMove(QPoint& final)
{
    unsigned difC = std::abs(this->toNote()->toStdString()[0] - toNote(final)->toStdString()[0]);
    unsigned difR = std::abs(this->toNote()->toStdString()[1] - toNote(final)->toStdString()[1]);

    return ( difR == 0 ) ||
           ( difC == 0 ) ;
}
