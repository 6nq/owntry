#include "station.h"
#include "route.h"

#ifndef STATION_CPP
#define STATION_CPP

Station::Station(int const& _no,string const& _name):no(_no),name(_name){ }
Station::~Station(){
    for (auto i = out_station.begin(); i != out_station.end(); ++i) {
        delete *i;
    }
    for (auto i = in_station.begin(); i != in_station.end(); ++i) {
        delete *i;
    }
}

inline void Station::
update(string const& _name){
    name = std::move(_name);
}

inline void Station::
add_out_station(Route *route){
    out_station.push_back(route);
}

inline void Station::
add_in_station(Route * route){
    in_station.push_back(route);
}

istream& 
operator>>(istream& is,Station& sta){
    is>> sta.no >> sta.name;
    return is;
}

ostream& 
operator<<(ostream& os,Station const& sta){
    os<< sta.no << " " << sta.name << endl;
    return os;
}

#endif
