#include "funcoes.h"


int main(int argc, char **argv) {
  /* FUNÇÃO PARAR CORRER O TEMPO COM A VARIAVEL */
  _tempo tiempo;
  iniciaTempo(&tiempo);

  /* Declaração das variaveis  que vamos usar durante todo o programa */
  int quantidade_passageiros = 10, opcao = 0;
  char *arquivo_elevador = NULL, *arquivo_passageiro = NULL;

  _passageiros *pass;
  _elevador elevador;
  /* FIM das declarações das variaveis */

  /* FUNÇÂO GETOPT */
  if (argc < 2) show_help(argv[0]);

  while((opcao = getopt(argc,argv,"hn:a:c:e:p:g:")) != -1){
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
        arquivo_elevador = optarg;
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
  FILE *IN_elevador = fopen("elevador.txt","r"); //Abrinco somente para leitura
  FILE *IN_passageiros = fopen("passageiros.txt", "w"); //Escrita
  FILE *OUT_fifo = fopen("OUT_FIFO.txt", "a"); //Leitura e escrita
  FILE *OUT_sjf = fopen("OUT_SJF.txt", "a"); //Escrita
  /* Vamos verificar se todos os arquivos foram abertos normalmente */
  if(IN_elevador == NULL || IN_passageiros == NULL || OUT_fifo == NULL || OUT_sjf == NULL){
      printf("Erro na abertura do arquivo. O programa irá ser fechado");
      exit(1);
  }
  /* FIM ARQUIVOS */

  /* ALocamos dinamicamente dentro da variavel pass que é do tipo passageiro */
  pass = (_passageiros *) malloc(quantidade_passageiros * (sizeof(_passageiros)));
  /* Cria o arquivo do passageiro randomicamente dentro dos limites baseando-se na quantidade de passageiros.  */
  randomiza_passageiros(pass, IN_passageiros, quantidade_passageiros, elevador.quant_andares);

  /* Executa os dois metodos escolhidos pela equipe SJF e FIFO */

  fifo(pass, quantidade_passageiros, OUT_fifo, elevador);
  fclose(OUT_fifo); //Fechamos o arquivo pois não usaremos ele mais no processo.

  sjf(pass, quantidade_passageiros, OUT_sjf, elevador);
  fclose(OUT_sjf); //Fechamos o arquivo pois não usaremos ele mais no processo.

  /* Fechamos todos os arquivos */
  fclose(IN_elevador);
  fclose(IN_passageiros);
  free(pass);
  finalizaTempo(&tiempo, &tiempo.tempoU,&tiempo.tempoS);
  printf("\nTempo total:%lf - Tempo Usuario:%lf - Tempo Sistema:%lf\n",tiempo.tempoU + tiempo.tempoS, tiempo.tempoU, tiempo.tempoS);
  return 0;
}
