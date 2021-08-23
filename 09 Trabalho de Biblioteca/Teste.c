#include "Pilha.h"
int main(){
	int x=0;
	Pilha*p;
	p=inicializar ();
	inserir(p,10);
	inserir(p,5);
	imprimir(p);
	x=remover(p);
	printf ("%d",x);
	destruir(p);
}
