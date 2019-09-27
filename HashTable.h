#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include "LinkedList.h"

typedef LinkedList* hashtable[buckets];

unsigned int hash(char* palavra) { //função hash 1

  int tam = strlen(palavra);
  unsigned int value = 0;

  for(int i = 0; i < tam; ++i)
      value = value * 33 + palavra[i];

  return value;
}

unsigned long int hash_2(char* palavra){//função hash2

  int tam = strlen(palavra);
  unsigned long int value;

  for(int i = 0; i < tam; ++i)
      value += palavra[i];

  return value;
}


void print(LinkedList *L) {
  Node *aux = L->Top;
  while(aux != NULL){
    printf("%s\n",aux->palavra);
    aux =aux->next;
  }

}


void insert(hashtable h,char *palavra) {
  unsigned int Hash1 = hash(palavra);
 
  if(h[Hash1%buckets] == NULL) {

    struct LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));

    h[Hash1%buckets] = L;
    prepend(L,palavra);

  }else {

    struct LinkedList* L = h[Hash1%buckets];

    prepend(L,palavra);

  }
}

int search(hashtable h, char *palavra) {
  int numero_busca = (hash(palavra)%buckets);
  
  if (h[numero_busca]!=NULL){  
    const struct LinkedList* L = h[numero_busca];
    const struct Node* aux = L->Top;
    while(aux!=NULL){
      if((strcmp(aux->palavra,palavra))== 0) {
        return 1;
      }
      aux =aux->next;
    }

  }
  return 0;
};



void ini(hashtable h) {
  unsigned int i;
  for(i = 0; i < buckets;i++) {
    h[i] = NULL;
  }
}


#endif