#include "Player.h"

Player::Player(QWidget* parent) : QLabel(parent)
{
    Icon.load("../ChessGame/Icons/Player.jpg");
    this->setPixmap(this->Icon.scaled(QSize(50,50), Qt::KeepAspectRatio));
}
