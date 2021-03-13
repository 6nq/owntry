#include "base.h"
#ifndef ROUTE_H
#define ROUTE_H

class Route
{
private:
    int no_station;
    int distance_;

public:
    Route(int const& noStation,int const& noBus,int const& Distance);
    ~Route();
};

#endif /* ROUTE_H */
