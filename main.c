#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "newmalloc.h"
#include "map.c"

void run();
void print();

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

