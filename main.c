#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "execution/choose/choose.h"

void read(char i[], char b[], int number){
  FILE *file = fopen(b, "r");
  char c;

  char buff[100];
  

  if (file == NULL){
    printf("Error: can't open file %s\n", b);
  }
  while(fgets(buff, 100, file) != NULL ){
    strcat(i, buff);
    if (c == '\n'){
      number++;
    }
  }
  number++;

  
  fclose(file);
}

int list_line(char *a, char *c[]) {
    char *b = strtok(a, "\n");
    int i = 0;

    while (b != NULL && i < 100) {
        c[i] = strdup(b); // Allouer dynamiquement de la mémoire pour chaque ligne
        if (c[i] == NULL) {
            printf("Erreur : échec de l'allocation de mémoire.\n");
            exit(EXIT_FAILURE);
        }

        i++;
        b = strtok(NULL, "\n");
    }
    return i;
}


int main(int argc, char *argv[]) {//printf("bonjour");
  if (argc < 2){
    printf("Error : no file given\n");
    exit(666);
    argv[1] = "saucisse.dog";
  }

  char content[999] = "";
  int number = 0;
  
  read(content, argv[1], number);
  printf("%s a\n", content);

  char *lines[100];

  int num = list_line(content, lines) - 1;

  for (int i = 0; i <= num; i++){
    char a[100];
    strcpy(a, " ");
    strcat(a, lines[i]);
    printf("a : %s\n", a);
    choose(a);
  }

}
