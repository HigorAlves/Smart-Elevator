#include <stdio.h>
#include <stdlib.h>
/*lib do GETOPT */
#include <unistd.h>

/* Mostra a ajuda */
void show_help(char *Passageiros) {
  fprintf(stderr, "\
    [uso] ./tp1 <opcoes>\n\
    -h         mostra essa tela e sai.\n\
    -a ANDARES    seta a quantidade de andares.\n\
    -c CAPACIDADE   seta a capacidade do elevador.\n\
    -p NOME_ARQUIVO nome para o arquivo dos passageiros\n");
  exit(-1) ;
}

int main(int argc, char **argv) {

  int opt;
  char *q_andares = NULL, *capacidade = NULL, *Passageiros = NULL;
  /* Variavel para o nome do arquivo dos passageiros */

  /* Chama a tela de ajuda */
  if (argc < 2) show_help(argv[0]);

  while((opt = getopt(argc,argv,"hn:a:c:p")) > 0){
    switch (opt){
      case 'h':
        show_help(argv[0]);
        break;
      case 'a':
        q_andares = optarg;
      break;
      case 'c':

      break;
      case 'p':

      break;
    }
  }

  printf("Andares: %c\n", *q_andares);

  return 0 ;
}
