#ifndef QUEEN_H
#define QUEEN_H

#include <QPixmap>
#include "Piece.h"

class Queen : public Piece
{
    Q_OBJECT
public:
    explicit Queen(QWidget* parent = nullptr, bool colour = true);
    bool shouldMove(QPoint& final);
    bool couldEat(QPoint& enemy) {return true;}
    bool couldNotEat(QPoint& enemy) {return true;}
};

#endif // QUEEN_H
