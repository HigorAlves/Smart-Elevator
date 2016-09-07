#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <unistd.h>

typedef struct elevador{
  int andares;
  int capacidade;
} _elevador;

typedef struct pessoa{
  int onde_ta;
  int onde_vai;
}Pessoa;

typedef struct no{
  Pessoa elemento;
  struct no *proximo;
}Node;

typedef struct fila{
  Node *inicio;
  Node *final;
}filinha;

void show_help(char *estrategia);

int mudou_andar(int onde_ta, int *tava);
void VerificaAmbiente(int onde_ta, int onde_vai, int andares);
int lotou(int *lotado, int capacidade);

void criaLista(filinha *pointer);
int primeiroLista(filinha pointer, Pessoa *passa);
int filaVazia(filinha pointer);
int colocar(filinha *pointer, Pessoa pass);
int remover(filinha *pointer, Pessoa *pass);
int mostrar(filinha *pointer);

#endif
