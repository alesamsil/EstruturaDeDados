#include "Filapri.h"
struct filap{
	Fila comun;
	Fila pri;
};

struct filap* inicia(struct filap* a){
	if(a!=NULL){
		a->comun=inicializar(a->comun);
		a->pri=inicializar(a->pri);
		return a;
	}
	a=(struct filap*)malloc(sizeof(struct filap));
	a->comun=NULL;
	a->pri=NULL;
	return a;
}

void inserirpri(struct filap*a, char *nome, int id, char onde){
	if(onde=='p')
		a->pri=inserir(a->pri,nome,id);
	else
		a->comun=inserir(a->comun,nome,id);
}

void removerpri(struct filap* f,char *nome, int *id){
	char temp[81];
	int tempid;
	if(f->pri!=NULL)
		f->pri=remover(f->pri, temp, &tempid);
	else
		f->comun=remover(f->comun,temp,&tempid);
	strcpy(nome, temp);
	(*id)=tempid;	
}

void imprimirpri(struct filap*f, char tipo){
	if(tipo=='p')
		imprimir(f->pri);
	else if(tipo=='c')
		imprimir(f->comun);
	else{
		printf ("Fila Prioridades:\n");
		imprimir(f->pri);
		printf ("Fila Comum:\n");
		imprimir(f->comun);
	}		
}

struct filap* destruirpri(struct filap* f){
	f->pri=destruir(f->pri);
	f->comun=destruir(f->comun);
	free(f);
	return NULL;
}

