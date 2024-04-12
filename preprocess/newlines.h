#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef new_line
#define new_line

void new_lines(char *a){
    char lines[999];
    int count = 0;

    int j = 0;
    int length = strlen(a);

    for (int i = 0; i < length; i++) {
        if (a[i] == '\\' && a[i+1] == 'n') {
            lines[j++] = '\n';
            i++; // Skip the second character of '\n'
        } else {
            lines[j++] = a[i];
        }
    }
    lines[j] = '\0'; // Null-terminate the output string

    strcpy(a, lines);
}

#endif