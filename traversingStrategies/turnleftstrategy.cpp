#include "turnleftstrategy.h"
#include <iostream>
TurnLeftStrategy::TurnLeftStrategy() {}

bool TurnLeftStrategy::traverse()
{


    Tile * currentTile = maze->getCurrentTile();

    if(maze->getCurrentX() == maze->getCenterColumn() && maze->getCurrentY() == maze->getCenterRow()) {
        return false;
    }

    if(maze->getIsOnStartingTile() || currentTile->getPreviousX() == maze->getCurrentX() -1) {
        if(currentTile->getWalls().count(Direction::NORTH) == 0) {
            micromouse->move(Direction::NORTH);
            maze->setCurrentY(maze->getCurrentY() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() + 1);
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::EAST) == 0) {
            micromouse->move(Direction::EAST);
            maze->setCurrentX(maze->getCurrentX() + 1);


            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() - 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else if (currentTile->getWalls().count(Direction::SOUTH) == 0) {
            micromouse->move(Direction::SOUTH);
            maze->setCurrentY(maze->getCurrentY() +1);

            currentTile->setPreviousX(maze->getCurrentX());
            currentTile->setPreviousY(maze->getCurrentY() - 1);
            maze->updateCurrentTile(*currentTile);
        } else {
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            currentTile->setPreviousX(maze->getCurrentX() + 1);
            currentTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*currentTile);
        }

    } else if(currentTile->getPreviousX() == maze->getCurrentX() + 1) {
        if (currentTile->getWalls().count(Direction::SOUTH) == 0) {
            micromouse->move(Direction::SOUTH);
            maze->setCurrentY(maze->getCurrentY() +1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() - 1);
            maze->updateCurrentTile(*nextTile);
        } else if (currentTile->getWalls().count(Direction::WEST) == 0) {
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() + 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::NORTH) == 0) {
            micromouse->move(Direction::NORTH);
            maze->setCurrentY(maze->getCurrentY() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() + 1);
            maze->updateCurrentTile(*nextTile);
        } else {
            micromouse->move(Direction::EAST);
            maze->setCurrentX(maze->getCurrentX() + 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() - 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        }
    } else if(currentTile->getPreviousY() == maze->getCurrentY() + 1) {
        if(currentTile->getWalls().count(Direction::WEST) == 0) {
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() + 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::NORTH) == 0) {
            micromouse->move(Direction::NORTH);
            maze->setCurrentY(maze->getCurrentY() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() + 1);
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::EAST) == 0) {
            micromouse->move(Direction::EAST);
            maze->setCurrentX(maze->getCurrentX() + 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() - 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else {
            micromouse->move(Direction::SOUTH);
            maze->setCurrentY(maze->getCurrentY() +1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() - 1);
            maze->updateCurrentTile(*nextTile);
        }
    } else if(currentTile->getPreviousY() == maze->getCurrentY() - 1) {
        if(currentTile->getWalls().count(Direction::EAST) == 0) {
            micromouse->move(Direction::EAST);
            maze->setCurrentX(maze->getCurrentX() + 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() - 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else if (currentTile->getWalls().count(Direction::SOUTH) == 0) {
            micromouse->move(Direction::SOUTH);
            maze->setCurrentY(maze->getCurrentY() +1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() - 1);
            maze->updateCurrentTile(*nextTile);
        } else if (currentTile->getWalls().count(Direction::WEST) == 0) {
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() + 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else {
            micromouse->move(Direction::NORTH);
            maze->setCurrentY(maze->getCurrentY() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() + 1);
            maze->updateCurrentTile(*nextTile);
        }
    } else {
        return false;
    }
    maze->isNotOnStartingTile();
    return true;
}
