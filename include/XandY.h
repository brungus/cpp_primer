#ifndef XANDY_H
#define XANDY_H

// ex. 7.31 pg 363
class Y;

class X
{
    Y *yPtr;
};

class Y
{
    X xObj;
};

#endif
