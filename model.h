typedef struct Bus {
    const char* name;//公交名
    int start;//起点
    int end;//终点
}Bus;

typedef struct Station {
    const char* station;//站点名
    struct Route* routes;//从该站点出发的所有下行路线的链域
}Station;

typedef struct Route {
    int station;//指向的站点索引号
    int bus;//公交索引号
    int distance;//两站之间公路的距离
    struct Route* next;//起始站点相同的，下一条下行路线
}Route;

typedef struct BusMap {
    Bus* buses;//公交线路数组
    Station* stations;//站点数组
    int station_num;//站点数
    int bus_num;//公交线路数
    bool visited;//遍历时的标志符
}BusMap;

typedef struct Path {
    int station_num;//路径中站点数
    char** stations;//路径中各站点数组
    char** buses;//站点与站点之间的路径数组
    int transfer;//换乘次数
    int need_time;//所需时间
    struct Path* next;//指向下一个路径节点
}Path;
