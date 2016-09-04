#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct {
  int onde_ta;
  int onde_vai;
} _Passageiros;


void estrategia_fifo(char *arq, int i, int size, int capacidade, int quant_andares, int jepslon){
  _Passageiros *passageiros;
  char *pch = NULL, *pch2=NULL;
  passageiros = malloc (size * sizeof( _Passageiros));

    if (i > capacidade){
      printf("Ta lotado %i\n",i);

    }

    /* Pega onde está o passageiro */
    pch = strtok (arq," ");
    passageiros[i].onde_ta = atoi (pch);
    if (passageiros[i].onde_ta > quant_andares || passageiros[i].onde_ta < 0){
      printf("O arquivo do passageiro tem mais andares que o ambiente do elevador ou ha algum andar negativo!%i\n",quant_andares);
      exit(1);
    }

    /* Pega o para onde vai o passageiro */
    while (pch != NULL)
    {
      passageiros[i].onde_vai = atoi (pch);
      pch = strtok (NULL, " ");
      if (passageiros[i].onde_vai > quant_andares){
        printf("O arquivo do passageiro tem mais andares que o ambiente do elevador ou ha algum andar negativo!\n");
        exit(1);
      }
    }
    printf ("%i, %i %i\n", i, passageiros[i].onde_ta, passageiros[i].onde_vai);


  /* limpando os mallocs */
  free(passageiros);
}
