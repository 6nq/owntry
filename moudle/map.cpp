#include "station.cpp"
#include "buses.cpp"
#include "map.h"

#ifndef MAP_CPP
#define MAP_CPP

Map& Map::getMapInstance(){
    static Map instance;
    return instance;
}

inline void Map::addStation(Station const& node){
    station_map.emplace(node.no,node);
}

inline void Map::addBus(Buses const& node){
    bus_map.emplace(node.no,node);
}

#endif
