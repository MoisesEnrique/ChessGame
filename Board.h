#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <memory>
#include "Piece.h"
#include "Queen.h"
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

private:
    QPixmap BoardFig;
    Ui::Board *ui;

    std::unique_ptr<Piece> piece;

    void mousePressEvent(QMouseEvent* event) override;

};

#endif // BOARD_H
