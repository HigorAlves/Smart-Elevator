#include "funcoes.h"

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

  char *arq_passageiro = NULL, *arq_elevador = NULL, *estrategia = NULL;
  int opcao, quant_andares = 0, capacidade = 0, i = 0;

  filinha *pointer;
  Pessoa eu;
  pointer = (filinha*) malloc(sizeof(filinha));
  //_elevador elevador;

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
        arq_passageiro = optarg;
        break;
      case 'o':
        estrategia = optarg;
        break;
    }
  }

  /* Abertura do arquivo dos passageiros */
  FILE *IN_passageiro;
  IN_passageiro = fopen(arq_passageiro,"r");

  /* Verifica se o arquivo foi aberto */
  if (IN_passageiro == NULL){
    printf("Não foi possivel abrir o arquivo do passageiro.");
    exit(1);
  }

  /* Verificar se vai abrir com arquivo do elevador */
  /*if (arq_elevador != NULL){
    FILE *IN_elevador;
    IN_elevador = fopen (arq_elevador,"r");

    /* Se não for possivel abrir o arquivo do elevador */
    /*if (IN_passageiro == NULL){
      printf("Não foi possivel abrir o arquivo do elevador!");
      exit(1);
    }else{
      /* Pega a quantidade de andares e a capacidade do elevador */
      /*while ((fscanf (IN_elevador, "%d", &elevador.andares)) && (fscanf (IN_elevador, "%d", &elevador.capacidade)) != EOF);
    }
  }*/

  /* Passa a entrada do metodo para lowercase */
   for(i = 0; estrategia[i]; i++) estrategia[i] = tolower(estrategia[i]);

/* Pega os valores do arquivo do passageeiro */
   while (fscanf(IN_passageiro,"%d",&eu.onde_ta) && fscanf(IN_passageiro,"%d",&eu.onde_vai)!=EOF){
     if (strcmp (estrategia, "fifo") == 0){
       colocar(pointer,eu);
     }else if(strcmp (estrategia, "sjf") == 0){
       //faz a funçao sjf
     }else{
       printf("Função escolhida não consta no programa!");
     }
   }
   mostrar(pointer);
return 0;
}
