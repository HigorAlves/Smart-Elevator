#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

typedef struct {
  int onde_ta;
  int onde_vai;
} _Passageiros;

typedef struct {
  int to_aqui;
  int tava ;
} _Elevador;

void estrategia_fifo(char *arq, int i, int size, int capacidade, int quant_andares, int jepslon, int teste){

  _Passageiros *passageiros;
  _Elevador elevador;
  char *pch = NULL;
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

    /* verifica se mudou de andar */
    elevador.to_aqui = passageiros[i].onde_ta;

    if (elevador.to_aqui != elevador.tava){
      if (elevador.tava == 0){
      }else{
        printf("Mudou\n");
        //entrega os do andar
      }
    }
    elevador.tava = elevador.to_aqui;

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

    printf ("%i, %i %i - %i %i\n", i, passageiros[i].onde_ta, passageiros[i].onde_vai, elevador.to_aqui,elevador.tava);


  /* limpando os mallocs */
  free(passageiros);
}
