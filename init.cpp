#include "init.h"
#include "map.cpp"

Init::Init(){
    InitStation();
}

void Init::InitStation(){
    int fd = open(fnstation,O_RDONLY|O_CREAT,555);
    if(fd < 0){
        cout<< "open " << fnstation << " error." << endl;
        exit(0);
    }
    cout<< "open " << fnstation << " success." <<endl;

    auto& instance = Map::getMapInstance();
}

void Init::InitBuses(){

}

void Init::InitRoute(){

}

int main(void)
{
    Init x;
    return 0;
}
