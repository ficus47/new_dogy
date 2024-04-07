#include <stdio.h>

#ifndef find
#define find

int is_char_in_string(char c, char *str, char a, char b) {
    int count = 0;
    int inside_parentheses = 1;

    // Parcourir la chaîne caractère par caractère
    while (*str) {
        // Vérifier si le caractère est une parenthèse
        if (*str == a) {
            inside_parentheses = 0;
            count++;
        } else if (*str == b) {
            inside_parentheses = 1;
            count--;
        }

        // Vérifier si le caractère n'est pas entre parenthèses et est égal à celui recherché
        if (!inside_parentheses && *str == c) {
            return 0;
        }

        str++;
    }

    // Vérifier si les parenthèses sont bien équilibrées

    return 1;
}

#endif