#include <stdio.h>
#include <stdlib.h>

typedef struct Contadoref
{
  int cont;
  void *endereco;
  struct Contadoref *prox;
}Contadoref;

Contadoref *lista = NULL;

void *malloc2(int size) // aloca e retorna o endereço da area criada
{
  Contadoref *aux;
  aux = malloc(sizeof(Contadoref));
  aux->endereco = malloc(size);
  aux->cont = 1;
  aux->prox = NULL;
  if(lista!=NULL)
  {
    aux->prox = lista;
  }
  lista = aux;
  return lista->endereco;
}

void dump() // imprime situação da memoria
{
  Contadoref *aux = lista;
  if(lista == NULL)
  {
    printf("Lista vazia");
  }
  while(aux != NULL)
  {
    printf("Endereco: %p\t Contador: %d\n",aux->endereco, aux->cont);
    aux = aux->prox;
  }
  printf("\n");
}


Contadoref* RemoveElemento(Contadoref* lista, void* endereco)
{
  Contadoref* aux;
  if(lista==NULL)
  {
    return lista;
  }
  else if(lista->endereco != endereco)
  {
    lista->prox = RemoveElemento(lista->prox,endereco);
    return lista;
  }
  else
  {
    aux = lista;
    lista = lista->prox;
    free(aux);
    lista = RemoveElemento(lista,endereco);
    return lista;
  }
}

void incrementacontador(void *end,int n)
{
  Contadoref *aux = lista;
  while(aux != NULL)
  {
    if(aux->endereco == end)
    {
      aux->cont = aux->cont + n;
      if(aux->cont == 0)
      {
        printf("Endereco: %p\t Contador: %d\n",aux->endereco, aux->cont);
        lista=RemoveElemento(lista,aux->endereco);
        break;
      }
    }
    aux = aux->prox;
  }
}

void atrib2(void **end1, void *end2)//end1 aponta end2
{
  if((*end1)!= NULL)
  {
    incrementacontador((*end1), -1);
    if(end2!=NULL)
    {
      incrementacontador(end2, 1);
    }
    (*end1) = end2;
  }

}
