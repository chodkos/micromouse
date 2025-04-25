#ifndef TRAVERSINGSTRATEGY_H
#define TRAVERSINGSTRATEGY_H

#include "maze.h"
#include "micromouse.h"


class TraversingStrategy
{
public:
    bool traverse();
    void setMaze(Maze* _maze);
    void setMicromouse(Micromouse &_micromouse);
protected:
    Maze *maze;
    Micromouse *micromouse;
};

#endif // TRAVERSINGSTRATEGY_H
