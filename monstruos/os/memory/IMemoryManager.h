#ifndef IMEMORYMANAGER_H
#define IMEMORYMANAGER_H

#include "common.h"

class IMemoryManager {
    public:
        virtual void* allocate(void*, size_t) = 0;
        virtual void free(void*) = 0;
}

#endif