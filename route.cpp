#include "route.h"

Route::Route(int const& no_bus,int const& distance_l,Station*const nextStation)
    :bus_no(no_bus),distance_(distance_l),next_station(nextStation){
    }


/* int main(void) */
/* { */
/*     cout<< sizeof(Route)<<endl; */
/*     return 0; */
/* } */
