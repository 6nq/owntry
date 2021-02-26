#include <iostream>
#include "bus_System_Config.h"

using namespace std;

int main()
{
    //report version
    cout<< "Version " << bus_System_VERSION_MAJOR << "."
        << bus_System_VERSION_MINOR << endl;

    return 0;
}
