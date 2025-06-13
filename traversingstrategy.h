#ifndef TRAVERSINGSTRATEGY_H
#define TRAVERSINGSTRATEGY_H

#include "maze.h"
#include "micromouse.h"


class TraversingStrategy: public QObject
{
    Q_OBJECT
public:
    virtual bool traverse() = 0;
    void setMaze(Maze* _maze);
    void setMicromouse(Micromouse* _micromouse);
protected:
    Maze *maze;
    Micromouse *micromouse;
};

#endif // TRAVERSINGSTRATEGY_H
