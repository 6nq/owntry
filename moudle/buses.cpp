#include "buses.h"

#ifndef BUSES_CPP
#define BUSES_CPP

Buses::Buses(int _bus_no,string const& _name,int const& _start,int const& _end)
                :no(_bus_no),name(_name),start(_start),end(_end),begin(nullptr){}

Buses::Buses(int _bus_no,string const& _name,int const& _start,int const& _end,Route*const _begin)
                :no(_bus_no),name(_name),start(_start),end(_end),begin(_begin){}

istream& operator>>(istream& is,Buses & bus){
    is>> bus.no 
      >> bus.name
      >> bus.start
      >> bus.end;
    return is;
}

ostream& operator<<(ostream& os,Buses const& bus){
    os<< bus.no << " "
      << bus.name << " "
      << bus.start << " "
      << bus.end << endl;
    return os;
}

#endif
