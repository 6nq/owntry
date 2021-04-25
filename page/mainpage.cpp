#include "mainpage.h"
#include "template.cpp"
#include "../fileio/fileio.cpp"

#ifndef PAGE_CPP
#define PAGE_CPP
FileIo& fileio_instance = FileIo::getFileIoInstance();

auto& map_instance = Map::getMapInstance();
auto& bus_map = map_instance.bus_map;
auto& station_map = map_instance.station_map;

void clearBuf(){
    char ch;
    while((ch = getchar()) != EOF && ch != '\n')
        ;
}
int getKeyvalue(int max_num){
    int ch;
    while(cin>>ch){
        clearBuf();
        if(ch < 0 || ch >= max_num){
            cout<< "输入有误,请重新输入" <<endl;
            continue;
        }
        return ch;
    }
    return 0;
}

Fun_next MainPage(){
    cout<<endl;
    cout<< "公交管理系统" <<endl;
    cout<< "按下数字键选择选项:" <<endl;
    cout<< "0: 退出" <<endl;
    cout<< "1: 查找公交线路" <<endl;
    cout<< "2: 查询两站点之间路线(至多换乘一次)" <<endl;
    cout<< "3: 增添数据" <<endl;
    cout<< "4: 删除数据" <<endl;
    cout<< "5: 查找站点" <<endl;
    cout<< "6: 更新数据" <<endl;

    static const std::array<Fun_page,7> func_page = {NullPage,Page1,Page2,Page3,Page4,Page5,Page6};


    Fun_next next_page = func_page[getKeyvalue(func_page.size())]();
    while(next_page != NULL){
        next_page = ((Fun_page)next_page) ();
    }
    return NULL;
}

inline constexpr Fun_next NullPage()noexcept{
    return NULL;
}

Fun_next Page1(){
    cout<< "0: 退出" <<endl;
    cout<< "1: 通过公交线路编号查找" <<endl;
    cout<< "2: 通过站点编号查找所有经过的路线并输出" <<endl;

    static const std::array<Fun_page,3> next_page = {MainPage,Page11,Page12};

    int next_page_no = getKeyvalue(next_page.size());
    return (Fun_next)next_page[next_page_no];
}

Fun_next Page11(){
    search_By_busno();
    return (Fun_next)Page1;
}

void search_By_busno(){
    cout<< "请输入线路编号" <<endl;
    int no_bus;
    cin>>no_bus;
    clearBuf();
    printRouteBybusno(no_bus);
}

Fun_next Page12(){
    search_By_stationno();
    return (Fun_next)Page1;
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

    for (auto& i : arr_line) {
        printRouteBybusno(i);
    }
}

Fun_next Page2(){
    int start,end;
    cout<< "起始站:" <<endl;
    while ((start = searchStation()) < 0) {
        cout<< "不存在该站点编号,请重新输入" <<endl;
    }
    cout<< "终点站:" <<endl;
    while ((end = searchStation()) < 0) {
        cout<< "不存在该站点编号,请重新输入" <<endl;
    }

    set<int> visited;
    vector<Route*> route;
    vector<int> bus_num;

    visited.insert(start);

    searchRoute(visited,route,start,end,bus_num,station_map[start]);

    return (Fun_next)MainPage;
}

void searchRoute(set<int>& visited , vector<Route*>& route,int const& start, int const& end , vector<int>& bus_num , Station const& begin){
    if(start == end){
        cout<< "【" << begin << "】" ;
        for (auto i = route.begin(); i != route.cend(); ++i) {
            cout<< "--no:" << (*i)->bus_no << " --" << (*i)->distance_ << "m->【" << *(*i)->next_station << "】";           
        }
        cout<< endl;
        return;
    }

    Station& sta = station_map[start];
    for (auto i = sta.out_station.begin(); i != sta.out_station.end(); ++i) {
        int no = (*i)->next_station->no;
        if(visited.count(no)){
            return;
        }

        bus_num.push_back((*i)->bus_no);
        int count_num = 0;
        for (auto j = bus_num.begin(); j != bus_num.end()-1; ++j) {
            if(*j != *(j+1)){
                count_num ++;
            }
        }
        if(count_num > 1){
            return;
        }

        visited.insert(no);
        route.push_back(*i);

        searchRoute(visited,route,no,end,bus_num,begin);

        route.pop_back();
        visited.erase(visited.find(no));
        bus_num.pop_back();
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

    cout<< "线路名字:" << bus.name << endl
        << "线路编号: " << no_bus << endl
        << "路线为:" << endl
        << "begin=>" << start_station;

    Station* ptr_sta = &start_station;
    
    if(bus.begin == nullptr){
        for (auto i = ptr_sta->out_station.begin(); i != ptr_sta->out_station.cend(); ++i) {
            if((*i)->bus_no == no_bus){
                bus.begin = *i;
                break;
            }
        }
    }

    Route* ptr_route = bus.begin;
    travelRoute(ptr_route,[](Route*const proute){
            cout<< "--[" << proute->distance_ << "m]-> " << *(proute->next_station); 
    });

    cout<<endl<<endl;
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

Fun_next Page3(){
    cout<< "0: 退出" <<endl;
    cout<< "1: 增加站点" <<endl;
    cout<< "2: 增加公交路线 "<<endl;

    static const std::array<Fun_page,3> next_page = {MainPage,Page31,Page32};

    int next_page_no = getKeyvalue(next_page.size());
    return (Fun_next)next_page[next_page_no];
}

Fun_next Page31(){
    addStation();
    return (Fun_next)Page3;
}

Fun_next Page32(){
    addBus();
    return (Fun_next)Page3;
}


int getnoExistBus(){
    int no_bus;
    while(cin>>no_bus) {
        clearBuf();
        auto iter_bus = bus_map.find(no_bus);
        if(iter_bus == bus_map.end()){
            break;
        }
        cout<< "已存在该公交线路编号,请重新输入" << endl;
    }
    return no_bus;
}

void addBus(){
    int no_bus;
    cout<< "请输入公交线路编号" <<endl;
    no_bus = getnoExistBus();
    string bus_name;
    cout<< "请输入线路名字" <<endl;
    cin>>bus_name;
    clearBuf();
    int num;
    cout<< "请输入经过几站[n>=2]"<<endl;
    while(cin>>num){
        clearBuf();
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
            clearBuf();
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
            clearBuf();
        }
        Route* out_route = new Route(no_bus,dis,&end_station);

        start_station.add_out_station(out_route);

    }
    Buses bus(no_bus , bus_name , staion_line[0] , staion_line[staion_line.size()-1]  );
    map_instance.addBus(bus);
}

Fun_next Page4(){
    cout<< "0: 退出" <<endl;
    cout<< "1: 删除线路" <<endl;
    cout<< "2: 删除站点" <<endl;

    static const std::array<Fun_page,3> next_page = {MainPage,Page41,Page42};

    int next_page_no = getKeyvalue(next_page.size());
    return (Fun_next)next_page[next_page_no];
}

Fun_next Page41(){
    deleteBus();
    return (Fun_next)Page4;
}

Fun_next Page42(){
    deleteStation();
    return (Fun_next)Page4;
}

void deleteBus(){
    cout<< "请输入删除公交编号:" <<endl;
    int no_bus;
    no_bus = getExistBus();
    
    for (auto& i : station_map) {
        auto& rou = i.second.out_station;
        for (auto j = rou.begin(); j != rou.end(); ++j) {
            if((*j)->bus_no == no_bus){
                delete *j;
                rou.erase(j);
                break;
            }
        }
    }   

    bus_map.erase(bus_map.find(no_bus));
}

void deleteStation(){
    int sta_no;
    cout<< "请输入删除的站点编号" <<endl;
    sta_no = getExistStation();

    set<int> bus_link;
    for (auto& i : station_map[sta_no].out_station) {
        bus_link.insert(i->bus_no);
    }
    for (auto& i : station_map) {
        auto& rou = i.second.out_station;
        for (auto j = rou.begin(); j != rou.end(); ++j) {
            if(bus_link.count((*j)->bus_no)){
                delete *j;
                rou.erase(j);
            }
        }
    }

    for (auto& i : bus_link) {
        bus_map.erase(bus_map.find(i));
    }
    station_map.erase(station_map.find(sta_no));
}

int getExistStation(){
    int sta_no;
    while(cin>>sta_no){
        clearBuf();
        if(station_map.find(sta_no) != station_map.end()){
            break;
        }
        cout<< "输入站点编号不存在" <<endl;
    }
    return sta_no;
}

void updateStationName(){
    int sta_no;
    cout<< "请输入要更新的站点编号" <<endl;
    sta_no = getExistStation();
    cout<< "请输入更新后的名字" <<endl;
    string new_name;
    cin>> new_name;
    clearBuf();
    station_map[sta_no].name = new_name;
}

int getExistBus(){
    int bus_no;
    while (cin>>bus_no){
        clearBuf();
        if(bus_map.find(bus_no) != bus_map.end()){
            break;
        }
        cout<< "输入的公交编号不存在" <<endl;
    }
    return bus_no;
}

void updateBusName(){
    int bus_no;
    cout<< "请输入要更新的公交编号" <<endl;
    bus_no = getExistBus();
    cout<< "请输入更新后的名字" <<endl;
    string new_name;
    cin>> new_name;
    clearBuf();
    bus_map[bus_no].name = new_name;
}

Fun_next Page5(){
    int sta_no =  searchStation();

    if(sta_no < 0){
        cout<< "不存在该站点编号" <<endl;
    } else{
        cout<< station_map[sta_no] <<endl;
    }

    return (Fun_next)MainPage;
}

Fun_next Page6(){
    cout<< "0: 退出"<<endl;
    cout<< "1: 更新站点名称" <<endl;
    cout<< "2: 更新公交名称" <<endl;

    static const std::array<Fun_page,3> next_page = {MainPage,Page61,Page62};
    int next_page_no = getKeyvalue(next_page.size());
    return (Fun_next)next_page[next_page_no];

}

Fun_next Page61(){
        updateStationName();
        return (Fun_next)Page6;
}

Fun_next Page62(){
    updateBusName();
    return (Fun_next)Page6;
}

#endif

