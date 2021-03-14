#include "moudle/base.h"


#ifndef INIT_H
#define INIT_H

class Init
{
public:
    static Init& getInitInstance();
    ~Init()=default;

private:
    Init();
    Init(Init const&)=delete;
    Init& operator=(Init const&)=delete;
    void InitStation();
    void InitBuses();
    void InitRoute();

    constexpr static char fnstation[] = "data/station.txt";
    constexpr static char fnbuses[] = "data/buses.txt";
    constexpr static char fnroute[] = "data/route.txt";
};

#endif /* INIT_H */
