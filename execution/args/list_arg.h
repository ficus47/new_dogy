#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int list_arg(const char *input_string, char *arguments[]) {
    // Vérifier si la chaîne d'entrée est NULL
    if (input_string == NULL) {
        return 0;
    }

    // Initialiser le compteur d'arguments
    int arg_count = 0;

    // Déclarer un pointeur temporaire vers un argument
    const char *start_quote = strchr(input_string, '\"');
    const char *end_quote = NULL;
    char *temp_arg = NULL;

    // Tant qu'il y a des guillemets
    while (start_quote != NULL) {
        // Rechercher le dernier guillemet après le premier guillemet trouvé
        end_quote = strchr(start_quote + 1, '\"');

        // Si un deuxième guillemet est trouvé
        if (end_quote != NULL) {
            // Allouer de la mémoire pour l'argument
            temp_arg = strdup(start_quote + 1);

            // Remplacer le dernier guillemet par un caractère nul pour terminer la chaîne
            temp_arg[end_quote - start_quote - 1] = '\0';

            // Ajouter l'argument à la liste
            arguments[arg_count] = temp_arg;
            arg_count++;
        }

        // Rechercher le prochain guillemet dans la chaîne
        start_quote = strchr(end_quote + 1, '\"');
    }

    return arg_count;
}