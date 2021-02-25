#include <iostream>
#include "bus_System_Config.h"

using namespace std;

int main(int argc , char* argv[])
{
    if (argc < 2) {
        //report version
        cout<< argv[0] <<"Version " << bus_System_VERSION_MAJOR << "."
            << bus_System_VERSION_MINOR << endl;
        cout<< "Usage: " << argv[0] << "number" << endl;
        return 1;
    }
    for (int i = 0; i < argc; ++i) {
        cout<< argv[i] <<endl;
    }
    return 0;
}
