#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../func/is_func.h"
#include "../char/extract.h"
#include "../exec/evaluate.h"
#include "../args/list_arg.h"
#include "../init.h"

#ifndef choose1
#define choose1



int choose(char func[]){
    printf("func : %s\n", func);
    if (is_func(func) == 0){
        char *arg;
        arg = extract_between_characters(func, '(', ')');

        char *command;
        command = extract_between_characters(func, ' ', '(');

        printf("\nargument : %s fonction : %s\n", arg, command);

        char *arg_list[50];
        int n_arg = list_arg(arg, arg_list);

        evaluate(arg_list, command, n_arg);

    }
    else{
        printf("\nerror \n");
        return 1;
    }

}

#endif