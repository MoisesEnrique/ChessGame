#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <QPixmap>

class Knight : public Piece
{
    Q_OBJECT
public:
    explicit Knight(QWidget* parent = nullptr, bool colour = true);
};

#endif // KNIGHT_H
