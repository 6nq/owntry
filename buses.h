#include "base.h"
#ifndef BUSES_H
#define BUSES_H

class Buses
{
private:
    string name;
    int bus_no;
    int start;
    int end;

public:
    Buses()=default;
    Buses(string const& _name,int _bus_no,int const& _start,int const& _end);
    ~Buses()=default;
    inline int  getBusesNo()const;
};

#endif /* BUSES_H */
