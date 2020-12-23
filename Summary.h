#ifndef SUMMARY_H
#define SUMMARY_H

#include <QWidget>
#include <QLabel>
#include <cmath>
#include <iostream>

namespace Ui {
class Summary;
}

class Summary : public QWidget
{
    Q_OBJECT
public:
    //QVector<std::shared_ptr<QLabel>> moves;
    bool rowOrColum{true};
public:
    explicit Summary(QWidget *parent = nullptr);
    ~Summary();

public slots:
    void printMoves(QPoint& final);
private:
    Ui::Summary *ui;

};

#endif // SUMMARY_H
