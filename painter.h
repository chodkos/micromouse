#ifndef PAINTER_H
#define PAINTER_H

#include <Direction.h>
#include <qgraphicsitem.h>


class Painter
{
public:
    Painter();
    QGraphicsLineItem *drawLine(int x, int y, int length, Direction direction);
    QGraphicsRectItem *drawRect(int x, int y, int size);
};

#endif // PAINTER_H
