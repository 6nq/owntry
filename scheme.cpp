#include <iostream>
#include "scheme.h"

using namespace std;


using a = list<num(2)>;
using x = cons(list<num(1)>,list<num(1)>);
using y = list<num(1)>;
using z = cons(y,y);


template<typename T>
struct setcartoA {
    /* data */
};

/* using z = list<>; */

/* constexpr auto c = is_nil<z>; */

int main(void)
{
    cout<< is_same_type(x,z) <<endl;
    /* cout<< c <<endl; */


    /* auto &&x = make_index_sequence_own<6>::value ; */
    /* for (int i = 0; i < 6; ++i) { */
    /*     cout<< x[i] <<endl; */
    /* } */
    return 0;
}
