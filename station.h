#include "base.h"
#ifndef STATION_H
#define STATION_H

class Station {
private:
    bool changed;
    int no;
    string name;

public:
    Station(int const& _no,string const& _name);
    inline void update(int const& _no);
    inline void update(string const& _name);
    inline void update(int const& _no,string const& _name);
    inline void update(string const& _name,int const& _no);
    inline void print()const;
    ~Station()=default;
};

#endif /* STATION_H */
