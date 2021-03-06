#include <iostream>
#include "scheme.h"



using x = cons(num(3),num(9));
using y = list<num(4),num(1),num(7)>;

using namespace std;
/* constexpr auto z = If<car(x)::value == car(y)::value */
/*                     ,num(4) */
/*                     ,num(5)>::type::value; */
constexpr auto z = If<is_same_type(car(x),car(y))
                    ,num(4)
                    ,num(5)>::type::value;
constexpr auto m = If( car(x)::value == car(y)::value )
                    Then(car(car(cons(x,y))))
                    Else(car(car(cons(y,x))))
                                                ::value;
int main(void)
{
    cout<< car(cdr(cdr(y)))::value <<endl;
    cout<< car(x)::value <<endl;
    cout<< z <<endl;

    /* cout<< typeid(typeof(num(1))).name() <<endl; */
    cout<< typeid(num(1)).name() <<endl;
    cout<< typeid(car(cdr(cons(num(3),cons(num(7),num(9)))))).name() <<endl;
    /* cout<< typeid(typeof(car(cons(num(3),num(7))))).name() <<endl; */
    cout<< typeid(car(y)).name() <<endl;

    /* constexpr  int const(&arr)[50] = pck_int<50>::type::value; */
    /* for (int i = 0; i < 50; ++i) { */
    /*     cout<< arr[i] <<endl; */
    /* } */
    return 0;
}
