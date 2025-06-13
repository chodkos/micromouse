#include "turnright.h"
#include <iostream>

TurnRight::TurnRight() {}

bool TurnRight::traverse()
{
    Tile * currentTile = maze->getCurrentTile();
    std::cout << "maze curren x :   "<<maze->getCurrentX()  << std::endl;
    std::cout << "maze curren y :   "<< maze->getCurrentY()  << std::endl;
    std::cout << "previous X :   "<< maze->getCurrentTile()->getPreviousX()  << std::endl;
    std::cout << "previous Y :   "<< maze->getCurrentTile()->getPreviousY()  << std::endl;
    if(maze->getCurrentX() == maze->getCenterColumn() && maze->getCurrentY() == maze->getCenterRow()) {
        return false;
    }

    if(maze->getIsOnStartingTile() || currentTile->getPreviousX() == maze->getCurrentX() -1) {
        std::cout << "inside X - 1"  << std::endl;
        if (currentTile->getWalls().count(Direction::SOUTH) == 0) {
            std::cout << "SOUTH"  << std::endl;
            micromouse->move(Direction::SOUTH);
            maze->setCurrentY(maze->getCurrentY() +1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() - 1);
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::EAST) == 0) {
            micromouse->move(Direction::EAST);
            maze->setCurrentX(maze->getCurrentX() + 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() - 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::NORTH) == 0) {
            std::cout << "NORTH"  << std::endl;
            micromouse->move(Direction::NORTH);
            maze->setCurrentY(maze->getCurrentY() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() + 1);
            maze->updateCurrentTile(*nextTile);
        } else {
            std::cout << "WEST"  << std::endl;
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() + 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        }

    } else if(currentTile->getPreviousX() == maze->getCurrentX() + 1) {
        std::cout << "inside X + 1"  << std::endl;

        if(currentTile->getWalls().count(Direction::NORTH) == 0) {
            micromouse->move(Direction::NORTH);
            maze->setCurrentY(maze->getCurrentY() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() + 1);
            maze->updateCurrentTile(*nextTile);
        } else if (currentTile->getWalls().count(Direction::WEST) == 0) {
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() + 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else if (currentTile->getWalls().count(Direction::SOUTH) == 0) {
            micromouse->move(Direction::SOUTH);
            maze->setCurrentY(maze->getCurrentY() +1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() - 1);
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
        std::cout << "inside Y + 1"  << std::endl;

        if(currentTile->getWalls().count(Direction::EAST) == 0) {
            micromouse->move(Direction::EAST);
            maze->setCurrentX(maze->getCurrentX() + 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() - 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::NORTH) == 0) {
            std::cout << "NORTH"  << std::endl;
            micromouse->move(Direction::NORTH);
            maze->setCurrentY(maze->getCurrentY() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() + 1);
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::WEST) == 0) {
            std::cout << "WEST"  << std::endl;
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() + 1);
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
        std::cout << "inside Y - 1"  << std::endl;
        if (currentTile->getWalls().count(Direction::WEST) == 0) {
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() + 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else if (currentTile->getWalls().count(Direction::SOUTH) == 0) {
            micromouse->move(Direction::SOUTH);
            maze->setCurrentY(maze->getCurrentY() +1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() - 1);
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::EAST) == 0) {
            micromouse->move(Direction::EAST);
            maze->setCurrentX(maze->getCurrentX() + 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() - 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        }  else {
            micromouse->move(Direction::NORTH);
            maze->setCurrentY(maze->getCurrentY() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() + 1);
            maze->updateCurrentTile(*nextTile);
        }
    } else {
        std::cout << "returned fals"  << std::endl;
        return false;
    }
    maze->isNotOnStartingTile();
    std::cout << "returned tru"  << std::endl;
    return true;
}
