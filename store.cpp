#include "store.h"
#include "moudle/map.cpp"

#ifndef STORE_CPP
#define STORE_CPP

Store&  Store::getStoreInstance(){
    static Store instance;
    return instance;
}

Store::~Store(){
    writeback();
}

void Store::writeback(){
    writeRoute();
    writeBuses();
    writeStation();
}

void Store::writeStation(){
    ofstream ofstrm;
    ofstrm.open(Config::fnstation);
    if(!ofstrm.is_open()){
        cout<< "打开失败" << Config::fnstation << endl;
        return ;
    }

    auto& station_map = Map::getMapInstance().station_map;
    for (int i = 0; i < station_map.size() ; ++i) {
        ofstrm<< station_map[i] <<endl;       
    }
    cout<< "写入成功" << Config::fnstation << endl;
    ofstrm.close();
}

void Store::writeBuses(){
    ofstream ofstrm;
    ofstrm.open(Config::fnbuses);
    if(!ofstrm.is_open()){
        cout<< "打开失败" << Config::fnbuses << endl;
        return ;
    }

    cout<< "写入成功" << Config::fnbuses << endl;
    ofstrm.close();
}

void Store::writeRoute(){
    ofstream ofstrm;
    ofstrm.open(Config::fnroute);
    if(!ofstrm.is_open()){
        cout<< "打开失败" << Config::fnroute << endl;
        return ;
    }

    cout<< "写入成功" << Config::fnroute << endl;
    ofstrm.close();
}

#endif

