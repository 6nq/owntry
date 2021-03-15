#include "moudle/base.h"
#include "fileio/fileio.cpp"
#include "page/mainpage.cpp"

FileIo& fileio_instance = FileIo::getFileIoInstance();

int main()
{
    MainPage();
    return 0;
}
