#include "moudle/base.h"

#ifndef CONFIG_H
#define CONFIG_H

class Config
{
private:
    constexpr static char fnstation[] = "../data/station.txt";
    constexpr static char fnbuses[] = "../data/buses.txt";
    constexpr static char fnroute[] = "../data/route.txt";

    friend class Init;
    friend class Store;

    Config()=default;
     ~Config()=default;
};

#endif /* CONFIG_H */
