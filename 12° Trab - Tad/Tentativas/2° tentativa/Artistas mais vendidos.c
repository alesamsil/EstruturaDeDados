#include "Arv_avl.h"
typedef struct musicas{
	char artista[81];
	char album[81];
	int ano;
	int ncopias;
}Musicas;
int main(void){
	int x=0,y=0;
	Arvore a;
	a=iniciar();
	Musicas *m=(Musicas*)malloc(sizeof(Musicas));
	
	while (x!=5){
		printf("Digite x: \n");
		scanf ("%d",&x);
		printf("Artista: \n");
		scanf (" %80[^\n]",m->artista);
		scanf (" %80[^\n]",m->album);
		scanf ("%d",&m->ano);
		scanf ("%d",&y);
		m->ncopias=y;
		a=inserir(a,m,y);
		printf("Aqui:2\n");
	}
return 0;
}
