#ifndef POINTS_H
#define POINTS_H

#include <QWidget>
#include "Player.h"
#include "Piece.h"

#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"

namespace Ui {
class Points;
}

class Points : public QWidget
{
    Q_OBJECT
public:
    std::shared_ptr<Player> player1{};
    std::shared_ptr<Player> player2{};

public:
    explicit Points(QWidget *parent = nullptr);
    ~Points();
    void drawPlayers();

public slots:
    void addPieces(char type, bool colour);

public:
    void addPiecePlayer1(char type);
    void addPiecePlayer2(char type);

private:
    Ui::Points *ui;
};

#endif // POINTS_H
