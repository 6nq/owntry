#include <iostream>
#include <cstring>
using namespace std;

#ifndef STATION_H
#define STATION_H

class Station
{
private:
     int index;
     int len;
     char name[0];
    
public:
    Station(){}
    Station(const int& ,const char*);
    Station(const Station&)=delete;
    Station& operator=(const Station&)=delete;
    inline const int& GetSize()const{ return len; }
    inline const int& GetIndex()const{ return index; }
    inline char const* GetName()const{ return name; }
    virtual ~Station()=default;

    void show()const{
         cout<< index << endl;
         cout<< len << endl;
         for (int i = 0; i < len; ++i) {
             cout<< name[i];
         }
    }
};

Station::Station(const int& Index,const char* name_){
    index = Index;
    len = strlen(name_)+1;
    strcpy(name,name_);
    /* cout<< this<<endl; */
    /* cout<< &index<<endl; */
    /* cout<< &len<<endl; */
    /* cout<< &name<<endl; */
}

#endif /* STATION_H */
//test

int main(void)
{
    /* const char str[] = "hello world!"; */
    /* size_t l = sizeof(Station)+strlen(str)+1; */
    /* void* ptr = malloc(l); */
    /* for (size_t i = 0; i <strlen(str)+1 ; ++i) { */
    /*     *((char*)ptr+15+i) = *(str+i); */
    /* } */
    /* cout<<endl; */
    /* Station* nsta = new(ptr)Station; */
    /* nsta->show(); */
    return 0;
}
