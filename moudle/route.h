#include "base.h"

#ifndef ROUTE_H
#define ROUTE_H

class Route
{
public:
    int bus_no;//线路所属公交线路编号
    int distance_;//两站点之间的距离
    Station* next_station;//指向目标公交站点的指针
    Route* next_route;//指向所属公交线路下一条线路的指针

    Route()=default;
    Route(int const& bus_no,int const& distance_,Station*const next_station);
    Route(int const& bus_no,int const& distance_,Station*const next_station,Route*const next_route);
    ~Route()=default;
};

#endif /* ROUTE_H */
