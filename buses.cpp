#include "buses.h"

Buses::Buses(string const& _name,int const& _start,int const& _end):name(_name),start(_start),end(_end){}

inline int const& Buses::getNo()const{
    return bus_no;
}
