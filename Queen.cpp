#include "Queen.h"

Queen::Queen(QWidget* parent, bool colour) : Piece(parent, colour)
{
    type = 'Q';
    if (colour)
        Icon.load("../ChessGame/Icons/Queen_white.png");
    else
        Icon.load("../ChessGame/Icons/Queen_black.png");

    this->setPixmap(this->Icon.scaled(QSize(45,45), Qt::KeepAspectRatio));

}

bool Queen::shouldMove(QPoint& final)
{
    unsigned difC = std::abs(this->toNote()->toStdString()[0] - toNote(final)->toStdString()[0]);
    unsigned difR = std::abs(this->toNote()->toStdString()[1] - toNote(final)->toStdString()[1]);

    return ( difC == difR) ||
           ( difR == 0 ) ||
           ( difC == 0 );

}
