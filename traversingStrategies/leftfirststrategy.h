#ifndef LEFTFIRSTSTRATEGY_H
#define LEFTFIRSTSTRATEGY_H

#include <traversingstrategy.h>


class LeftFirstStrategy: public TraversingStrategy
{
public:
    LeftFirstStrategy();

    // TraversingStrategy interface
    bool traverse();
    void prnt();
};

#endif // LEFTFIRSTSTRATEGY_H
