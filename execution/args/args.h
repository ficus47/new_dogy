#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef list_args1
#define list_args1

#define MAX_ARGS 25

void list_args(int argc, char *argv[], char *args_list[]) {
    // Vérifier si le nombre d'arguments est valide
    if (argc > MAX_ARGS) {
        printf("Nombre d'arguments supérieur à la capacité maximale.\n");
        exit(1);
    }

    // Stocker chaque argument dans la liste
    for (int i = 0; i < argc; i++) {
        // Allouer de la mémoire pour stocker chaque argument
        args_list[i] = (char *)malloc(strlen(argv[i]) + 1);
        if (args_list[i] == NULL) {
            printf("Erreur lors de l'allocation de mémoire.\n");
            exit(1);
        }

        // Copier l'argument dans la liste
        strcpy(args_list[i], argv[i]);
    }
}

#endif