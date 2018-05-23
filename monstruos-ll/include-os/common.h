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

#endif