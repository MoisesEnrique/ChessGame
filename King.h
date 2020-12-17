#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <QPixmap>

class King : public Piece
{
    Q_OBJECT
public:
    explicit King(QWidget* parent = nullptr);
};

#endif // KING_H
