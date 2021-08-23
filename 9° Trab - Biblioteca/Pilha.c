#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
struct Pilha{
	int vet[100];
	int topo;
};
Pilha inicializar(void){
	Pilha p=(Pilha)malloc(sizeof(struct Pilha));
	p->topo=0;
	return p;
}
int Cheia(Pilha p){
	if(p->topo==100)
		return 1;
	else 
		return 0;
}
void inserir (Pilha p, int x){
	if(Cheia(p)==1){
		printf("Erro!");
		return;
	}
	else {
		p->vet[p->topo]=x;
		p->topo++;
	}
}
int vazia (Pilha p){
	if (p->topo==0)
		return 1;
	else
		return 0;
}
int remover(Pilha p){
	if(vazia (p)==1){
		printf("Erro");
		return -1;
	}
	else{
		int a;
		p->topo--;
		a=p->vet[p->topo];
		return a;
	}
}
void destruir(Pilha p){
	free(p);
}
void imprimir (Pilha p){
	int i;
	for(i=0;i<p->topo;i++)
		printf("%d",p->vet[i]);
}
