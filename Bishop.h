#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <QPixmap>

class Bishop : public Piece
{
    Q_OBJECT
public:
    explicit Bishop(QWidget* parent = nullptr, bool colour = true);
    bool shouldMove(QPoint& final);
    bool couldEat(QPoint& enemy) {return true;}
    bool couldNotEat(QPoint& enemy) {return true;}
};

#endif // BISHOP_H
