#ifndef MAZETRAVERSER_H
#define MAZETRAVERSER_H

#include "maze.h"
#include "micromouse.h"

#include <QObject>

#include <traversingStrategies/turnleftstrategy.h>
#include <traversingStrategies/turnright.h>


class MazeTraverser: public QObject
{
    Q_OBJECT
private:
    Maze *maze;
    Micromouse *micromouse;
    int movesCount = 0;

    QMetaObject::Connection connection;
    TraversingStrategy * traversingStrategy;

public:
    explicit MazeTraverser(QObject *parent = nullptr);
    void setMaze(Maze* _maze);
    Maze * getMaze();
    void stopTraversing();
    void setMicromouse(Micromouse* _micromouse);
    Micromouse * getMicromouse();

    //zaczyna ruch robota do czasu osiagniecia punktu koncowego lub wywolania stopTraversing()
    void startTraversing();

    //zwieksza licznik ruchow
    void incrementMovesCount();
    int getMovesCount();

    void setTraversingStrategy(TraversingStrategy * _traversingStrategy);
    TraversingStrategy * getTraversingStrategy();

public slots:
    void moveMicromouse();
};

#endif // MAZETRAVERSER_H
