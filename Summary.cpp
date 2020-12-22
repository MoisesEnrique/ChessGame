#include "Summary.h"
#include "ui_Summary.h"

Summary::Summary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Summary)
{
    ui->setupUi(this);
}

Summary::~Summary()
{
    delete ui;
}

void Summary::printMoves(QPoint& final)
{

    if (moves.size() % 3 == 0){
        std::shared_ptr<QLabel> number = std::make_shared<QLabel>(ui->scrollAreaWidgetContents);
        number->setText(QString(QChar(moves.size()/2 + 1 + 48)) + QString(QChar(46)));
        number->setGeometry(0, 17*moves.size()/3, 25, 17);
        number->show();

        moves.push_back(number);
    }

    char x = std::ceil(final.x() / (450.f/8.f)) + 96;
    char y = std::ceil(final.y() / (450.f/8.f)) + 48;

    std::shared_ptr<QLabel> move = std::make_shared<QLabel>(ui->scrollAreaWidgetContents);
    move->setText(QString(QChar(x)) + y);
    move->setGeometry(25*(moves.size()%3), 17*std::floor(moves.size()/3), 25, 17);
    move->show();

    moves.push_back(move);
}
