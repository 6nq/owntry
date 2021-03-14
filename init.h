#include "base.h"

#ifndef INIT_H
#define INIT_H

class Init
{
    constexpr static char fnstation[] = "station.txt";
    constexpr static char fnbuses[] = "buses.txt";
    constexpr static char fnroute[] = "route.txt";
public:
    Init();
    ~Init();
};

#endif /* INIT_H */
