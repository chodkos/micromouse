#ifndef TURNLEFTSTRATEGY_H
#define TURNLEFTSTRATEGY_H

#include <traversingstrategy.h>

class TurnLeftStrategy : public TraversingStrategy
{
    Q_OBJECT
public:
    TurnLeftStrategy();
    bool traverse();
};

#endif // TURNLEFTSTRATEGY_H
