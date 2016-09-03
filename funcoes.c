#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define DELIMITER " -\n"

typedef struct {
  int onde_ta;
  int onde_vai;
} _Passageiros;

void estrategia_fifo(char *arq, int i, int size){
  _Passageiros *passageiros;
  char *pch = NULL;

  passageiros = malloc (size * sizeof( _Passageiros));

  /* Pega onde está o passageiro */
  pch = strtok (arq," ,.-");
  passageiros[i].onde_ta = atoi (pch);

  /* Pega o para onde vai o passageiro */
  while (pch != NULL)
  {
    passageiros[i].onde_vai = atoi (pch);
    pch = strtok (NULL, " ,.-");
  }

  printf("%i ", passageiros[i].onde_ta);
  printf("%i\n", passageiros[i].onde_vai);

  /* limpando os mallocs */
  free(passageiros);
}
