#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include <QPixmap>

namespace Ui {
class Piece;
}

class Piece : public QLabel
{
    Q_OBJECT
protected:
    QPixmap Icon;

public:
    explicit Piece(QWidget* parent = nullptr);

    //funciones de la pieza
};

#endif // PIECE_H
