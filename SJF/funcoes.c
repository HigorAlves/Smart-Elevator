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
        if (passageiro[i].onde_ta == passageiro[i].onde_vai) passageiro[i].onde_vai = rand()%qtd_andar+1;
          fprintf(IN_passageiros," \n%i %i\n", passageiro[i].onde_ta, passageiro[i].onde_vai);
    }
}

/* ESCALONAMENTO POR FIRST IN FIRST OUT */
void fifo(_passageiros *passageiros, int quantidade_passageiros, FILE *OUT_FIFO, _elevador elevador){
    //Tempo de entrada e saida
    int entrada_saida = 2, i;
    int cont_temp_total = 0, cont_temp_esp = 0, cont_temp_perc = 0;
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

        //calcula o tempo total de cada passageiro
        passageiros[i].tempo_total = passageiros[i].tempo_espera + passageiros[i].tempo_percurso + entrada_saida;

        //soma de todos os tempos totais
        cont_temp_total += passageiros[i].tempo_total;

        //soma de todos os tempos de espera
        cont_temp_esp += passageiros[i].tempo_espera;

        //tempo total de percuso do elevador
        cont_temp_perc += passageiros[i].tempo_percurso;


    }

    //imprime as medias e outras informacoes no arquivo fifo_arq
    fprintf(OUT_FIFO,"\n\nQtd Andar: %i \t Qtd Passageiros: %i \tMedia total: %.2f \tmedia espera: %.2f \tMedia_percurso: %.2f \tTotal perc. elevador: %i \tPortas elev: %i\n\n", elevador.quant_andares, quantidade_passageiros, (float)cont_temp_total/quantidade_passageiros, (float)cont_temp_esp/quantidade_passageiros, (float)cont_temp_perc/quantidade_passageiros, cont_temp_perc, quantidade_passageiros * 2);
}

/* ESCALONAMENTO PELO METODO Shortest job first */

void refazer(int esq, int dir, _passageiros *a) {
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
        if (x.onde_ta >= a[j].onde_ta) break;
        a[i] = a[j];
        i = j;
        j = i*2;
    }
    a[i] = x;
}


void construir(_passageiros *a, int *n) {
    int esq = *n/2 + 1;
    while (esq > 0) {
        esq--;
        refazer(esq,*n, a);
    }
}


void Heapsort(_passageiros *a, int *n) {
    int esq, dir;
    _passageiros x;
    construir(a, n);   /*constroi o heap*/
    esq = 0;
    dir = *n - 1;
    while (dir > 0) { /*ordena o vetor*/
        x = a[0];
        a[0] = a[dir];
        a[dir] = x;
        dir--;
        refazer(esq, dir, a);
    }
}


void sjf(_passageiros *passageiros, int quantidade_passageiros, FILE *OUT_SJF, _elevador elevador){

    //tempo de entrada e saida do passageiro no elevador
    int j, i;
    int entrada_saida = 2;
    int cont_temp_total = 0, cont_temp_esp = 0, cont_temp_perc = 0;

    //organiza os passageiros de acordo com os andares
    Heapsort(passageiros, &quantidade_passageiros);

    //zera os tempos dos passageiros
    for (j=0; j < quantidade_passageiros; j++) {
        passageiros[j].tempo_total = 0;
        passageiros[j].tempo_espera = 0;
        passageiros[j].tempo_percurso = 0;
    }

    //calcula os tempos dos passageiros
    for (i=0; i < quantidade_passageiros; i++) {

        if (passageiros[i].onde_ta == 1) {

            //atribui 0 ao tempo de espera do primeiro passageiro situado no andar de origem do elevador
            passageiros[i].tempo_espera = 0;
        }
        else if (passageiros[i].onde_vai < passageiros[i].onde_ta) {

            //calcula tempo de espera do passageiro cujo andar atual > proximo andar
            passageiros[i].tempo_espera = abs(passageiros[i].onde_ta - passageiros[i-1].onde_vai) + passageiros[i-1].tempo_total;
        }
        else{

            //calcula tempo de espera do passageiro cujo andar atual < proximo andar
            passageiros[i].tempo_espera = abs(passageiros[i].onde_ta - passageiros[i].onde_vai);
        }

        //calcula tempo de percurso de cada passageiro
        passageiros[i].tempo_percurso = abs(passageiros[i].onde_vai - passageiros[i].onde_ta);

        //calcula tempo total de cada passageiro
        passageiros[i].tempo_total = passageiros[i].tempo_espera + passageiros[i].tempo_percurso + entrada_saida;

        //soma de todos os tempos totais
        cont_temp_total += passageiros[i].tempo_total;

        //soma de todos os tempos de espera
        cont_temp_esp += passageiros[i].tempo_espera;

        //tempo total de percuso do elevador
        cont_temp_perc += passageiros[i].tempo_percurso;

    }

    //imprime as medias e outras informacoes no arquivo sjf_arq
    fprintf(OUT_SJF,"Qtd Andar: %i \t Qtd Passageiros: %i \tMedia total: %.2f \tmedia espera: %.2f \tMedia_percurso: %.2f \tTotal perc. elevador: %i \tPortas elev: %i\n\n", elevador.quant_andares, quantidade_passageiros, (float)cont_temp_total/quantidade_passageiros, (float)cont_temp_esp/quantidade_passageiros, (float)cont_temp_perc/quantidade_passageiros, cont_temp_perc, quantidade_passageiros * 2);
}
