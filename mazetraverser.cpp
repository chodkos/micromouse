#include "mazetraverser.h"

#include <qtimer.h>

#include <traversingStrategies/leftfirststrategy.h>

MazeTraverser::MazeTraverser(QObject *parent): QObject{parent}
{

}

void MazeTraverser::setMaze(Maze* _maze)
{
    maze = _maze;
}

Maze MazeTraverser::getMaze()
{
    return *maze;
}

void MazeTraverser::stopTraversing()
{
    disconnect(connection);
}

void MazeTraverser::setMicromouse(Micromouse* _micromouse)
{
    micromouse = _micromouse;
}

void MazeTraverser::startTraversing()
{
    QTimer * timer = new QTimer();
    connection = connect(timer, SIGNAL(timeout()), this, SLOT(moveMicromouse()));
    timer->start(1000);
}

void MazeTraverser::incrementMovesCount()
{
    movesCount+=1;
}

int MazeTraverser::getMovesCount()
{
    return movesCount;
}

void MazeTraverser::setTurnLeftStrategy(TurnLeftStrategy *_turnLeftStrat)
{
    turnLeftStrat = _turnLeftStrat;
}

TurnLeftStrategy *MazeTraverser::prepareTurnLeftStrategy()
{
    turnLeftStrat->setMaze(maze);
    turnLeftStrat->setMicromouse(*micromouse);
    return turnLeftStrat;
}

void MazeTraverser::setTurnRightStrategy(TurnRight *_turnRightStrat)
{
    turnRightStrat = _turnRightStrat;
}

TurnRight *MazeTraverser::prepareTurnRightStrategy()
{
    turnRightStrat->setMaze(maze);
    turnRightStrat->setMicromouse(*micromouse);
    return turnRightStrat;
}

void MazeTraverser::setStrategy(int _st)
{
    strategy = _st;
}

int MazeTraverser::getStrategy()
{
    return strategy;
}



void MazeTraverser::moveMicromouse()
{
    if(getStrategy() == 1) {
        TurnLeftStrategy turnLeft;
        turnLeftStrat = &turnLeft;
        turnLeftStrat->setMaze(maze);
        turnLeftStrat->setMicromouse(*micromouse);

        if(!turnLeftStrat->traverse()) {
            stopTraversing();
            return;
        }
    } else if(getStrategy() == 2) {
        TurnRight turnRight;
        turnRightStrat = &turnRight;
        turnRightStrat->setMaze(maze);
        turnRightStrat->setMicromouse(*micromouse);

        if(!turnRightStrat->traverse()) {
            stopTraversing();
            return;
        }
    }
    incrementMovesCount();
}
