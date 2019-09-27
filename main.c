#define buckets 50000

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "HashTable.h"


int main(void) {
  int n_erros = 0;
  int total = 0;
  double tempo;
  clock_t t0, tf; 

    hashtable h;
    ini(h);
    LinkedList erros; 
    FILE *dicionario = fopen("dicionario.txt","r");
    FILE *texto = fopen("texto.txt","r");
    FILE *resposta = fopen("resposta.txt","w");

    char word[50];

    while (!feof(dicionario)){
      fscanf(dicionario,"%s",word);
      insert(h,word);
      total++;
    } 
    
    t0 = clock();//inicio da comparação

    while (!feof(texto)){
      fscanf(texto,"%s",word);

      if(!search(h,word)) {
        prepend(&erros,word);
      }
    }

    tf = clock();//fim da comparação
    tempo = ( (double) (tf - t0) ) / (CLOCKS_PER_SEC/1000);

    Node* aux = erros.Top;
    while(aux != NULL){

      aux = aux->next;
      n_erros++;
    }


    fprintf(resposta,"Número total de palavras do texto: %d\n",total);
    fprintf(resposta,"Tempo total da verificação: %lf ms\n",tempo);
    fprintf(resposta,"Número de palavras que falharam no spell check: %d\n",n_erros);
    fprintf(resposta,"Lista de palavras que falharam no spell check:\n");
    fprintf(resposta,"Num. Ocorrencia - Palavra\n");


    n_erros = 1;
    aux = erros.Top;
    while(aux != NULL){
      fprintf(resposta,"%d - %s\n",n_erros,aux->palavra);
      aux = aux->next;
      n_erros++;
    }

    return 0;
}
