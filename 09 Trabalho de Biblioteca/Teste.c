/* Universidade Federal Fluminense
   Instituto de Ciência e Tecnologia de Rio das Ostras
   Trabalho de Biblioteca
   Disciplina: Estrutura de Dados
   Docente: Prof°. Dr°. Dalessandro Soares Vianna
   Discinte: Alessandro Sampaio
*/

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
