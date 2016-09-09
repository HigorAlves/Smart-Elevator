#include "funcoes.h"


int main(int argc, char **argv) {
  /* FUNÇÃO PARAR CORRER O TEMPO COM A VARIAVEL */
  _tempo tiempo;
  int tmili = 0;
  struct timeval inicio, final;
  iniciaTempo(&tiempo);
  gettimeofday(&inicio, NULL);
  /* Declaração das variaveis  que vamos usar durante todo o programa */
  int quantidade_passageiros = 10, opcao = 0, i =0;
  char *arquivo_elevador = NULL, *arquivo_passageiro = NULL, *estrategia = NULL;

  _passageiros *pass;
  _elevador elevador;
  /* FIM das declarações das variaveis */

  /* FUNÇÂO GETOPT */
  if (argc < 2) show_help(argv[0]);

  while((opcao = getopt(argc,argv,"hn:a:c:p:g:e:")) != -1){
    switch (opcao){
      case 'h':
        show_help(argv[0]);
        break;
      case 'a':
        elevador.quant_andares = atoi(optarg);
        break;
      case 'c':
        elevador.capacidade = atoi(optarg);
        break;
      case 'e':
        estrategia = optarg;
        break;
      case 'p':
        arquivo_passageiro = optarg;
        break;
      case 'g':
        quantidade_passageiros = atoi(optarg);
        break;
    }
  }
  /* FIM FUNÇAO GETOPT */

  /* Abertura dos arquivos que vamos usar */
  FILE *IN_passageiros = fopen(arquivo_passageiro, "w"); //Escrita
  FILE *OUT_fifo = fopen("OUT_FIFO.txt", "a"); //Leitura e escrita
  FILE *OUT_sjf = fopen("OUT_SJF.txt", "a"); //Escrita
  /* Vamos verificar se todos os arquivos foram abertos normalmente */
  if(IN_passageiros == NULL || OUT_fifo == NULL || OUT_sjf == NULL){
      printf("Erro na abertura do arquivo. O programa irá ser fechado\n");
      exit(1);
  }
  /* FIM ARQUIVOS */

  /* ALocamos dinamicamente dentro da variavel pass que é do tipo passageiro */
  pass = (_passageiros *) malloc(quantidade_passageiros * (sizeof(_passageiros)));
  /* Cria o arquivo do passageiro randomicamente dentro dos limites baseando-se na quantidade de passageiros.  */
  randomiza_passageiros(pass, IN_passageiros, quantidade_passageiros, elevador.quant_andares);

  /* Executa os dois metodos escolhidos pela equipe SJF e FIFO */
  for(i = 0; estrategia[i]; i++) estrategia[i] = tolower(estrategia[i]);
  if (strcmp(estrategia,"fifo")==0){
    fifo(pass, quantidade_passageiros, OUT_fifo, elevador);
    fclose(OUT_fifo); //Fechamos o arquivo pois não usaremos ele mais no processo.
  }else if (strcmp(estrategia,"sjf")==0){
    sjf(pass, quantidade_passageiros, OUT_sjf, elevador);
    fclose(OUT_sjf); //Fechamos o arquivo pois não usaremos ele mais no processo.
  }

  /* Fechamos todos os arquivos */
  fclose(IN_passageiros);
  free(pass);

  /* Gera os tempos e imprimi */
  finalizaTempo(&tiempo, &tiempo.tempoU,&tiempo.tempoS);
  printf("\nTempo total:%lf - Tempo Usuario:%lf - Tempo Sistema:%lf\n",tiempo.tempoU + tiempo.tempoS, tiempo.tempoU, tiempo.tempoS);
  gettimeofday(&final, NULL);
  tmili = (double) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
  printf("Tempo decorrido %d millesegundos.\n", tmili);
  return 0;
}
