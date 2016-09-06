#include "lista.h"

int main(int argc, char const *argv[]) {
  FILE *arq = fopen("passageiros.txt","r");

  filinha *pointer;
  Pessoa eu;
  pointer = (filinha*) malloc(sizeof(filinha));

while (fscanf(arq,"%d",&eu.onde_ta) && fscanf(arq,"%d",&eu.onde_vai)!=EOF) {
  //printf("%d %d\n",eu.onde_ta,eu.onde_vai);
  colocar(pointer,eu);
}
mostrar(pointer);
  return 0;
}
