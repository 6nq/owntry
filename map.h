#include "base.h"
#include "station.h"
#include "buses.h"

#ifndef MAP_H
#define MAP_H

class Map
{
public:
    Map();
    inline void addStation(Station const& );
    inline void addBus(Buses const&);
    inline Station& getStation(int const& station_no);
    inline Buses& getBuses(int const& bus_no);
    ~Map();
private:
    unordered_map<int,Station> station_map;      
    unordered_map<int,Buses> bus_map;

};

#endif /* MAP_H */
