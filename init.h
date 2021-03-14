#include "base.h"


#ifndef INIT_H
#define INIT_H

class Init
{
public:

    Init();
    ~Init()=default;

private:
    void InitStation();
    void InitBuses();
    void InitRoute();

    constexpr static char fnstation[] = "station.txt";
    constexpr static char fnbuses[] = "buses.txt";
    constexpr static char fnroute[] = "route.txt";
};

#endif /* INIT_H */
