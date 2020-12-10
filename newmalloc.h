#include <stdio.h>
#include <stdlib.h>
void* _malloc(size_t size){
    void* ptr = malloc(size);
    if(ptr == NULL)
    {
        printf("Memory is not enough.\n");
        exit(0);
    }
    return ptr;
}
