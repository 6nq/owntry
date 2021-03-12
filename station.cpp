#include "station.h"

Station::Station(int const& _no,string const& _name):changed(false),no(_no),name(_name){}

inline void Station::update(int const& _no){
    no = _no;
}

inline void Station::update(string const& _name){
    name = std::move(_name);
}

inline void Station::update(int const& _no,string const& _name){
    no = _no;
    name = std::move(_name);
}

inline void Station::update(string const& _name,int const& _no){
    no = _no;
    name = std::move(_name);
}

void Station::print()const{
    cout<< no << " : " << name << endl;
}
