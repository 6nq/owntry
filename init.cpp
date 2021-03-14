#include "init.h"
#include "moudle/route.cpp"
#include "moudle/map.cpp"

Init& Init::getInitInstance(){
    static Init instance;
    return instance;
}

Init::Init(){
    InitStation();
    InitBuses();
    InitRoute();
}

void Init::InitStation(){
    ifstream ifstrm;
    ifstrm.open(fnstation);
    if(!ifstrm.is_open()){
        return ;
    }

    Station sta;
    auto& instance = Map::getMapInstance();
    while (ifstrm >> sta) {
        instance.addStation(sta);
    }
    cout<< "读取结束" << endl;
}

void Init::InitBuses(){
    ifstream ifstrm;
    ifstrm.open(fnbuses);
    if(!ifstrm.is_open()){
        return ;
    }

    Buses bus;
    auto& instance = Map::getMapInstance();
    while (ifstrm >> bus) {
        instance.addBus(bus);
    }
}


void Init::InitRoute(){
    ifstream ifstrm;
    ifstrm.open(fnroute);
    if(!ifstrm.is_open()){
        return ;
    }

    auto& instance = Map::getMapInstance();
    auto buses_map = instance.bus_map;
    auto station_map = instance.station_map;
    
    int start,end,distance_,bus_no;
    while (ifstrm >> bus_no >> start >> end >> distance_) {
        Station*const font = &station_map[start];
        Station*const tail = &station_map[end];

        Route out_route(bus_no,distance_,tail);
        Route in_route(bus_no,distance_,font);

        font->add_out_station(out_route);
        tail->add_in_station(in_route);
    }
}

int main(void)
{
    Init& Init_Instance = Init::getInitInstance();
    return 0;
}
