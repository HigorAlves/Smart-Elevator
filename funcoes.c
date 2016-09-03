#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define DELIMITER " -\n"

typedef struct {
  int onde_ta;
  int onde_vai;
} _Passageiros;

void estrategia_fifo(char *arq){
  int n = 255, i=0;
  _Passageiros *passageiros;
  char *pch, *word;

  passageiros = malloc (n * sizeof(_Passageiros));

  pch = strtok (arq," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    i = atoi (pch);
    pch = strtok (NULL, " ,.-");
  }

  printf("%i", i+1);

  /* limpando os mallocs */
  free(passageiros);
}
