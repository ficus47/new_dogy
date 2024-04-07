#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../char/quotes.h"

#ifndef is_func1
#define is_func1

int is_func(char content[]){
    if (is_char_in_string('(', content, '"', '"')){
        return 0;
    }
    else{
        return 1;
    }
}

#endif