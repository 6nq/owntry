#include "fileio/fileio.cpp"
#include "mainpage.h"

#ifndef PAGE_CPP
#define PAGE_CPP

void clearBuf(){
    char ch;
    while((ch = getchar()) != EOF && ch != '\n')
        ;
}
char const getKeystroke(){
    char ch;
    while(cin>>ch){
        clearBuf();
        if(ch < '0' || ch > '9'){
            cout<< "输入有误,请重新输入" <<endl;
            continue;
        }
        return ch;
    }
    return '0';
}

void MainPage(){
    cout<< "公交管理系统" <<endl;
    cout<< "按下数字键选择选项:" <<endl;
    cout<<"公交管理系统"<<endl;
    cout<< "0: 退出" <<endl;
    cout<< "1: 查找公交线路" <<endl;
    cout<< "2: 查询两站点之间路线(至多换乘一次)" <<endl;

    switch(getKeystroke()){
        case '0':
            system("clear");
            return;
        case '1':
            system("clear");
            return Page1();
        case '2':
            system("clear");
            return Page2();
        default:
            system("clear");
            cout<< "请重新选择选项[ 0 - 2 ]" <<endl;
            return MainPage();
    }
}

void Page1(){
    cout<< "0: 退出" <<endl;
    cout<< "1: 通过公交线路编号查找" <<endl;
    cout<< "2: 通过站点编号查找所有经过的路线并输出" <<endl;

    switch(getKeystroke()){
        case '0':
            system("clear");
            return MainPage();
        case '1':
            search_By_busno();
            return Page1();
        case '2':
            system("clear");
            search_By_stationno();
            return Page1();
        default:
            system("clear");
            cout<< "请重新选择选项[ 0 - 2 ]" <<endl;
            return Page1();
    }
}

void search_By_busno(){
    cout<< "请输入线路编号" <<endl;

    int no_bus;
    auto& map_instance = Map::getMapInstance();
    auto& bus_map = map_instance.bus_map;
    auto& station_map = map_instance.station_map;
    cin>>no_bus;

    /* auto& bus = bus_map[no_bus]; */
    auto iter_bus = bus_map.find(no_bus);
    if(iter_bus == bus_map.end()){
        cout<< "不存在该公交线路编号" << endl;
        cout<< (*iter_bus).second <<endl;
        return;
    }
    auto& bus = (*iter_bus).second;
    auto& start_station = station_map[bus.start];
    auto& end_station = station_map[bus.end];

    cout<< bus.name
        << " 线路编号: " << no_bus << endl;

    cout<< "路线为:" << start_station;

    Station* ptr_sta = &start_station;
    do{
        for (auto i = ptr_sta->out_station.begin(); i != ptr_sta->out_station.cend(); ++i) {
            if((*i)->bus_no == no_bus){
                ptr_sta = (*i)->next_station;
                cout<< " -> " << *ptr_sta ;
                break;
            }
        }
    }while(ptr_sta->no != bus.end);
    cout<<endl;
}

void search_By_stationno(){
    cout<< "请输入站点编号" <<endl;
    int no_station;
    cin>> no_station;

    auto& map_instance = Map::getMapInstance();
    auto& bus_map = map_instance.bus_map;
    auto& station_map = map_instance.station_map;

    auto iter_station = station_map.find(no_station);
    if(iter_station == station_map.cend()){
        cout<< "不存在该站点编号" << endl;
        return;
    }

}

void Page2(){

}

#endif
