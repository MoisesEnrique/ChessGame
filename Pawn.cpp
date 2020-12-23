#include "Pawn.h"

Pawn::Pawn(QWidget* parent, bool colour) : Piece(parent, colour)
{
    type = 'P';
    if (colour){
        Icon.load("../ChessGame/Icons/Pawn_white.png");
    }
    else
        Icon.load("../ChessGame/Icons/Pawn_black.png");

    this->setPixmap(this->Icon.scaled(QSize(35,45), Qt::KeepAspectRatio));

}

Pawn::~Pawn()
{

}

bool Pawn::shouldMove(QPoint& final)
{
    unsigned difC = std::abs(this->toNote()->toStdString()[0] - toNote(final)->toStdString()[0]);
    unsigned difR = std::abs(this->toNote()->toStdString()[1] - toNote(final)->toStdString()[1]);

    if(this->colour)
    {
        if (this->toNote()->toStdString()[1] - toNote(final)->toStdString()[1] >= 1)
        {
            if ( (this->toNote()->toStdString()[1] == '7') && (difR == 2) && (difC != 2))
                return true;

            if (difR == 1)
                return true;

            return false;
        }

        return false;
    }

    else
    {
        if (this->toNote()->toStdString()[1] - toNote(final)->toStdString()[1] <= -1)
        {
            if ( (this->toNote()->toStdString()[1] == '2') && (difR == 2) && (difC != 2))
                return true;

            if (difR == 1)
                return true;

            return false;
        }

        return false;
    }

    return false;

}

bool Pawn::couldEat(QPoint& enemy)
{
    unsigned difC = std::abs(this->toNote()->toStdString()[0] - toNote(enemy)->toStdString()[0]);
    unsigned difR = std::abs(this->toNote()->toStdString()[1] - toNote(enemy)->toStdString()[1]);

    return difC == difR;

}

bool Pawn::couldNotEat(QPoint &enemy)
{
    unsigned difC = std::abs(this->toNote()->toStdString()[0] - toNote(enemy)->toStdString()[0]);
    unsigned difR = std::abs(this->toNote()->toStdString()[1] - toNote(enemy)->toStdString()[1]);

    if ((difR <= 2) && (difC == 0))
        return true;
    return false;
}
