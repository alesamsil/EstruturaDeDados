#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct fila{
    char nome[81];
    int id;
    struct fila *prox;
};

Fila inserir(Fila f, char *nome, int id){
	if (f == NULL){
		f=(Fila)malloc(sizeof(struct fila));
		strcpy(f->nome,nome); 
		f->id=id;
		f->prox=NULL;
		return f;
	}
	else{
		f->prox=inserir(f->prox,nome,id);
	}
	return f;
}
Fila remover(Fila f){
    if(f!=NULL){
    	Fila n=f->prox;
    	
    	free(f);
    	printf ("Elemento foi removido\n\n");
    	return n;
	}
	else{
		printf("Lista vazia\n\n");
		return f;
	}
}

void imprimir(Fila f){
    while (f!=NULL){
     	printf ("Nome: %s\n",f->nome);
        printf ("Idade: %d\n",f->id);
        printf ("-----------------\n");
        f=f->prox;
    }
}

Fila inicializar (Fila f){
    f=NULL;
    return f;
}

Fila destruir(Fila f){
    if(f==NULL)
    	return NULL;
	if(f->prox==NULL)
			free(f);
	else
		f->prox=destruir(f->prox);
	return f;
}
