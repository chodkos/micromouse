#include "leftfirststrategy.h"
#include <iostream>

LeftFirstStrategy::LeftFirstStrategy()
{

}

bool LeftFirstStrategy::traverse()
{
    std::cout<< " maze xxxxzzzzzzzxz: " << maze->getMap().size() << std::endl;


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

    }
    std::cout<< " ret tru: " << std::endl;
    return true;
}

void LeftFirstStrategy::prnt()
{
    std::cout<< " derived prnt class " <<  std::endl;
}

