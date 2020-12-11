#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "data.h"
#define None -1
#define Status int
#define ST_OK 1
#define ST_FAIL 0

static BusMap map;
void Load();//加载
void LoadMapDate();//加载地图信息
void LoadBusMap();//加载公交线路信息
void Loadstation();//加载站点信息
int FindBus(char* bus);//查找Bus对象并返回其索引
int GetBus(char*bus);//插入一个公交线路并返回其索引，已经存在直接返回索引
int FindStaion(char* station);//查找Staion对象，返回其索引号
int GetStaion(char* station);//插入一个站点并返回其编号,若存在则直接返回编号
void AddBus(const char* bus,const char* pstart,const char* pend);//添加公交车信息
Status AddRoute(const char* pbus,const char* pstart,const char* pend,int distance);//添加路段信息，形成邻接表
int QueryStation(char* pStation);//查询站点信息，输出该站点所经过路线信息
int QueryBus(char* pbus);

void Load(){
    LoadBusMap();
    Loadstation();
    LoadMapDate();
}
void LoadBusMap(){
    map.bus_num = BUS_NUM;
    map.buses = (Bus*)malloc(BUS_NUM*sizeof(Bus));
    for (int i = 0; i < BUS_NUM; ++i) {
        map.buses[i].name = BUSES[i][0];
    }
}

void Loadstation(){
    map.station_num = STATION_NUM;
    map.stations = (Station*)malloc(STATION_NUM*sizeof(Station));
    for (int i = 0; i < STATION_NUM; ++i) {
        map.stations[i].station = STATIONS[i];
        map.stations[i].routes = NULL;
    }
}

void LoadMapDate(){
    //添加公交线路信息
    for (int i = 0; i < BUS_NUM; ++i) 
        AddBus(BUSES[i][0],BUSES[i][1],BUSES[i][2]);
    for (int i = 0; i < ROUTE_NUM; ++i)
        AddRoute(STATIONS[ROUTES[i][0]],STATIONS[ROUTES[i][1]],STATIONS[ROUTES[i][2]],ROUTES[i][3]);
}

int FindBus(char* bus){
    for (int i = 0; i < map.bus_num; ++i) {
        if(strcmp(map.buses[i].name,bus) == 0)
            return i;
    }
    return None;
}

int GetBus(char*bus){
    int nBus = FindBus(bus);
    if(nBus == None){

        map.buses =(Bus*)realloc(map.buses,(map.bus_num + 1)*sizeof(Bus));
        Bus *pbus = map.buses + map.bus_num;
        pbus->name = bus;
        pbus->start = pbus->end = None;
        nBus = map.bus_num;
        map.bus_num++;
    }
    return nBus;
}

int FindStaion(char* station){
    for (int i = 0; i < map.station_num; ++i) {
       if(strcmp(map.stations[i].station,station) == 0)
            return i;
    }
    return  None;
}
int GetStaion(char* station){
    int nstation = FindStaion(station);
    if(nstation == None){

        map.stations =(Station*)realloc(map.stations,(map.station_num + 1)*sizeof(Station));
        Station *pstation = map.stations + map.station_num;
        pstation->station = station;
        pstation->routes = NULL;
        nstation = map.station_num;
        map.bus_num++;
    }
    return nstation;
}
void AddBus(char* bus,char* pstart,char* pend){
    int nbus = GetBus(bus);
    int nstart = GetStaion(pstart);
    int nend = GetStaion(pend);
    Bus* pbus = map.buses + nbus;
    pbus->start = nstart;
    pbus->end = nend;
}
Status AddRoute(char* pbus,char* pstart,char* pend,int distance){
    int nbus = GetBus(pbus);
    int nstart = GetStaion(pstart);
    int nend = GetStaion(pend);
    //输入起点的出边链域
    Station* pstation = &map.stations[nstart];
    Route* proute = pstation->routes;

    while (proute!=NULL && pstation!=NULL) {
        //判断该边是否存在，存在则不插入
        if(proute->bus == nbus && proute->next == NULL)
            return ST_FAIL;
        proute = proute->next;   
    }
    //创建新的路线
    Route* pNewRoute = (Route*)malloc(sizeof(Route));
    pNewRoute->bus = nbus;
    pNewRoute->station = nend;
    pNewRoute->distance = distance;
    pNewRoute->next = NULL;
    
    //若是起始顶点的第一条边
    if(proute == NULL)
        pstation->routes = pNewRoute;
    else
        proute->next = pNewRoute;
    
    return ST_OK;
}
int QueryStation(char* pStation){
    int nstation = FindStaion(pStation);
    int num = 0;
    Route* route = map.stations[nstation].routes;
    while (route != NULL) {
        printf("%s\n",map.buses[route->bus].name);
        route = route->next;
        num++;
    }
    return num;
}
int QueryBus(char* pbus){
    int nbus = FindBus(pbus);
    int start = map.buses[nbus].start;
    int end = map.buses[nbus].end;
    int num = 0;
    printf("[%s] 从%s出发，%s为终点\n",pbus,map.stations[start].station,map.stations[end].station);

    Route* route = map.stations[start].routes;
    while (route != NULL) {
        if(nbus  != route->bus) {
            route =route->next; 
            continue;
        }
        ++num;
        start =  route->station;
        if(start != end){
            printf("%s->",map.stations[start].station);
            route = map.stations[start].routes;
            continue;
        }
        printf("%s\n",map.stations[end].station);
    }
    return num;
}
