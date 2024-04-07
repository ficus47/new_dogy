#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../native_func/char/print.h"

#ifndef evaluate1
#define evaluate1

int evaluate(char *arg[], char *func, int n_arg){
    printf("fonction : %s, func - 'print' : %d\n", func, strcmp(func, "print"));
    if (strcmp(func, "print") == 0 || strcmp(func, "println") == 0){
        print(arg, n_arg);
    }

    return -1;
}

#endif