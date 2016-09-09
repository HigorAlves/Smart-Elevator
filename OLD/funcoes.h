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

void VerificaAmbiente(int onde_ta, int onde_vai, int andares);
int mudou_andar(int onde_ta, int *tava);
void entrega(filinha *pointer, int *jepslon_andar, int *jepslon_porta, int *elevador_ta, Pessoa *pass);

void criaLista(filinha *pointer);
int primeiroLista(filinha pointer, Pessoa *passa);
int filaVazia(filinha pointer);
int colocar(filinha *pointer, Pessoa pass);
int remover(filinha *pointer, Pessoa *pass);
int mostrar(filinha *pointer);

#endif
