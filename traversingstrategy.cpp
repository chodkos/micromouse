#include "traversingstrategy.h"

bool TraversingStrategy::traverse()
{
    return false;
}

void TraversingStrategy::setMaze(Maze* _maze)
{
    maze = _maze;
}

void TraversingStrategy::setMicromouse(Micromouse &_micromouse)
{
    micromouse = &_micromouse;
}
