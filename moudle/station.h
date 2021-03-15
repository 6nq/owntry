#include "base.h"

#ifndef STATION_H
#define STATION_H

class Station 
{
public:
    Station()=default;
    Station(int const& _no,string const& _name);
    ~Station();

    inline void update(string const& _name);
    inline void add_out_station(Route *route);
    inline void add_in_station(Route *route);

    int no;
    string name;
    vector<Route*> out_station;
    vector<Route*> in_station;
};

#endif /* STATION_H */
