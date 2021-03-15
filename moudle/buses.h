#include "base.h"
#ifndef BUSES_H
#define BUSES_H

class Buses
{
public:
    Buses()=default;
    Buses(int _bus_no,string const& _name,int const& _start,int const& _end);
    ~Buses()=default;

    int no;
    string name;
    int start;
    int end;
};

#endif /* BUSES_H */
