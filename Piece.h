#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include <QPixmap>
#include <cmath>

namespace Ui {
class Piece;
}

class Piece : public QLabel
{
    Q_OBJECT
public:
    QPixmap Icon;
    char type{};
    bool colour;
    QPoint coordinate{};

public:
    explicit Piece(QWidget* parent = nullptr, bool _colour = true);
    std::shared_ptr<QString> toNote();
};

#endif // PIECE_H
