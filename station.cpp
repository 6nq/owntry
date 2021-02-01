#include <iostream>
#include <cstring>
using namespace std;

#ifndef STATION_H
#define STATION_H

class Station
{
private:
    int index;
    size_t size;
    char name[];
public:
    Station(const int& Index,const char* name_):index(Index){
         size = strlen(name_)+1;
         strcpy(name,name_);
    }
    inline const size_t& GetSize()const{ return size; }
    inline const int& GetIndex()const{ return index; }
    inline  char const* GetName()const{
         return name;
    }
    virtual ~Station()=default;
};

#endif /* STATION_H */

int main(void)
{
    char str[30];
    cin>>str;
    int size = strlen(str)+1;
    void* ptr = malloc(sizeof(class Station)+size*sizeof(char));
    Station* nsta = new(ptr)Station(1,str);
    cout<< endl;
    cout<< nsta->GetIndex() <<endl;
    cout<< nsta->GetName() <<endl;
    cout<< nsta->GetSize() <<endl;
    return 0;
}
