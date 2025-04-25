#ifndef TURNRIGHT_H
#define TURNRIGHT_H

#include <traversingstrategy.h>

class TurnRight : public TraversingStrategy
{
public:
    TurnRight();
    bool traverse();
};

#endif // TURNRIGHT_H
