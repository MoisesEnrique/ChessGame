#include "Piece.h"

Piece::Piece(QWidget* parent, bool _colour) : QLabel(parent), colour{_colour}
{

}

std::shared_ptr<QString> Piece::toNote()
{
    char x = std::ceil(this->coordinate.x() / (450.f/8.f)) + 96;
    char y = std::ceil(this->coordinate.y() / (450.f/8.f)) + 48;

    std::shared_ptr<QString> note = std::make_shared<QString>(QChar(x) + y);
    return note;
}

std::shared_ptr<QString> Piece::toNote(QPoint& coord)
{
    char x = std::ceil(coord.x() / (450.f/8.f)) + 96;
    char y = std::ceil(coord.y() / (450.f/8.f)) + 48;

    std::shared_ptr<QString> note = std::make_shared<QString>(QChar(x) + y);
    return note;
}
