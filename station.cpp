#include "station.h"

Station::Station(string const& _name):no(count_station()),name(_name){ }

inline void Station::update(string const& _name){
    name = std::move(_name);
}

void Station::print()const{
    cout<< no << " : " << name << endl;
}

inline void Station::add_out_station(Station* out_node){
    out_station.push_back(out_node);
}

inline void Station::add_in_station(Station* in_node){
    in_station.push_back(in_node);
}
inline int const& count_station(){
    static int num = 0;
    return ++num;
}
