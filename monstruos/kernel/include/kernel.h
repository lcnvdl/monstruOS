#ifndef KERNEL_H
#define KERNEL_H

#include "common.h"

#ifdef fix_asm_fns
#define KMAIN _kernel_main
#else
#define KMAIN kernel_main
#endif

void user_input(char *input);

#endif
