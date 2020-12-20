#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <memory>
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include <QtWidgets>

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget* parent = nullptr);
    ~Board();

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;

    void drawPieces();
    std::shared_ptr<Piece> createPiece(char type);

private:
    QPixmap BoardFig;
    Ui::Board *ui;
    QVector<QVector<char>> BoardData{
        {'R','H','B','Q','K','B','H','R'},
        {'P','P','P','P','P','P','P','P'},
        {'x','x','x','x','x','x','x','x'},
        {'x','x','x','x','x','x','x','x'},
        {'x','x','x','x','x','x','x','x'},
        {'x','x','x','x','x','x','x','x'},
        {'p','p','p','p','p','p','p','p'},
        {'r','h','b','k','q','b','h','r'}
    };

    QVector<std::shared_ptr<Piece>> Pieces{};

    //QVector<std::shared_ptr<Piece>> black_pieces{};
    //QVector<std::shared_ptr<Piece>> white_pieces{};

};

#endif // BOARD_H
