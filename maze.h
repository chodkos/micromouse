#ifndef MAZE_H
#define MAZE_H

#include "qobject.h"
#include <vector>
#include <tile.h>

class Maze
{
private:
    int columns = 0;
    int rows = 0;
    int centerColumn = 0;
    int centerRow = 0;
    std::vector<std::vector<Tile>> mapTap;
    Tile * currentTile;
    int currentX;
    int currentY;
    bool isOnStaringTile = true;
public:
    Maze();

    Tile getTile(int col, int row);
    bool isCenter(int col, int row);
    int getColumns();
    int getRows();
    void createMaze(QVector<QString> data);
    std::vector<std::vector<Tile>> getMap();
    int getCurrentX();
    int getCurrentY();
    void setCurrentX(int _x);
    void setCurrentY(int _y);
    Tile * getCurrentTile();
    void updateCurrentTile(Tile tile);
    Tile getCurr();
    void isNotOnStartingTile();
    bool getIsOnStartingTile();
};

#endif // MAZE_H
