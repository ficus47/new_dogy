#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef extract
#define extract

char* extract_between_characters(char *str, char start_char, char end_char) {
    char *start_pos = strchr(str, start_char); // Recherche du premier caractère de début
    char *end_pos = strchr(str, end_char);     // Recherche du premier caractère de fin
    
    char *result;

    // Vérification si les caractères de début et de fin sont présents dans la chaîne
    if (start_pos != NULL && end_pos != NULL && start_pos < end_pos) {
        size_t length = end_pos - start_pos - 1;  // Calcul de la longueur du contenu extrait
        result = (char *)malloc(length + 1);      // Allouer de la mémoire pour le contenu extrait
        if (result != NULL) {
            strncpy(result, start_pos + 1, length); // Copie du contenu extrait dans le nouveau tableau
            result[length] = '\0';                  // Ajout du caractère de fin de chaîne
        } else {
            printf("Erreur : échec de l'allocation de mémoire.\n");
        }
    } else {
        return NULL;
    }

    return result;
}

#endif