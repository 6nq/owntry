#include "moudle/base.h"
#include "config.h"


#ifndef INIT_H
#define INIT_H

class Init
{
public:
    static Init& getInitInstance();
    ~Init()=default;

private:
    Init();
    Init(Init const&)=delete;
    Init& operator=(Init const&)=delete;
    void InitStation();
    void InitBuses();
    void InitRoute();

};

#endif /* INIT_H */
