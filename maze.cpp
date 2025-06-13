#include "maze.h"
#include <cmath>
#include <iostream>


Maze::Maze() {}

int Maze::getColumns()
{
    return columns;
}

void Maze::createMaze(QVector<QString> data)
{
    std::vector<std::vector<Tile>> map;
    int length = std::sqrt(data.length());
    columns = length;
    for (int var = 0; var < length; ++var) {
        std::vector<Tile> vect;
        for (int i = 0; i < length; ++i) {
            Tile t;
            vect.push_back(t);
        }
        map.push_back(vect);
    }



    for (int i = 0; i < data.size(); ++i) {
        QStringList row = data[i].split(" ");
        /*!
         * kazdy rzad w pliku ma 6 cyfr
         * 2 pierwsze to wspolrzedne kafelka
         * 4 kolejne to cyfry wskazujace na obecnos sciany w danym kierunku
         * przykladowo: 3 2 1 0 0 0 - na kafelku o wspolrzednych x = 3, y = 2 jest tylko scianka na gorze
         */
        Tile * tile = &map[row[0].toInt()][row[1].toInt()];
        tile->createWalls(row[2] == '1', row[3] == '1', row[4] == '1', row[5] == '1');
    }

    mapTap = map;
    currentX = 0;
    currentY = map[0].size() - 1;
}

std::vector<std::vector<Tile> > Maze::getMap()
{
    return mapTap;
}

int Maze::getCurrentX()
{
    return currentX;
}

int Maze::getCurrentY()
{
    return currentY;
}

void Maze::setCurrentX(int _x)
{
    currentX = _x;
}

void Maze::setCurrentY(int _y)
{
    currentY = _y;
}

Tile * Maze::getCurrentTile()
{
    return &mapTap[currentX][currentY];
}

void Maze::updateCurrentTile(Tile tile)
{
    mapTap[currentX][currentY] = tile;
}

void Maze::isNotOnStartingTile()
{
    isOnStaringTile = false;
}

bool Maze::getIsOnStartingTile()
{
    return isOnStaringTile;
}

int Maze::getCenterColumn()
{
    return centerColumn;
}

int Maze::getCenterRow()
{
    return centerRow;
}

