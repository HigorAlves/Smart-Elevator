#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*lib do GETOPT */
#include <unistd.h>
#include "funcoes.h"


#define DELIMITER ",-\n"

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
  char *word = NULL, *arq_elevador = NULL, *arq_passageiros = NULL, *estrategia = NULL;
  int i = 0, opcao = 0, quant_andares = 0, capacidade = 0;
  long size = 0;

  if (argc < 2) show_help(argv[0]);

  while((opcao = getopt(argc,argv,"hn:a:c:e:p:o:")) != -1){
    switch (opcao){
      case 'h':
        show_help(argv[0]);
        break;
      case 'a':
        quant_andares = atoll(optarg);
        break;
      case 'c':
        capacidade = atoll(optarg);
        break;
      case 'e':
        arq_elevador = optarg;
        break;
      case 'p':
        arq_passageiros = optarg;
        break;
      case 'o':
        estrategia = optarg;
        break;
    }
  }

  /*Abertura dos arquivos conforme o nome que o usuario pede*/
  FILE *IN_passageiros;
  FILE *IN_elevador;
  IN_passageiros = fopen (arq_passageiros,"r");
  IN_elevador = fopen (arq_elevador,"r");

  /* caso o arquivo não seja aberto */
  if (IN_passageiros == NULL || IN_elevador == NULL){
    printf("Os arquivos não puderam ser abertos! Ou algum esta em falta.\n");
    exit(1);
  }

  /* Função para pegar o tamanho do arquivo e voltar ao inicio dele */
  fseek(IN_passageiros, 0L, SEEK_END);
  size = ftell(IN_passageiros);
  rewind(IN_passageiros);

  /* Separa a string e manda para a função escolhida */
   while ((fscanf (IN_passageiros, "%m[^"DELIMITER"]%*["DELIMITER"]", &word)) != EOF){
     i++;
     estrategia_fifo(word, i, size);
   }

return 0 ;
}
