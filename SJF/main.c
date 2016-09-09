#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define DELIMITER "\n"

typedef struct pessoa{
  int onde_vai;
  int onde_ta;
}Pessoa;


int main(int argc, char const *argv[]) {
  /* variaveis */
  int n = 0,i=1, elev=1, to_aqui, ta, vai, tava;
  int aux;
  Pessoa *pass;
  char *f;

  FILE *IN_passageiro;
  IN_passageiro = fopen("passageiros.txt","r");

  while (fscanf(IN_passageiro,"%m[^"DELIMITER"]%*["DELIMITER"]",&f) != EOF){
    n++;
  }

  pass = (Pessoa *) malloc(n * sizeof(Pessoa));
  rewind(IN_passageiro);

  while (fscanf(IN_passageiro,"%d",&ta) && fscanf(IN_passageiro,"%d",&vai) != EOF){
    pass[i].onde_ta = ta;
    pass[i].onde_vai = vai;
    i++;
  }

  // PAREI DE PASSAR PRO PRINCIPAL AQUI
  int capacidade = 10, lotou =0, mais_perto = 10000000,j,jepslon = 0,flag,ajuda=1;
  i = 1;

  while (i <= n) {
    //Lotou entao entrega

    //primeiro olho se mudou de andar
    if (pass[i].onde_ta != elev){
      for (j = 1; j < i; j++){
        if (mais_perto > pass[j].onde_vai){
          if (pass[j].onde_vai != 1000000){
            mais_perto = pass[j].onde_vai;
            pass[j].onde_vai = 1000000;
            jepslon = jepslon + abs(mais_perto - elev);
            elev = mais_perto;
            for (j = 1; j < i; j++){
              if (mais_perto < pass[j].onde_vai && pass[j - 1].onde_ta == pass[j].onde_ta){
                if (pass[j].onde_vai != 1000000){
                  mais_perto = pass[j].onde_vai;
                  jepslon = jepslon + abs(mais_perto - elev);
                  pass[j].onde_vai = 1000000;
                  elev = mais_perto;
                  flag = elev;
                  ajuda = flag;
                }
              }else if(mais_perto < pass[j].onde_vai && pass[j - 1].onde_ta != pass[j].onde_ta){
                if (pass[j].onde_ta == 0 && pass[j].onde_vai){
                  printf("OSIAD");
                }
              }
            }
          }
        }
      }
    }
    i ++;
  }
  printf("Ajuda: %i\n", ajuda);
  printf("Flag: %i\n", flag);
  printf("jepslon:%i\n",jepslon);
  return 0;
}
