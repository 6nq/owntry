#include "base.h"
#include "uncopyable.h"
#ifndef STATION_H
#define STATION_H

class Station :public Uncopyable{
public:
    Station(string const& _name);
    ~Station()=default;

    inline void update(string const& _name);
    inline void add_out_station(int const& distance,int const& index_out_station);
    inline void add_in_station(int const&distance,int const& index_in_station);
    inline void print()const;

private:
    int no;
    string name;
    list<pair<int,Station*>> out_station;
    list<pair<int,Station*>> in_station;

    inline int const& count_station();
};

#endif /* STATION_H */
