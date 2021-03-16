#include "base.h"
#ifndef BUSES_H
#define BUSES_H

class Buses
{
public:
    Buses()=default;
    Buses(int _bus_no,string const& _name,int const& _start,int const& _end);
    Buses(int _bus_no,string const& _name,int const& _start,int const& _end,Route*const _begin);
    ~Buses()=default;

    int no;
    string name;
    int start;
    int end;
    Route* begin;
};

#endif /* BUSES_H */
