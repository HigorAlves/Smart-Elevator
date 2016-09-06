#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

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

void criaLista(filinha *pointer);
int primeiroLista(filinha pointer, Pessoa *passa);
int filaVazia(filinha pointer);
int coloca(filinha *pointer, Pessoa pass);
int remove(filinha *pointer, Pessoa *pass);
int mostra(filinha *pointer);

#endif
