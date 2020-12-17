#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <QPixmap>

class Pawn : public Piece
{
    Q_OBJECT
public:
    explicit Pawn(QWidget* parent = nullptr);
};


#endif // PAWN_H
