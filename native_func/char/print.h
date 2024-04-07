#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef print1
#define print1

int print(char *args[], int n_arg){
    printf("%d\n", n_arg+1);
    for (int i = 0; i <= n_arg+1; i++){
        printf("%s", args[i]);
    }
    return 0;

}

#endif