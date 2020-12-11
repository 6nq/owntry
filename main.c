#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "newmalloc.h"
#include "map.c"

void run();
void print();
void FindStationinfo();
void FindBusinfo();

int main(void)
{
    run();
    return 0;
}
void print(){
        printf("==========公交管理系统==========\n");
        printf("1.查询公交线路\n");
        printf("2.查询站点信息\n");
        printf("3.查询两个站点公交线路\n");
        printf("0.退出\n");
}

void run(){
    char ch;
    print();
    LoadBusMap();
    while((ch = getchar())){
        switch(ch){
            case '0':
                return;
            case '1':
                break;
            case '2':
                FindStationinfo();
                break;
            case '3':
                break;
            default:
                break;
        }
        system("clear");//清除屏幕信息Linux
        //system("cls");//清除屏幕信息Windows
        print();
    }
}

void FindStationinfo(){
    printf("===== 查询站点信息 =====\n");
    printf("请输入要查询的站点名:");
    char stationname[30];
    scanf("%s",stationname);
    printf("------------------------\n");
    printf("[%s站]:\n",stationname);
    int sum = QueryStation(stationname);
    printf("共%d辆车经过\n",sum);
}
void FindBusinfo(){
    printf("===== 查询公交信息 =====\n");
    printf("请输入要查询的公交名:");
    char busname[30];
    scanf("%s",busname);
    printf("------------------------\n");
    int sum = QueryBus(busname);
    printf("共%d辆车经过。\n",sum);
}
