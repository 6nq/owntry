#include <iostream>
using namespace std;


#ifndef STATION_H
#define STATION_H

class Station
{
private:
    size_t len;
    char name[];

public:
    Station(){};
    void print(){
        cout<< len <<endl;
        cout<< sizeof(len) <<endl;
        cout<< name << endl;

    }
    ~Station();
};

#endif /* STATION_H */
