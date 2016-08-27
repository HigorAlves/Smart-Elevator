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
    -h         mostra essa tela e sai.\n\
    -a ANDARES    seta a quantidade de andares.\n\
    -p ARQ_PASSAGEIROS nome do arquivo dos passageiros\n\
    -c CAPACIDADE   seta a capacidade do elevador.\n\
    -o METODO use FIFO ou SJF como estrategia\n");
  exit(-1) ;
}


int main(int argc, char **argv) {

  int opcao,i = 0;
  char *q_andares = NULL, *capacidade = NULL, *Passageiros = NULL, *metodo = NULL;
  /* Variavel para o nome do arquivo dos passageiros */

  /* Chama a tela de ajuda */
  if (argc < 2) show_help(argv[0]);

  while((opcao = getopt(argc,argv,"hn:a:c:p:o:")) > 0){
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

  /* Passa o metodo para lower case */
  for (i = 0; metodo[i]; i++) metodo[i] = tolower(metodo[i]);

  /* Caso o usuario escolha um dos metodos ou nenhum deles */
  if (strcmp(metodo,"fifo") == 0){
    printf("FIFO foi o escolhido\n");
  }
  else if (strcmp(metodo == "SJF") == 0{
    printf("SJF foi o escolhido\n");
  }
  else{
    printf("O metodo nao foi escolhido ou a opcao inserida é invalida!\n Tente usar -o FIFO ou -o SJF\n");
  }

return 0 ;
}
