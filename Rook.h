#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
    Q_OBJECT
public:
    explicit Rook(QWidget* parent = nullptr, bool colour = true);
    bool shouldMove(QPoint& final);
    bool couldEat(QPoint& enemy) {return true;}
    bool couldNotEat(QPoint& enemy) {return true;}
};

#endif // ROOK_H
