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
Arv_avl inserir(Arv_avl a,void *info,int y){
	if(a==NULL){
		Arv_avl no=(Arv_avl)malloc(sizeof(struct arv_avl));
		no->id=y;
		no->info=info;
		no->esq=NULL;
		no->dir=NULL;
		return no;
	}
	else{
		if (y<=a->id)
			a->esq=inserir(a->esq,info,y);
		else
			a->dir=inserir(a->dir,info,y);
		return a;
	}
}
