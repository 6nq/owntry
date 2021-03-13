#include "base.h"
#include "uncopyable.h"
#ifndef STATION_H
#define STATION_H

class Station :public Uncopyable{
public:
    Station(string const& _name);
    ~Station()=default;

    inline void update(string const& _name);
    inline void add_out_station(Station* out_node);
    inline void add_in_station(Station* out_node);
    inline void print()const;

private:
    int no;
    string name;
    list<Station*> out_station;
    list<Station*> in_station;

    inline int const& count_station();
};

#endif /* STATION_H */
