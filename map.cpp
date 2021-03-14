#include "map.h"

inline void Map::addStation(Station const& node){
    station_map.emplace(node.getNo(),node);
}

inline void Map::addBus(Buses const& node){
    bus_map.emplace(node.getNo(),node);
}
inline Station& Map::getStation(int const& station_no){
    return station_map[station_no];
}

inline Buses& Map::getBuses(int const& bus_no){
    return bus_map[bus_no];
}
