#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <QPixmap>

class Knight : public Piece
{
    Q_OBJECT
public:
    explicit Knight(QWidget* parent = nullptr, bool colour = true);
    bool shouldMove(QPoint& final);
    bool couldEat(QPoint& enemy) {return true;}
    bool couldNotEat(QPoint& enemy) {return true;}
};

#endif // KNIGHT_H
