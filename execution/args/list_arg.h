#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int list_arg(char *input_string, char *argument[]) {
  // Vérifier si la chaîne d'entrée est NULL
  if (input_string == NULL) {
    return 0;
  }

  // Initialiser le compteur d'arguments
  int count = 0;

  // Déclarer un pointeur temporaire vers un argument
  char *temp_arg = NULL;

  // Rechercher le premier guillemet dans la chaîne
  const char *start_quote = strchr(input_string, '\"');

  // Tant qu'il y a des guillemets
  while (start_quote != NULL) {
    // Allouer de la mémoire pour l'argument
    temp_arg = malloc(50 * sizeof(char));

    // Rechercher le dernier guillemet après le premier guillemet trouvé
    const char *end_quote = strchr(start_quote + 1, '\"');

    // Si un deuxième guillemet est trouvé
    if (end_quote != NULL) {
      // Copier l'argument entre les guillemets dans le tableau d'arguments
      int arg_length = end_quote - start_quote - 1;
        strncpy(temp_arg, start_quote + 1, arg_length);
        temp_arg[arg_length] = '\0';
        printf("%s\n", temp_arg);
        strcpy(argument[count], temp_arg);
        count++;
    }

    // Rechercher le prochain guillemet dans la chaîne
    start_quote = strchr(end_quote + 1, '\"');
  }

  return count;
}