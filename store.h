#include "moudle/base.h"
#include "config.h"

#ifndef STORE_H
#define STORE_H

class Store
{
public:
    static Store&  getStoreInstance();
    ~Store ();

private:
    Store ()=default;

    void writeback();
    void writeStation();
    void writeBuses();
    void writeRoute();
};

#endif /* STORE_H */
