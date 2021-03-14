#include "base.h"

#ifndef MAP_H
#define MAP_H

class Map
{
public:
    static Map& getMapInstance();
    inline void addStation(Station const& );
    inline void addBus(Buses const&);
    inline Station& getStation(int const& station_no);
    inline Buses& getBuses(int const& bus_no);
    ~Map()=default;
private:
    Map()=default;
    Map(Map const&)=delete;
    Map& operator=(Map const&)=delete;

    unordered_map<int,Station> station_map;      
    unordered_map<int,Buses> bus_map;
};

#endif /* MAP_H */
