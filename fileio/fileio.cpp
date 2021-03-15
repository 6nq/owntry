#include "fileio.h"
#include "../moudle/route.cpp"
#include "../moudle/map.cpp"

#ifndef INIT_CPP
#define INIT_CPP

FileIo& FileIo::getFileIoInstance(){
    static FileIo instance;
    return instance;
}

FileIo::FileIo(){
    FileIoStation();
    FileIoBuses();
    FileIoRoute();
}

FileIo::~FileIo(){
    writeback();
}

void FileIo::writeback(){
    writeRoute();
    writeBuses();
    writeStation();
}

void FileIo::FileIoStation(){
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
    cout<< "加载成功" << Config::fnstation << endl;
}

void FileIo::FileIoBuses(){
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
    cout<< "加载成功" << Config::fnbuses << endl;
}


void FileIo::FileIoRoute(){
    ifstream ifstrm;
    ifstrm.open(Config::fnroute);
    if(!ifstrm.is_open()){
        cout<< "打开失败" << Config::fnroute << endl;
        return ;
    }

    auto& instance = Map::getMapInstance();
    auto& buses_map = instance.bus_map;
    auto& station_map = instance.station_map;
    
    int start,end,distance_,bus_no;
    while (ifstrm >> bus_no >> start >> end >> distance_) {
        Station*const font = &(station_map[start]);
        Station*const tail = &(station_map[end]);


        Route* out_route = new Route(bus_no,distance_,tail);
        Route* in_route = new Route(bus_no,distance_,font);

        font->add_out_station(out_route);
        tail->add_in_station(in_route);
    }
    ifstrm.close();

    for (auto& i : station_map) {
        cout<< "hi1"<<endl;
        vector<Route*>& route_list =  i.second.out_station;
        int start_station_no = i.first;

        cout<< route_list.size()<<endl;

        for(auto& j : route_list){
            cout<< j->bus_no           << " "
                  << start_station_no    << " "
                  << j->next_station->no << " "
                  << j->distance_        <<endl;

        }
    }

    cout<< "加载成功" << Config::fnroute << endl;
}



void FileIo::writeStation(){
    ofstream ofstrm;
    ofstrm.open(Config::fnstation);
    if(!ofstrm.is_open()){
        cout<< "打开失败" << Config::fnstation << endl;
        return ;
    }

    auto& station_map = Map::getMapInstance().station_map;
    for (auto& i : station_map) {
        ofstrm<< i.second <<endl;       
    }
    cout<< "写入成功" << Config::fnstation << endl;

    ofstrm.close();
}

void FileIo::writeBuses(){
    ofstream ofstrm;
    ofstrm.open(Config::fnbuses);
    if(!ofstrm.is_open()){
        cout<< "打开失败" << Config::fnbuses << endl;
        return ;
    }

    auto& buses_map = Map::getMapInstance().bus_map;
    for (auto i : buses_map) {
        ofstrm<< i.second <<endl;
    }
    cout<< "写入成功" << Config::fnbuses << endl;

    ofstrm.close();
}

void FileIo::writeRoute(){
    ofstream ofstrm;
    ofstrm.open(Config::fnroute);
    if(!ofstrm.is_open()){
        cout<< "打开失败" << Config::fnroute << endl;
        return ;
    }

    auto &station_map = Map::getMapInstance().station_map;
    for (auto& i : station_map) {
        cout<< "hi1"<<endl;
        vector<Route*>& route_list =  i.second.out_station;
        int start_station_no = i.first;

        cout<< route_list.size()<<endl;

        for(auto& j : route_list){
            cout<< "fs" <<endl;
            ofstrm<< j->bus_no           << " "
                  << start_station_no    << " "
                  << j->next_station->no << " "
                  << j->distance_        <<endl;

        }
    }

    cout<< "写入成功" << Config::fnroute << endl;
    ofstrm.close();
}

#endif
