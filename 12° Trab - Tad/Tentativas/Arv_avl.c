#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arv_avl.h"
struct arv_avl{
	int id;
	void *info;
	struct arvore *esq;
	struct arvore *dir;
};
Arv_avl inserir_no(Arv_avl a,int y,void *info){
	if(a==NULL){
		Arv_avl no=(Arv_avl*)malloc(sizeof(Arv_avl));
		no->id=y;
		no->info=info;
		no->esq=NULL;
		no->dir=NULL;
		return no;
	}
	else{
		if (y<=a->id)
			a->esq=inserir_no(a->esq,y,info);
		else
			a->dir=inserir_no(a->dir,y,info);
		return a;
	}
}
