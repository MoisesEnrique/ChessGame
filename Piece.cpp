#include "Piece.h"

Piece::Piece(QWidget* parent, bool _colour) : QLabel(parent), colour{_colour}
{
    //this->setScaledContents(true);
    //this->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    //this->setText("Queen");
    //en las clases derivadas
    /*
     * Icon.load("../");
     * this->setPixmap(Icon);
    */
}
