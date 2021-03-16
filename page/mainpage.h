#include "../moudle/base.h"
#ifndef PAGE_H
#define PAGE_H

void clearBuf();
char const getKeystroke();
void MainPage();
void Page1();
void Page2();
void Page3();
void Page4();
void Page5();
void addStation();
void addBus();
int  searchStation();
void search_By_busno();
void search_By_stationno();
void printRouteBybusno(int const&);

#endif /* PAGE_H */
