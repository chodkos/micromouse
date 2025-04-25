#include "turnleftstrategy.h"
#include <iostream>
TurnLeftStrategy::TurnLeftStrategy() {}

bool TurnLeftStrategy::traverse()
{


    Tile * currentTile = maze->getCurrentTile();
    std::cout << "maze curren x :   "<<maze->getCurrentX()  << std::endl;
    std::cout << "maze curren y :   "<< maze->getCurrentY()  << std::endl;
    std::cout << "previous X :   "<< maze->getCurrentTile()->getPreviousX()  << std::endl;
    std::cout << "previous Y :   "<< maze->getCurrentTile()->getPreviousY()  << std::endl;
    if(maze->getCurrentX() == 4 && maze->getCurrentY() == 2) {
        return false;
    }

    if(maze->getIsOnStartingTile() || currentTile->getPreviousX() == maze->getCurrentX() -1) {
        std::cout << "inside X - 1"  << std::endl;
        if(currentTile->getWalls().count(Direction::NORTH) == 0) {
            std::cout << "NORTH"  << std::endl;
            micromouse->move(Direction::NORTH);
            maze->setCurrentY(maze->getCurrentY() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX());
            nextTile->setPreviousY(maze->getCurrentY() + 1);
            maze->updateCurrentTile(*nextTile);
        } else if(currentTile->getWalls().count(Direction::EAST) == 0) {
            std::cout << "EAST: "  << (currentTile->getWalls().count(Direction::EAST) == 0) << std::endl;
            std::cout << "NORTH: "  << (currentTile->getWalls().count(Direction::NORTH) == 0) << std::endl;
            std::cout << "SOUTH: "  << (currentTile->getWalls().count(Direction::SOUTH) == 0) << std::endl;
            std::cout << "WEST: "  << (currentTile->getWalls().count(Direction::WEST) == 0) << std::endl;
            micromouse->move(Direction::EAST);
            maze->setCurrentX(maze->getCurrentX() + 1);


            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() - 1);
            nextTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*nextTile);
        } else if (currentTile->getWalls().count(Direction::SOUTH) == 0) {
            std::cout << "SOUTH"  << std::endl;
            micromouse->move(Direction::SOUTH);
            maze->setCurrentY(maze->getCurrentY() +1);

            currentTile->setPreviousX(maze->getCurrentX());
            currentTile->setPreviousY(maze->getCurrentY() - 1);
            maze->updateCurrentTile(*currentTile);
        } else {
            std::cout << "WEST"  << std::endl;
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            currentTile->setPreviousX(maze->getCurrentX() + 1);
            currentTile->setPreviousY(maze->getCurrentY());
            maze->updateCurrentTile(*currentTile);
        }

    } else if(currentTile->getPreviousX() == maze->getCurrentX() + 1) {
        std::cout << "inside X + 1"  << std::endl;
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
        std::cout << "inside Y + 1"  << std::endl;
        if(currentTile->getWalls().count(Direction::WEST) == 0) {
            std::cout << "WEST"  << std::endl;
            micromouse->move(Direction::WEST);
            maze->setCurrentX(maze->getCurrentX() - 1);

            Tile * nextTile = maze->getCurrentTile();
            nextTile->setPreviousX(maze->getCurrentX() + 1);
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
        std::cout << "inside Y - 1"  << std::endl;
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
         std::cout << "returned fals"  << std::endl;
        return false;
    }
    /*
    if(maze->getCurrentTile()->getWalls().count(Direction::EAST) == 0 && maze->getCurrentX() + 1 != maze->getCurrentTile()->getPreviousX()) {
        micromouse->move(Direction::EAST);
        maze->setCurrentX(maze->getCurrentX() + 1);

        maze->getCurrentTile()->setPreviousX(maze->getCurrentX() - 1);
        maze->getCurrentTile()->setPreviousY(maze->getCurrentY());
    } else if(maze->getCurrentTile()->getWalls().count(Direction::NORTH) == 0 && maze->getCurrentY() -1 != maze->getCurrentTile()->getPreviousY()){
        micromouse->move(Direction::NORTH);
        maze->setCurrentY(maze->getCurrentY() -1);

        maze->getCurrentTile()->setPreviousX(maze->getCurrentX());
        maze->getCurrentTile()->setPreviousY(maze->getCurrentY() + 1);
    } else if(maze->getCurrentTile()->getWalls().count(Direction::WEST) == 0 && maze-> getCurrentX() - 1 != maze->getCurrentTile()->getPreviousX()){
        micromouse->move(Direction::WEST);
        maze->setCurrentX(maze->getCurrentX() - 1);

        maze->getCurrentTile()->setPreviousX(maze->getCurrentX() + 1);
        maze->getCurrentTile()->setPreviousY(maze->getCurrentY());
    } else if(maze->getCurrentTile()->getWalls().count(Direction::SOUTH) == 0 && maze->getCurrentY() + 1 != maze->getCurrentTile()->getPreviousY()){
        micromouse->move(Direction::SOUTH);
        maze->setCurrentY(maze->getCurrentY() +1);

        maze->getCurrentTile()->setPreviousX(maze->getCurrentX());
        maze->getCurrentTile()->setPreviousY(maze->getCurrentY() - 1);
    } else {
        std::cout<< " ret fals: " << std::endl;
        return false;

    }*/
    maze->isNotOnStartingTile();
    std::cout << "returned tru"  << std::endl;
    return true;
}
