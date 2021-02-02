#include <iostream>
#include "station.cpp"
#include <cstring>

#ifndef IO_H
#define IO_H

class buffer
{
static const int MAX_BUF = 4096;
private:
    char buf[MAX_BUF];
    size_t avail_len = MAX_BUF;
public:
    buffer(){ };
    buffer(const buffer&)=delete;
    buffer& operator=(const buffer&)=delete;
    virtual ~buffer()=default;

    inline void* GetAdderss()const{
         return (void*)buf;
    }
    inline size_t& GetLen(){
         return avail_len;
    } 
};

#endif /* IO_H */
int main(void)
{
    buffer new_buf;
    const char str[24] = "12341234hello world!C++";
    for (int i = 0; i < 24; ++i) {
        *((char*)new_buf.GetAdderss()+i) = *(str+i);
    }

    Station* nsta = new(new_buf.GetAdderss())Station;
    //nsta->show();
    cout<<endl;

    return 0;
}
