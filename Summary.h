#ifndef SUMMARY_H
#define SUMMARY_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class Summary;
}

class Summary : public QWidget
{
    Q_OBJECT
public:
    QVector<std::shared_ptr<QLabel>> movPlayer1;
    QVector<std::shared_ptr<QLabel>> movPlayer2;

public:
    explicit Summary(QWidget *parent = nullptr);
    ~Summary();

public slots:
    void printMoves(QPoint start, QPoint final);

private:
    Ui::Summary *ui;

};

#endif // SUMMARY_H
