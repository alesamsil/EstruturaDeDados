#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arv_avl.h"
struct arvore{
	int i;
	void *info;
	struct arvore *esq;
	struct arvore *dir;	
};
Arvore *a=NULL;

Arvore iniciar(){
	struct arvore *a=(struct arvore*)malloc(sizeof(struct arvore));
	a->i=0;
	a->info=NULL;
	a->esq=NULL;
	a->dir=NULL;
	return a;
}
Arvore inserir(Arvore a, void *in, int id){
	if(a->info==NULL){
		printf("Aqui: arvore null\n");
		Arvore no=(struct arvore*)malloc(sizeof(struct arvore));
		no->i=id;
		no->info=in;
		no->esq=NULL;
		no->dir=NULL;
		return no;
	}
	else{
		if (id<=a->i){
			printf("Esq: --------------\n");
			a->esq=inserir(a->esq,in,id);
		}
		else{
			printf("Dir: --------------\n");
			a->dir=inserir(a->dir,in,id);
		}
		return a;
	}
}
