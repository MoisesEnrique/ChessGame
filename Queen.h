#ifndef QUEEN_H
#define QUEEN_H

#include <QPixmap>
#include "Piece.h"

class Queen : public Piece
{
    Q_OBJECT
public:
    explicit Queen(QWidget* parent = nullptr, bool colour = true);
};

#endif // QUEEN_H
