#ifndef MICROMOUSE_H
#define MICROMOUSE_H

#include <Direction.h>
#include <QGraphicsRectItem>


class Micromouse: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Micromouse();
public slots:
    void move(Direction direction);
};

#endif // MICROMOUSE_H
