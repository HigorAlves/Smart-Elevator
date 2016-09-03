#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*lib do GETOPT */
#include <unistd.h>
#include "funcoes.h"


#define DELIMITER "!? .,-\n"

/* Mostra a ajuda */
void show_help(char *q_andares) {
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


int main(int argc, char **argv) {

  int opcao, i = 0;
  char *q_andares = NULL, *capacidade = NULL, *arq_passageiro = NULL, *metodo = NULL, *arq_elevador = NULL;
  /* Variavel para o nome do arquivo dos passageiros */

  /* Chama a tela de ajuda */
  if (argc < 2) show_help(argv[0]);

  while((opcao = getopt(argc,argv,"hn:a:c:e:p:o:")) > 0){
    switch (opcao){
      case 'h':
        show_help(argv[0]);
        break;
      case 'a':
        q_andares = optarg;
      break;
      case 'c':
        capacidade = optarg;
      break;
      case 'e':
        arq_elevador = optarg;
      break;
      case 'p':
        arq_passageiros = optarg;
      break;
      case 'o':
        metodo = optarg;
      break;
    }
  }

  /*Abertura dos arquivos conforme o nome que o usuario pede*/
  //FILE *IN_passageiros;
  //FILE *IN_elevador;
  //IN_passageiros = fopen (arq_passageiros,"r");
  //IN_elevador = fopen (arq_elevador,"r");

  /* caso o arquivo não seja aberto */
  //if (IN_passageiros == NULL /*|| IN_elevador == NULL*/){
    //printf("Os arquivos não puderam ser abertos! Ou algum esta em falta.\n");
    //exit(1);
  //}

  /* Por cuidado vamos zerar o buffer */
  //fflush(stdout);

  /* Passa o metodo para lower case */
  for (i = 0; metodo[i]; i++) metodo[i] = tolower(metodo[i]);

  /* Caso o usuario escolha um dos metodos ou nenhum deles */
  if (strcmp(metodo, "fifo") == 0){
    printf("FIFO foi o escolhido\n");
    //estrategia_fifo(arq_passageiros);
  }
  else if (strcmp(metodo, "SJF") == 0){
    printf("SJF foi o escolhido\n");
  }
  else{
    printf("O metodo nao foi escolhido ou a opcao inserida é invalida!\n Tente usar -o FIFO ou -o SJF\n");
  }

return 0 ;
}
