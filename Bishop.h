#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <QPixmap>

class Bishop : public Piece
{
    Q_OBJECT
public:
    explicit Bishop(QWidget* parent = nullptr, bool colour = true);
};

#endif // BISHOP_H
