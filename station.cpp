#include "station.h"

Station::Station(string const& _name):no(count_station()),name(_name),out_station(0){ }

inline void Station::
update(string const& _name){
    name = std::move(_name);
}

void Station::
print()const{
    cout<< no << " : " << name << endl;
}

inline void Station::
add_out_station(Route *const route){
    out_station.emplace_back(route);
}

inline void Station::
add_in_station(Route *const route){
    in_station.emplace_back(route);
}

inline int const& Station::
count_station(){
    static int num = 0;
    return ++num;
}

inline int const& Station::
getNo()const{
    return no;
}

inline string const& Station::
getName()const{
    return name;
}

inline list<Route*>& Station::
get_outStation(){
    return out_station;
}

inline list<Route*>& Station::
get_inStation(){
    return out_station;
}
