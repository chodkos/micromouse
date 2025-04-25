#include <set>
#include <direction.h>
#ifndef TILE_H
#define TILE_H

class Tile
{
private:
    bool visited = false;
    std::set<Direction> walls;
    Tile previousTile();
    int previousX;
    int previousY;
public:
    Tile();
    void addDirection(Direction direction);
    std::set<Direction> getWalls();
    void createWalls(bool north, bool south, bool west, bool east);
    bool getVisited();
    void setVisited();
    Tile getPreviousTile();
    void setPreviousTile();

    int getPreviousX();
    int getPreviousY();

    void setPreviousX(int _x);
    void setPreviousY(int _y);
};

#endif // TILE_H
