#include "buses.h"

Buses::Buses(string const& _name,int _bus_no,int const& _start,int const& _end):name(_name),bus_no(_bus_no),start(_start),end(_end){}

inline int Buses::getBusesNo()const{
    return bus_no;
}

/* int main(void) */
/* { */
/*     return 0; */
/* } */
