#include "base.h"

#ifndef STATION_H
#define STATION_H

class Station 
{
public:
    Station()=default;
    Station(int const& _no,string const& _name);
    ~Station()=default;

    inline void update(string const& _name);
    inline void add_out_station(Route const& route);
    inline void add_in_station(Route const& route);
    inline int getStationNo()const;
    inline string const& getName()const;
    inline list<Route>& get_outStation();
    inline list<Route>& get_inStation();
    inline void print()const;

    list<Route> out_station;
    list<Route> in_station;

private:
    int no;
    string name;
};

#endif /* STATION_H */
