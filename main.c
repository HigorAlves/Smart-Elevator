#include "funcoes.h"

int main(int argc, char **argv) {

  char *arq_passageiro = NULL, *arq_elevador = NULL, *estrategia = NULL;
  int opcao, quant_andares = 0, capacidade = 0, i = 0, lotado = 0, tava = 1, jepslon_porta = 0, jepslon_andar =0, elevador_ta = 1;

  filinha *pointer;
  Pessoa eu;
  pointer = (filinha*) malloc(sizeof(filinha));
  _elevador elevador;

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
  if (arq_elevador != NULL){
    FILE *IN_elevador;
    IN_elevador = fopen (arq_elevador,"r");

    /* Se não for possivel abrir o arquivo do elevador */
    if (IN_passageiro == NULL){
      printf("Não foi possivel abrir o arquivo do elevador!");
      exit(1);
    }else{
      /* Pega a quantidade de andares e a capacidade do elevador */
      while ((fscanf (IN_elevador, "%d", &elevador.andares)) && (fscanf (IN_elevador, "%d", &elevador.capacidade)) != EOF);
    }
  }

  /* Passa a entrada do metodo para lowercase */
   for(i = 0; estrategia[i]; i++) estrategia[i] = tolower(estrategia[i]);

   /* Pega os valores do arquivo do passageeiro */
   while (fscanf(IN_passageiro,"%d",&eu.onde_ta) && fscanf(IN_passageiro,"%d",&eu.onde_vai) != EOF){
     if (strcmp (estrategia, "fifo") == 0){
       /* Se o passageiro estiver respeitando o ambiente do elevador */
       VerificaAmbiente(eu.onde_ta, eu.onde_vai, elevador.andares);
       /* Se o elevador estiver lotado vamos entregar quem esta la dentro. */
       lotado = lotado + 1;
       if (lotado > elevador.capacidade){
         entrega(pointer, &jepslon_andar, &jepslon_porta, &elevador_ta, &eu);
         printf("entrei 1\n");
         lotado = 0;

       }else
       /* Verifica se a proxima entrada vai mudar de andar, caso ela mude vamos entregar os que ja entraram. */
       if (mudou_andar(eu.onde_ta, &tava) == 1){
         entrega(pointer, &jepslon_andar, &jepslon_porta, &elevador_ta, &eu);
         printf("entrei 2\n");
         lotado = 0;
       }
       colocar(pointer,eu);
     }else if(strcmp (estrategia, "sjf") == 0){
       //faz a funçao sjf
     }else{
       printf("Função escolhida não consta no programa!");
     }
   }
   //remover (pointer,&eu); //cada remover retira um da pilha
   printf("PORTA:%i JEP:%i\n", jepslon_porta - 1, jepslon_andar);
   mostrar(pointer);
return 0;
}
