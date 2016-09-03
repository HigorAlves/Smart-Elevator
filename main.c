#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*lib do GETOPT */
#include <unistd.h>
#include "funcoes.h"


/* Mostra a ajuda */
void show_help(char *q_andares) {
  fprintf(stderr, "\
    [uso] ./tp1 <opcoe> -o <metodo>\n\
    -h  Mostra a tela de ajuda e sai dela. \n\
    -a  Seta a quantidade de andares.\n\
    -c  Seta a capacidade do elevador.\n\
    -e  Definir um arquivo de ambiente para o elevador? \n\
    -p  Nome do arquivo dos passageiros.\n\
    -o  Use FIFO ou SJF como estrategia. \n");
  exit(-1) ;
}


int main(int argc, char **argv) {

  int opcao,i = 0;
  char *q_andares = NULL, *capacidade = NULL, *Passageiros = NULL, *metodo = NULL;
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
      case 'p':
        Passageiros = optarg;
      break;
      case 'o':
        metodo = optarg;
      break;
    }
  }

  FILE *IN;
  IN = fopen (Passageiros,"r");

  /* caso o arquivo não seja aberto */
  if (IN == NULL){
    printf("O arquivo não pode ser aberto!\n");
    exit(1);
  }

  /* Por cuidado vamos zerar o buffer */
  fflush(stdout);

  /* Passa o metodo para lower case */
  for (i = 0; metodo[i]; i++) metodo[i] = tolower(metodo[i]);

  /* Caso o usuario escolha um dos metodos ou nenhum deles */
  if (strcmp(metodo, "fifo") == 0){
    printf("FIFO foi o escolhido\n");
  }
  else if (strcmp(metodo, "SJF") == 0){
    printf("SJF foi o escolhido\n");
  }
  else{
    printf("O metodo nao foi escolhido ou a opcao inserida é invalida!\n Tente usar -o FIFO ou -o SJF\n");
  }

return 0 ;
}
