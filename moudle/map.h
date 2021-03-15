#include "base.h"

#ifndef MAP_H
#define MAP_H

class Map
{
public:
    static Map& getMapInstance();
    inline void addStation(Station const& );
    inline void addBus(Buses const&);
    ~Map()=default;

    unordered_map<int,Station> station_map;      
    unordered_map<int,Buses> bus_map;

private:
    Map()=default;
    Map(Map const&)=delete;
    Map& operator=(Map const&)=delete;
};

#endif /* MAP_H */
