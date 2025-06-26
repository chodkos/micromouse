#include "mazetraverser.h"

#include <qtimer.h>

MazeTraverser::MazeTraverser(QObject *parent): QObject{parent}
{

}

void MazeTraverser::setMaze(Maze* _maze)
{
    maze = _maze;
}

Maze * MazeTraverser::getMaze()
{
    return maze;
}

void MazeTraverser::stopTraversing()
{
    disconnect(connection);
}

void MazeTraverser::setMicromouse(Micromouse* _micromouse)
{
    micromouse = _micromouse;
}

Micromouse *MazeTraverser::getMicromouse()
{
    return micromouse;
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

void MazeTraverser::setTraversingStrategy(TraversingStrategy *_traversingStrategy)
{
    traversingStrategy = _traversingStrategy;
}

TraversingStrategy *MazeTraverser::getTraversingStrategy()
{
    return traversingStrategy;
}


void MazeTraverser::moveMicromouse()
{
    if(!getTraversingStrategy()->traverse()) {
        stopTraversing();
        return;
    }
    incrementMovesCount();
}
