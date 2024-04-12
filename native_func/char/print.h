#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef print1
#define print1

int print(char *args[], int n_arg){
    for (int i = 0; i < n_arg; i++){
        printf("%s ", args[i]);
    }
    printf("\n");
    return 0;

}

#endif