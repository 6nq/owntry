#include <iostream>
#include "scheme.h"

using namespace std;


using x = cons(num(3),num(9));
using y = list<num(4),num(1),num(7)>;
using z = list<>;

constexpr auto c = is_nil<y>;
constexpr auto m = If( car(x)::value == car(y)::value )
                    Then(car(car(cons(x,y))))
                    Else(car(car(cons(y,x))))
                                                ::value;
int main(void)
{
    cout<<  cdr(cdr(cdr(y))) ::value <<endl;
    /* cout<< c <<endl; */

    /* cout<< typeid(typeof(num(1))).name() <<endl; */
    /* cout<< typeid(num(1)).name() <<endl; */
    /* cout<< typeid(car(cdr(cons(num(3),cons(num(7),num(9)))))).name() <<endl; */
    /* cout<< typeid(typeof(car(cons(num(3),num(7))))).name() <<endl; */
    /* cout<< typeid(car(y)).name() <<endl; */

    auto &&x = make_index_sequence_own<6>::value ;
    for (int i = 0; i < 6; ++i) {
        cout<< x[i] <<endl;
    }
    return 0;
}
