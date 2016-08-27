#include <stdio.h>
#include <stdlib.h>
/*lib do GETOPT */
#include <unistd.h>

/* Mostra a ajuda */
void show_help(char *Passageiros) {
  fprintf(stderr, "\
    [uso] ./tp1 <opcoes>\n\
    -sh         mostra essa tela e sai.\n\
    -a ANDARES    seta a quantidade de andares.\n\
    -c CAPACIDADE   seta a capacidade do elevador.\n\
    -p NOME_ARQUIVO nome para o arquivo dos passageiros\n");
  exit(-1) ;
}

int main(int argc, char **argv) {

  int *q_andares = NULL, *capacidade = NULL;
  /* Variavel para o nome do arquivo dos passageiros */
  char *Passageiros = NULL;

  if (argc < 2) show_help(argv[0]);

  return 0 ;
}
