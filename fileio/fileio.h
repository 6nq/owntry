#include "../moudle/base.h"
#include "config.h"


#ifndef INIT_H
#define INIT_H

class FileIo
{
public:
    static FileIo& getFileIoInstance();

    void writeback();
private:
    FileIo();
    ~FileIo();
    FileIo(FileIo const&)=delete;
    FileIo& operator=(FileIo const&)=delete;

    void FileIoStation();
    void FileIoBuses();
    void FileIoRoute();

    void writeStation();
    void writeBuses();
    void writeRoute();

};

#endif /* INIT_H */
