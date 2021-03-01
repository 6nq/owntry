#include <iostream>
using namespace std;


#ifndef STATION_H
#define STATION_H

class Station
{
private:
    int no;
    size_t len;

public:
    Station(){};
    void print(){
        cout<< len <<endl;
        cout<< sizeof(len) <<endl;

    }
    ~Station(){};
};

#endif /* STATION_H */
