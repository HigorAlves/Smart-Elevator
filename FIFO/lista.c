#include "lista.h"

  void criaLista(filinha *pointer){
    pointer->inicio = NULL;
    pointer->final = NULL;
  }

  int primeiroLista(filinha pointer, Pessoa *passa){
    if(filaVazia(pointer))
    return 0;
    *passa = (pointer.inicio)->elemento;
    return 1;
  }

  int filaVazia(filinha pointer){
    if (pointer.inicio == NULL && pointer.final == NULL){
      return 1;
    }
  }

  int colocar(filinha *pointer, Pessoa pass){
    Node *newmemo;
    newmemo = (Node*) malloc(sizeof(Node));

    newmemo->elemento.onde_ta = pass.onde_ta;
    newmemo->elemento.onde_vai = pass.onde_vai;
    newmemo->proximo = NULL;
    if (filaVazia(*pointer)){
      pointer->inicio = newmemo;
    }else
      (pointer->final)->proximo = newmemo;
      pointer->final = newmemo;
      return 1;
  }

  int remover (filinha *pointer, Pessoa *pass){
    Node *aux;
    if(pointer->inicio == NULL){
      return 0;
    }
    aux = pointer->inicio->proximo;
    free(pointer->inicio);
    pointer->inicio = aux;
    return 1;
  }

  int mostrar(filinha *pointer){
    Node *aux;
    if (filaVazia (*pointer)) {
      printf("fila vazia\n");
    }else
    aux = pointer->inicio;
    printf("%d %d\n", aux->elemento.onde_ta, aux->elemento.onde_vai);
    while (aux->proximo != NULL) {
      aux = aux->proximo;
      printf("%d %d\n", aux->elemento.onde_ta, aux->elemento.onde_vai);
    }
  }
