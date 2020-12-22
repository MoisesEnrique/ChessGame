#ifndef PLAYER_H
#define PLAYER_H

#include <QLabel>
#include <QPixmap>
#include "Piece.h"

class Player : public QLabel
{
    Q_OBJECT
protected:
    QPixmap Icon;
public:
    QVector<std::shared_ptr<Piece>> Pieces{};

public:
    explicit Player(QWidget* parent = nullptr);
};

#endif // PLAYER_H
