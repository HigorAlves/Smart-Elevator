#include <stdio.h>
#include <stdlib.h>
/*lib do GETOPT */
#include <unistd.h>

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

  int opcao;
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


  return 0 ;
}
