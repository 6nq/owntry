#include "base.h"
#ifndef BUS_H
#define BUS_H

class Buses
{
private:
    string name;
    int bus_no;
    int start;
    int end;

public:
    Buses(string const& _name,int const& _start,int const& _end);
    ~Buses()=default;
    inline int const& getNo()const;
};

#endif /* BUS_H */
