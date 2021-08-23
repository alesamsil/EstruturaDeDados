#include <stdio.h>
#include <stdlib.h>
#include "imovel.h"
#include "Arv_avl.h"
struct imovel{
	char tipo;
	float preco;
	int quartos;
	char end[201];
};
Arv_avl a=NULL;
Imovel novoimov(){
	Imovel novo=(Imovel)malloc(sizeof(struct imovel));
	printf("Digite C para casa ou A para apartamento\n-> ");
	scanf("%s",&novo->tipo);
	printf("\nDigite o preco\n-> ");
	scanf("%f",&novo->preco);
	printf("\nDigite a quantidade de quartos\n-> ");
	scanf("%d",&novo->quartos);
	printf("\nDigite o endereco\n-> ");
	scanf("\n %200[^\n]",novo->end);
	return novo;
}
void inserir_imovel(Imovel m){
	a=inserir(a,m);
}
/*void imprimir_ordemavl(Arv_avl a){
	if(a!=NULL){
		imprimir_ordemavl(a->esq);
		Imovel n=(Imovel)malloc(sizeof(struct imovel));
		n=(Imovel)a->info;
		printf("%c",n->tipo);
		printf("%f",n->preco);
		printf("%i",n->quartos);
		printf("%s",n->end);
		imprimir_ordemavl(a->dir);
	}	
}
void imprimir_ordem(){
	imprimir_ordemavl(a->esq,m);
	imprimir_ordemavl(a,m);
	imprimir_ordemavl(a->dir,m);
}
*/
