#ifndef MAP_H
#define MAP_H

#include <maze.h>

class Map
{
private:
    Maze maze;


public:
    Map();
    void drawMaze();
    void setMaze(Maze _maze) {
        maze = _maze;
    }
};

#endif // MAP_H
