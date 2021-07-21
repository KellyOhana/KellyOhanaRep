#include <stdio.h>
#include <stdlib.h>

typedef struct Contadoref
{
  int cont;
  void *endereco;
  struct Contadoref *prox;
}Contadoref;


void *malloc2(int size); // aloca e retorna o endereço da area criada


void dump(); // imprime situação da memoria


Contadoref* RemoveElemento(Contadoref* lista, void* endereco);

void incrementacontador(void *end, int n);


void atrib2(void **end1, void *end2);//end1 aponta end2
