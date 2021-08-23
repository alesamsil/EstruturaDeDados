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
Fila remover(Fila f, char* nome, int *id){
    if(f!=NULL){
		Fila n=f->prox;
    	strcpy(nome, f->nome);
		(*id)=f->id;
		free(f);
    	return n;
	}
	else{
		printf("Lista vazia\n\n");
		return f;
	}
}

void imprimir(Fila f){
	Fila p;
	for(p=f;p!=NULL;p=p->prox){
		printf("Nome: %s\n", p->nome);
		printf("Idade: %d\n----------------------\n",p->id);
	}
}

Fila inicializar (Fila f){
    if(f!=NULL){
    	return f;
    }
	f=NULL;
    return f;
}

Fila destruir(Fila f){
    Fila t=f;
    while(f!=NULL){
    	t=f->prox;
    	free(f);
    	f=t;
    }
	return f;
}
