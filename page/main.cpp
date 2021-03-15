#include "../fileio/fileio.cpp"
#include "mainpage.cpp"

FileIo& fileio_instance = FileIo::getFileIoInstance();

int main()
{
    MainPage();
    return 0;
}
