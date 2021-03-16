#include "../fileio/fileio.cpp"
#include "mainpage.h"
#include "template.cpp"

#ifndef PAGE_CPP
#define PAGE_CPP
auto& map_instance = Map::getMapInstance();
auto& bus_map = map_instance.bus_map;
auto& station_map = map_instance.station_map;

void clearBuf(){
    char ch;
    while((ch = getchar()) != EOF && ch != '\n')
        ;
}
char const getKeyvalue(){
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
    cout<< "3: 增添数据" <<endl;
    cout<< "4: 修改数据" <<endl;
    cout<< "5: 删除数据" <<endl;
    cout<< "6: 查找站点" <<endl;


    switch(getKeyvalue()){
        case '0':
            system("clear");
            return;
        case '1':
            system("clear");
            return Page1();
        case '2':
            system("clear");
            return Page2();
        case '3':
            system("clear");
            return Page3();
        case '4':
            system("clear");
            return Page4();
        case '5':
            system("clear");
            return Page5();
        case '6':
            system("clear");
            int sta_no;
            sta_no =  searchStation();
            if(sta_no < 0){
                cout<< "不存在该站点编号" <<endl;
            } else{
                cout<< station_map[sta_no];
            }
            return MainPage();
        default:
            system("clear");
            cout<< "请重新选择选项[ 0 - 6 ]" <<endl;
            return MainPage();
    }
}

void Page1(){
    cout<< "0: 退出" <<endl;
    cout<< "1: 通过公交线路编号查找" <<endl;
    cout<< "2: 通过站点编号查找所有经过的路线并输出" <<endl;

    switch(getKeyvalue()){
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
    cin>>no_bus;
    printRouteBybusno(no_bus);
}

void search_By_stationno(){
    int sta_no = searchStation();
    if(sta_no < 0){
        cout<< "不存在该站点编号";
        return ;
    }
    auto& sta = station_map[sta_no];

    set<int> arr_line;
    for (auto i : (sta.out_station)) {
        arr_line.insert((*i).bus_no);
    }
    for (auto i : (sta.in_station)) {
        arr_line.insert((*i).bus_no);
    }

    for (auto& i : arr_line) {
        printRouteBybusno(i);
    }
}

void Page2(){
    int start,end;
    cout<< "起始站:" <<endl;
    while ((start = searchStation()) < 0) {
        cout<< "不存在该站点编号,请重新输入" <<endl;
    }
    cout<< "终点站:" <<endl;
    while ((end = searchStation()) < 0) {
        cout<< "不存在该站点编号,请重新输入" <<endl;
    }

    
}

void printRouteBybusno(int const& no_bus){

    auto iter_bus = bus_map.find(no_bus);
    if(iter_bus == bus_map.cend()){
        cout<< "不存在该公交线路编号" << endl;
        return;
    }
    auto& bus = (*iter_bus).second;

    auto& start_station = station_map[bus.start];
    auto& end_station = station_map[bus.end];

    cout<< bus.name << endl
        << " 线路编号: " << no_bus << endl;

    cout<< "路线为:" << endl
        << "begin----->" << start_station;

    Station* ptr_sta = &start_station;
    
    Route* ptr_route;
    for (auto i = ptr_sta->out_station.begin(); i != ptr_sta->out_station.cend(); ++i) {
        if((*i)->bus_no == no_bus){
            ptr_route = *i;
            break;
        }
    }

    travelRoute(ptr_route,[ptr_route](){
            cout<< "---" << ptr_route->distance_ << "--> " << *(ptr_route->next_station); 
    });

    cout<<endl;
}



void addStation(){

    string sta_name;
    int sta_no;
    cout<< "请输入站点编号" <<endl;
    while(cin>>sta_no){
        clearBuf();
        auto iter_station = station_map.find(sta_no);
        if(iter_station == station_map.end()){
            break;
        }
        cout<< "已存在该站点线路编号,请重新输入" << endl;
    }
    cout<< "请输入站点名字" << endl;
    cin>>sta_name;

    Station sta(sta_no,sta_name);
    map_instance.addStation(sta);
}

int  searchStation(){
    cout<< "请输入站点编号(大于0)" <<endl;
    int no_station;
    while (cin>>no_station) {
        if(no_station > 0){
            break;
        }
        cout<< "输入有误,请重新输入" <<endl;
    }


    auto iter_station = station_map.find(no_station);
    if(iter_station == station_map.cend()){
        return -no_station;
    }
    return no_station;
}

void Page3(){
    cout<< "0: 退出" <<endl;
    cout<< "1: 增加站点" <<endl;
    cout<< "2: 增加公交路线 "<<endl;

    switch(getKeyvalue()){
        case '0':
            return MainPage();
        case '1':
            addStation();
            return Page3();
        case '2':
            addBus();
            return Page3();
        default:
            system("clear");
            cout<< "请重新输入" <<endl;
            return Page3();
    }
}

void addBus(){
    int no_bus;
    cout<< "请输入公交线路编号" <<endl;
    while(cin>>no_bus) {
        clearBuf();
        auto iter_bus = bus_map.find(no_bus);
        if(iter_bus == bus_map.end()){
            break;
        }
        cout<< "已存在该公交线路编号,请重新输入" << endl;
    }
    string bus_name;
    cout<< "请输入线路名字" <<endl;
    cin>>bus_name;
    int num;
    cout<< "请输入经过几站[n>=2]"<<endl;
    while(cin>>num){
        if(num < 2){
            cout<< "输入有误，请重新输入"<<endl;
            continue;
        }
        break;
    }
    vector<int> staion_line;
    for (int i = 0; i < num; ++i) {
        cout<< "请输入第" << i+1 << "个站点编号";

        int exist = searchStation();
        int const& station_no = exist<0?-exist:exist;
        if(exist > 0){
            cout<< "已存在该站点线路编号,是否使用已经存在的站点(y/n)"<<endl;
            char ch;

            clearBuf();
            while((ch = getchar()) != EOF){
                clearBuf();
                if(ch == 'y'){
                    staion_line.push_back(station_no);
                    break;
                }else{
                    cout<<"请重新输入"<<endl;
                }
            }
        }else{
            string station_name;
            cout<<"请输入站点名字"<<endl;
            cin>>station_name;
            map_instance.addStation(Station( station_no,station_name));
            staion_line.push_back(station_no);
        }
    }

    for (auto i = staion_line.begin(); i != staion_line.end()-1; ++i) {
        auto& start_station = station_map[*i];
        auto& end_station = station_map[*(i+1)];
        int dis = 0;
        for (auto j = start_station.out_station.begin(); j != start_station.out_station.end(); ++j) {
            if((*j)->next_station->no == end_station.no){
                dis = (*j)->distance_;
                break;
            }
        }
        if(dis == 0){
            for (auto j = end_station.out_station.begin(); j != end_station.out_station.end(); ++j) {
                if((*j)->next_station->no == start_station.no){
                    dis = (*j)->distance_;
                    break;
                }
            }
        }
        if(dis == 0){
            cout<< "请输入【"<< start_station.no << ":" << start_station.name 
                << "】到【" << end_station.no << ":" << end_station.name <<"】的距离"<<endl;
            cin>>dis;
        }
        Route* out_route = new Route(no_bus,dis,&end_station);
        Route* in_route = new Route(no_bus,dis,&start_station);

        start_station.add_out_station(out_route);
        end_station.add_in_station(in_route);

    }
    Buses bus(no_bus,bus_name,staion_line[0],staion_line[staion_line.size()-1]);
    map_instance.addBus(bus);
}

void Page4(){

}

void Page5(){

}

#endif
