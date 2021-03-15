#include "init.h"
#include "moudle/route.cpp"
#include "moudle/map.cpp"

#ifndef INIT_CPP
#define INIT_CPP

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
    ifstrm.open(Config::fnstation);
    if(!ifstrm.is_open()){
    cout<< "打开失败" << Config::fnstation << endl;
        return ;
    }

    Station sta;
    auto& instance = Map::getMapInstance();
    while (ifstrm >> sta) {
        instance.addStation(sta);
    }
    ifstrm.close();
    cout<< "读取成功" << Config::fnstation << endl;
}

void Init::InitBuses(){
    ifstream ifstrm;
    ifstrm.open(Config::fnbuses);
    if(!ifstrm.is_open()){
    cout<< "打开失败" << Config::fnbuses << endl;
        return ;
    }

    Buses bus;
    auto& instance = Map::getMapInstance();
    while (ifstrm >> bus) {
        instance.addBus(bus);
    }
    ifstrm.close();
    cout<< "读取成功" << Config::fnbuses << endl;
}


void Init::InitRoute(){
    ifstream ifstrm;
    ifstrm.open(Config::fnroute);
    if(!ifstrm.is_open()){
        cout<< "打开失败" << Config::fnroute << endl;
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
    ifstrm.close();
    cout<< "读取成功" << Config::fnroute << endl;
}

#endif
