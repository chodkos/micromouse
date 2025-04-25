#include "micromouse.h"

#include "properties.h"

Micromouse::Micromouse() {
    setRect(10,310,30,30);
}

void Micromouse::move(Direction direction) {
    switch (direction) {
    case Direction::NORTH:
        setPos(x(), y() - Properties::LENGTH);
        break;
    case Direction::SOUTH:
        setPos(x(), y() + Properties::LENGTH);
        break;
    case Direction::WEST:
        setPos(x() - Properties::LENGTH, y());
        break;
    case Direction::EAST:
        setPos(x() + Properties::LENGTH, y());
        break;
    default:
        break;
    }
}

