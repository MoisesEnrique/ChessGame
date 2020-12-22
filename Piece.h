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
public:
    QPixmap Icon;
    char type{};
public:
    bool colour;
    QPoint coordinate{};

public:
    explicit Piece(QWidget* parent = nullptr, bool _colour = true);

};

#endif // PIECE_H
