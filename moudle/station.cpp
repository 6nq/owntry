#include "station.h"
#include "route.h"

Station::Station(int const& _no,string const& _name):no(_no),name(_name){ }

inline void Station::
update(string const& _name){
    name = std::move(_name);
}

inline void Station::
add_out_station(Route const& route){
    out_station.emplace_back(route);
}

inline void Station::
add_in_station(Route const& route){
    in_station.emplace_back(route);
}


inline int Station::
getStationNo()const{
    return no;
}

inline string const& Station::
getName()const{
    return name;
}

inline list<Route>& Station::
get_outStation(){
    return out_station;
}

inline list<Route>& Station::
get_inStation(){
    return out_station;
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

/* int main(void) */
/* { */
/*     Station sta; */
/*     cin>> sta; */
/*     cout<< sta; */
/*     cin>> sta; */
/*     cout<< sta; */
/*     return 0; */
/* } */
