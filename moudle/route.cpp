#include "route.h"

#ifndef ROUTE_CPP
#define ROUTE_CPP

Route::Route(int const& no_bus,int const& distance_l,Station*const nextStation)
    :bus_no(no_bus),distance_(distance_l),next_station(nextStation){
    }

ostream& operator<<(ostream& os,Route const& route){
    os  << route.bus_no << " "
        << route.distance_ << " "
        << route.next_station<< endl;
    return os;
}

#endif
