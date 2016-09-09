#include "funcoes.h"

/* Função para chamar a tela de ajuda do opt */
void show_help(char *arquivo_elevador) {
  fprintf(stderr, "\
    [uso] ./tp1 <opcoe> -o <metodo>\n\
    -h  Mostra a tela de ajuda e sai dela. \n\
    -a  Seta a quantidade de andares.\n\
    -c  Seta a capacidade do elevador.\n\
    -e  Nome do arquivo do elevador. \n\
    -p  Nome do arquivo dos passageiros.\n\
    -g  Quantidade de passageiros para gerar.\n");
  exit(-1) ;
}

/* Gerar todos os passageiros baseado na quantidade que o usuario inseriu para  popular o arquivo */
void randomiza_passageiros(_passageiros *passageiro, FILE *IN_passageiros, int quantidade_passageiros, int qtd_andar) {
  int i;
  srand((unsigned)time(NULL));
  fprintf(IN_passageiros,"%i\n", quantidade_passageiros);

  //Imprimi andar atual e o proximo
  for (i=0; i<quantidade_passageiros; i++){
    passageiro[i].onde_ta = rand()%qtd_andar+1;
    passageiro[i].onde_vai = rand()%qtd_andar+1;
    if (passageiro[i].onde_ta == passageiro[i].onde_vai){
      passageiro[i].onde_vai = rand()%qtd_andar+1;
    }
    fprintf(IN_passageiros," \n%i %i\n", passageiro[i].onde_ta, passageiro[i].onde_vai);
  }
}

/* Função de um codigo de Heap adptado, heap escolhido pois assim podemos ordenar de maneira rapida arquivos muito grandes */
void refaz(int esq, int dir, _passageiros *a) {
  /* Variaveis */
  int i = esq;
  int j;
  _passageiros x;
  j = i*2;
  x = a[i];

  while (j <= dir) {
    if (j < dir) {
      if (a[j].onde_ta < a[j+1].onde_ta){
        j++;
      }
    }
    if (x.onde_ta >= a[j].onde_ta){
      break;
    }
    a[i] = a[j];
    i = j;
    j = i*2;
  }
  a[i] = x;
}

void constroi(_passageiros *a, int *n) {
  /* VARIAVEIS */
  int esq = *n/2 + 1;
  while (esq > 0) {
    esq--;
    refaz(esq,*n, a);
  }
}

void Heapsort(_passageiros *a, int *n) {
  int esq, dir;
  _passageiros x;
  constroi(a, n);
  esq = 0;
  dir = *n - 1;
  while (dir > 0) {
    x = a[0];
    a[0] = a[dir];
    a[dir] = x;
    dir--;
    refaz(esq, dir, a);
  }
}
/* FIM DO HEAP */

void sjf(_passageiros *passageiros, int quantidade_passageiros, FILE *OUT_SJF, _elevador elevador){
  /* Declaração das variaveis */
  int j, i, temp_total = 0, temp_esp = 0, temp_perc = 0;
  /* FIM VARIAVEIS */

  //vamos usar o HEAP para ordenar todo mundo de acordo com os andares :D
  Heapsort(passageiros, &quantidade_passageiros);
  for (j=0; j < quantidade_passageiros; j++) {
    passageiros[j].tempo_total = 0;
    passageiros[j].tempo_espera = 0;
    passageiros[j].tempo_percurso = 0;
  }
  //Tempo dos passageiros
  for (i=0; i < quantidade_passageiros; i++) {
    if (passageiros[i].onde_ta == 1) {
      passageiros[i].tempo_espera = 0;
    }else if (passageiros[i].onde_vai < passageiros[i].onde_ta) {
      //Calcula o tempo de espera do passajeiro
      passageiros[i].tempo_espera = abs(passageiros[i].onde_ta - passageiros[i-1].onde_vai) + passageiros[i-1].tempo_total;
    }else{
      //calcula tempo de espera do passageiro
      passageiros[i].tempo_espera = abs(passageiros[i].onde_ta - passageiros[i].onde_vai);
    }
    //Calcular os tempos do passageiro
    passageiros[i].tempo_percurso = abs(passageiros[i].onde_vai - passageiros[i].onde_ta);
    passageiros[i].tempo_total = passageiros[i].tempo_espera + passageiros[i].tempo_percurso + 2;
    temp_total += passageiros[i].tempo_total;
    temp_esp += passageiros[i].tempo_espera;
    temp_perc += passageiros[i].tempo_percurso;
  }
  //Imprimi no arquivo, o float enfrente cada divisão é para tratar erro e ter casas decimais
  fprintf(OUT_SJF,"Qtd Andar: %i \t Qtd Passageiros: %i \tMedia total: %.2f \tmedia espera: %.2f \tMedia_percurso: %.2f \tTotal perc. elevador: %i \tPortas elev: %i\n\n"
          ,elevador.quant_andares, quantidade_passageiros, (float)temp_total/quantidade_passageiros, (float)temp_esp/quantidade_passageiros, (float)temp_perc/quantidade_passageiros, temp_perc, quantidade_passageiros * 2);
}

/* ESCALONAMENTO POR FIRST IN FIRST OUT */
void fifo(_passageiros *passageiros, int quantidade_passageiros, FILE *OUT_FIFO, _elevador elevador){
  //Tempo de entrada e saida
  int i, temp_total = 0, temp_esp = 0, temp_perc = 0;
  for (i=0; i<quantidade_passageiros; i++) {
    //Passageiro esta no 1 Andar?
    if (i == 0) {
      //Vamos calcular o tempo de espera
      passageiros[i].tempo_espera = passageiros[i].onde_ta;
    }
    else {
      //Vamos calcular o tempo de espera
      passageiros[i].tempo_espera = abs(passageiros[i-1].onde_vai - passageiros[i].onde_ta + passageiros[i-1].tempo_total);
    }
    //Calcula o tempo de percurso de cada passageiro
    passageiros[i].tempo_percurso = abs(passageiros[i].onde_vai - passageiros[i].onde_ta);
    //Total de cada passageiro
    passageiros[i].tempo_total = passageiros[i].tempo_espera + passageiros[i].tempo_percurso + 2;
    //Soma o total dos tempos
    temp_total += passageiros[i].tempo_total;
    //soma de todos os tempos de espera
    temp_esp += passageiros[i].tempo_espera;
    //tempo total de percuso do elevador
    temp_perc += passageiros[i].tempo_percurso;
  }
  //Imprimi no arquivo, o float enfrente cada divisão é para tratar erro e ter casas decimais
  fprintf(OUT_FIFO,"\n\nQuantidade de Andares:%i \t Quantidade de Passageiros: %i \tMedia total: %.2f \tMedia espera: %.2f \tMedia percurso: %.2f \tTotal Percurso elevador: %i \tTotal portas elevador: %i\n\n"
          ,elevador.quant_andares, quantidade_passageiros, (float)temp_total/quantidade_passageiros, (float)temp_esp/quantidade_passageiros, (float)temp_perc/quantidade_passageiros, temp_perc, quantidade_passageiros * 2);
}

/* FIM ESCALONAMENTO PELO METODO Shortest job first */

void zera_tempo(double *tempoUser, double *tempoSis){
  *tempoUser = 0;
  *tempoSis = 0;
}

/* FUNÇAO GETRUSAGE DO SACHETO */
void iniciaTempo(_tempo *t){
	//Inicia a contagem de tempo do usuario e sistema.
	getrusage(RUSAGE_SELF, &(t->resources));
	t->inicioU = t->resources.ru_utime;
	t->inicioS = t->resources.ru_stime;
}

void finalizaTempo(_tempo *t,double *tempoU, double *tempoS){
	// Finaliza a contagem de tempo do usuario e sistema.
	getrusage(RUSAGE_SELF, &(t->resources));
	t->fimU = t->resources.ru_utime;
	t->fimS = t->resources.ru_stime;

	// Calcula o tempo do usuario.
	*tempoU = (double) (t->fimU.tv_sec - t->inicioU.tv_sec) + 1.e-6 * (double) (t->fimU.tv_usec - t->inicioU.tv_usec);

	// Calcula o tempo do sistema.
	*tempoS = (double) (t->fimS.tv_sec - t->inicioS.tv_sec) + 1.e-6 * (double) (t->fimS.tv_usec - t->inicioS.tv_usec);
}
