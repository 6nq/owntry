#include "../moudle/base.h"
#ifndef PAGE_H
#define PAGE_H


using Fun_page = void*(*)(void);
using Fun_do = void(*)(void);
using Fun_next = void*;

void clearBuf();
int getKeyvalue(int max_num);
Fun_next MainPage();
    Fun_next Page1();
        Fun_next Page11();
        Fun_next Page12();
    Fun_next Page2();
    Fun_next Page3();
        Fun_next Page31();
        Fun_next Page32();
    Fun_next Page4();
        Fun_next Page41();
        Fun_next Page42();
    Fun_next Page5();
    Fun_next Page6();
        Fun_next Page61();
        Fun_next Page62();
    Fun_next NoPage();
    inline constexpr Fun_next NullPage()noexcept;
int getExistStation();
int getnoExistBus();
int getExistBus();
void updateBusName();
void updateStationName();
void addStation();
void addBus();
int  searchStation();
void search_By_busno();
void search_By_stationno();
void printRouteBybusno(int const&);
void searchRoute(set<int>& visited , vector<Route*>& route,int const& start, int const& end , vector<int>& bus_num , Station const& begin);
void deleteBus();
void deleteStation();

#endif /* PAGE_H */
