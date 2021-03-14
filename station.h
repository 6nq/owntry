#include "base.h"
#ifndef STATION_H
#define STATION_H

class Station {
public:
    Station(string const& _name);
    ~Station()=default;

    inline void update(string const& _name);
    inline void add_out_station(Route *const route);
    inline void add_in_station(Route *const route);
    inline int const& getNo()const;
    inline string const& getName()const;
    inline list<Route*>& get_outStation();
    inline list<Route*>& get_inStation();
    inline void print()const;

    int no;
    string name;
    list<Route*> out_station;
    list<Route*> in_station;

private:
    inline int const& count_station();
};

#endif /* STATION_H */
