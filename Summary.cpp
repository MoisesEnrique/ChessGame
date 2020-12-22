#include "Summary.h"
#include "ui_Summary.h"

Summary::Summary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Summary)
{
    ui->setupUi(this);

    //player = std::make_shared<Player>(ui->scrollAreaWidgetContents);
    //player->setGeometry(0,200, 50, 50);
    //player->show();

    //ui->scrollAreaWidgetContents->resize(201,40);

    ui->SummaryMoves->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //ui->SummaryMoves->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


}

Summary::~Summary()
{
    delete ui;
}
