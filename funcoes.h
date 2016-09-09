#ifndef FUNCOES_H
#define FUNCOES_H

/* BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h> //BIBLIOTECA DO GETOPT
/* FIM BIBLIOTECAS */

/* Definição das structss */
typedef struct {
    int tempo_espera;
    int tempo_percurso;
    int tempo_total;

    int onde_ta;  //Onde o passeiro esta
    int onde_vai; //Onde o passageiro quer ir
} _passageiros;

typedef struct {
    int andar_atual;
    int quant_andares;
    int capacidade;
} _elevador;

typedef struct tempo{
	double tempoU,tempoS;
	struct rusage resources;
	struct timeval inicioU, inicioS, fimU, fimS;
}_tempo;

/* Fim das structs */

/* Definição das funções */
void show_help(char *arquivo_passageiro);
void randomiza_passageiros(_passageiros *passageiro, FILE *IN_passageiros, int tam_pax, int qtd_andar);
/* TEMPO GETRUSAGE */
void iniciaTempo(_tempo *t);
void finalizaTempo(_tempo *t,double *tempoU, double *tempoS);
void zera_tempo(double *tempoUser, double *tempoSis);
/* ESCALONAMENTOS */
void fifo(_passageiros *passageiros, int quantidade_passageiros, FILE *OUT_FIFO, _elevador elevador);
void sjf(_passageiros *passageiros, int quantidade_passageiros, FILE *OUT_SJF, _elevador elevador);
/* Fim das funções */
#endif
