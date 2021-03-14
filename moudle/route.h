#include "base.h"

#ifndef ROUTE_H
#define ROUTE_H

class Route
{
public:
    int bus_no;
    int distance_;
    Station* next_station;

    Route()=default;
    Route(int const& bus_no,int const& distance_,Station*const next_distance);
    ~Route()=default;
};

#endif /* ROUTE_H */
