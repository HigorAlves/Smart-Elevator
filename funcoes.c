#include "funcoes.h"

/* Mostra a ajuda */
void show_help(char *estrategia) {
  fprintf(stderr, "\
    [uso] ./tp1 <opcoe> -o <metodo>\n\
    -h  Mostra a tela de ajuda e sai dela. \n\
    -a  Seta a quantidade de andares.\n\
    -c  Seta a capacidade do elevador.\n\
    -e  Nome do arquivo do elevador. \n\
    -p  Nome do arquivo dos passageiros.\n\
    -o  Use FIFO ou SJF como estrategia. \n");
  exit(-1) ;
}

void VerificaAmbiente(int onde_ta, int onde_vai, int andares){
  if (onde_ta > andares || onde_ta < 0){
    printf("O andar %i onde o passageiro está não existe no ambiente do elevador.\nReveja o arquivo para retornar a executar o programa.", onde_ta);
    exit(1);
  }else if (onde_vai > andares || onde_vai <0){
    printf("O andar %i onde o passageiro deseja ir não existe no ambiente do elevador.\nReveja o arquivo para retornar a executar o programa.", onde_vai);
    exit(1);
  }
}

void entrega(filinha *pointer, int *jepslon_andar, int *jepslon_porta, int *elevador_aqui, Pessoa *eu){
  Node *aux2;
  if (filaVazia (*pointer)) {
    printf("Todos entregues\n");
  }else
    aux2 = pointer->inicio;
      /* Se o elevador não estiver no mesmo andar */
  if (aux2->elemento.onde_ta != *elevador_aqui){
  //  *jepslon_porta = *jepslon_porta + 1;
    *jepslon_andar = *jepslon_andar + abs(aux2->elemento.onde_vai - *elevador_aqui);
    *elevador_aqui = aux2->elemento.onde_ta;
  }

  if (aux2->elemento.onde_vai != *elevador_aqui) {
    //*jepslon_porta = *jepslon_porta + 1;
    *jepslon_andar = *jepslon_andar + abs(aux2->elemento.onde_vai - *elevador_aqui);
    *elevador_aqui = aux2->elemento.onde_vai;
  }
  *jepslon_porta = *jepslon_porta + 1;
  while (aux2->proximo != NULL) {
    aux2 = aux2->proximo;
    /* Se o elevador não estiver no mesmo andar */
    if (aux2->elemento.onde_ta != *elevador_aqui){
      *jepslon_andar = *jepslon_andar + abs(aux2->elemento.onde_vai - *elevador_aqui);
      *elevador_aqui = aux2->elemento.onde_vai;
    }

    if (aux2->elemento.onde_vai != *elevador_aqui) {
      //*jepslon_porta = *jepslon_porta + 1;
      *jepslon_andar = *jepslon_andar + abs(aux2->elemento.onde_vai - *elevador_aqui);
      *elevador_aqui = aux2->elemento.onde_vai;
    }

  }
  *jepslon_porta = *jepslon_porta + 1;
}

int mudou_andar(int onde_ta, int *tava){
 if(*tava != onde_ta){ //Mudou de andar; Contar jepslon
    *tava = onde_ta;
    return 1;
  }else{ //Recebe o valor de onde ta so por segurança
    *tava = onde_ta;
    return 0;
  }
}

  /* FUNÇÃO FIFO */

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
    }else{
      return 0;
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
