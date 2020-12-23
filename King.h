#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <QPixmap>

class King : public Piece
{
    Q_OBJECT
public:
    explicit King(QWidget* parent = nullptr, bool colour = true);
    bool shouldMove(QPoint& final);
    bool couldEat(QPoint& enemy) {return true;}
    bool couldNotEat(QPoint& enemy) {return true;}
};

#endif // KING_H
