#include "tile.h"
#include <iostream>

Tile::Tile() {}

void Tile::addDirection(Direction direction)
{
    walls.insert(direction);
}

std::set<Direction> Tile::getWalls()
{
    return walls;
}

void Tile::createWalls(bool north, bool south, bool west, bool east)
{
    if(north) addDirection(Direction::NORTH);
    if(south) addDirection(Direction::SOUTH);
    if(west) addDirection(Direction::WEST);
    if(east) addDirection(Direction::EAST);
}

bool Tile::getVisited()
{
    return visited;
}

void Tile::setVisited()
{
    visited = true;
}

int Tile::getPreviousX()
{
    return previousX;
}

int Tile::getPreviousY()
{
    return previousY;
}

void Tile::setPreviousX(int _x)
{
    previousX = _x;
}

void Tile::setPreviousY(int _y)
{
    previousY = _y;
}

