#include "painter.h"

Painter::Painter() {}

QGraphicsLineItem* Painter::drawLine(int x, int y, int length, Direction direction)
{
    QGraphicsLineItem * line = new QGraphicsLineItem();
    switch (direction) {
    case Direction::NORTH:
        line->setLine(length*x,length*y + 5, length*x+length,length*y + 5);
        break;
    case Direction::SOUTH:
        line->setLine(length*x,length*y+length-2, length*x+length,length*y+length-2);
        break;
    case Direction::WEST:
        line->setLine(length*x+5,length*y, length*x+5,length*y+length);
        break;
    case Direction::EAST:
        line->setLine(length*x+length-2,length*y, length*x+length-2,length*y+length);
        break;
    default:
        break;
    }
    return line;
}
