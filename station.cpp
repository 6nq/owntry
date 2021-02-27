#include "station.h"
#include <cassert>
using namespace std;

template<typename T,std::size_t N>
constexpr std::size_t arraysize(T (&)[N])noexcept{
    return N;
}

int main(void)
{
    char buffer[1024];
    Station* sta = new(buffer)Station;
    sta->print();
    return 0;
}
