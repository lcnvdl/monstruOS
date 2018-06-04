#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#ifdef __cplusplus
    #define APIDEF extern "C"
    #define APIDEC extern "C"
#else
    #define APIDEF
    #define APIDEC extern
#endif

inline void* operator new(unsigned size)
{
    return 0;
}

inline void* operator new[](unsigned size)
{
    return 0;
}

inline void* operator new(unsigned size, void* ptr)
{
    return ptr;
}

inline void* operator new[](unsigned size, void* ptr)
{
    return ptr;
}

inline void operator delete(void* ptr)
{
    int i = 0;
}

inline void operator delete[](void* ptr)
{
    int i = 0;
}

inline void operator delete(void* ptr, unsigned size)
{
    int i = 0;
}

inline void operator delete[](void* ptr, unsigned size)
{
    int i = 0;
}

#endif