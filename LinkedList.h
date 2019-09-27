#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct Node{
	
	char *palavra;
	struct Node *next;
	
}Node;

typedef struct LinkedList{

  Node *Top;

}LinkedList;


void prepend(LinkedList *list,char *entrada) {
    
    Node *novo; 
    int tamanho;   
    novo = (Node*)malloc(sizeof(Node));

  
    tamanho = strlen(entrada);
    novo->palavra = (char*)malloc(sizeof(char)*tamanho+1);
    strcpy(novo->palavra,entrada);

    if(list->Top == NULL) {

        novo->next = NULL;
        list->Top = novo;
        
    }else{
        novo->next = list->Top;
        list->Top = novo;
    }

}


#endif