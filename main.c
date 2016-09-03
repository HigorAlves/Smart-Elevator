#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*lib do GETOPT */
#include <unistd.h>
#include "funcoes.h"


#define DELIMITER ",-\n"

/* Mostra a ajuda */
void show_help(char *quant_andares) {
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
  long size_passageiro = 0;

  /* Funçao do GetOpt */
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
  IN_passageiros = fopen (arq_passageiros,"r");

  /* caso o arquivo não seja aberto */
  if (IN_passageiros == NULL){
    printf("Os arquivos não puderam ser abertos! Ou algum esta em falta.\n");
    exit(1);
  }

  /* Se a entrada for com o arquivo */
  if (arq_elevador != NULL){
    char *pch = NULL;
    /* Abrindo arquivo do elevador */
    FILE *IN_elevador;
    IN_elevador = fopen (arq_elevador,"r");

    printf("Esta usando o arquivo do elevador para configurar o ambiente.\n");
    /* Pega a primeira quantos andares tem o predio */
    fscanf (IN_elevador, "%m[^"DELIMITER"]%*["DELIMITER"]", &word);
    quant_andares = atoi (word);
    rewind(IN_elevador);

    /* Pega qual a capacidade de passageiros do elevador*/
    while ((fscanf (IN_elevador, "%m[^"DELIMITER"]%*["DELIMITER"]", &word)) != EOF){
      pch = strtok (word," ,.-");
      while (pch != NULL){
        capacidade = atoi (pch);
        pch = strtok (NULL, " ,.-");
      }
    }
  }

  /* Função para pegar o tamanho do arquivo e voltar ao inicio dele */
  fseek(IN_passageiros, 0L, SEEK_END);
  size_passageiro = ftell(IN_passageiros);
  rewind(IN_passageiros);

  /* Passa a estrategia para minusculo*/
  for(i = 0; estrategia[i]; i++) estrategia[i] = tolower(estrategia[i]);

  /* Separa a string e manda para a função escolhida */
   while ((fscanf (IN_passageiros, "%m[^"DELIMITER"]%*["DELIMITER"]", &word)) != EOF){
     i++;
     if (strcmp(estrategia, "fifo") == 0){
       estrategia_fifo(word, i, size_passageiro, capacidade, quant_andares);
     }else if (strcmp(estrategia, "sjf") == 0){

     }else{
       printf("Nenhum metodo selecionado!");
     }
   }

return 0 ;
}
