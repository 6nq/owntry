#include <iostream>
#include <concepts>
#include <tuple>

using namespace std;

int main(void)
{
    auto x = [](int n,int m)->int{
        return n*m;
    };
    auto y = [](int n){
        return n*n;
    };
    tuple<int,int> a = {7,4};
    auto z = apply(x,a);
    cout << y(z) << endl;
    return 0;
}
