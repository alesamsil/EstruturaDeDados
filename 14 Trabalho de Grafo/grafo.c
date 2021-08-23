/* Universidade Federal Fluminense
   Instituto de Ciência e Tecnologia de Rio das Ostras
   Trabalho de Grafos
   Disciplina: Estrutura de Dados
   Docente: Prof°. Dr°. Dalessandro Soares Vianna
   Discinte: Alessandro Sampaio
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct lista{
	int destino;
	float custo;
	struct lista *prox;	
}Lista;
Lista **inicializa(int tam){
	int i;
	Lista **g=(Lista**)malloc((tam)*sizeof(Lista*));
	for(i=0;i<tam;i++)
		g[i]=NULL;
	return g;
}
int ler_dados_grafo(int *tam,int *origem, int *destino,float *custo){
	printf("Digite a origem\n");
	printf ("-> ");
	scanf("%d",origem);
	if(*origem<*tam){
		printf("\nDigite o destino\n");
		printf ("-> ");
		scanf("%d",destino);
			if(*destino<*tam){					
				printf ("\nDigite o custo\n");
				printf ("-> ");
				scanf("%f",custo);
				return 1;
			}
			else{
				printf("\nDestino nao existente no grafo!!!\n");
				return 0;
			}
	}
	else{
		printf("\nOrigem nao existente no grafo!!!\n");
		return 0;
	}
}
int dados_grafo(int *tam,int *origem, int *destino){
	printf("Digite a origem\n");
	printf ("-> ");
	scanf("%d",origem);
	if(*origem<*tam){
		printf("\nDigite o destino\n");
		printf ("-> ");
		scanf("%d",destino);
			if(*destino<*tam)					
				return 1;
			else{
				printf("\nDestino nao existente no grafo!!!\n");
				return 0;
			}
	}
	else{
		printf("\nOrigem nao existente no grafo!!!\n");
		return 0;
	}	
}
Lista *inserirlista(Lista *l,int d, float c){
	Lista *no=(Lista*)malloc(sizeof(Lista));
	no->destino=d;
	no->custo=c;
	no->prox=l;
	l=no;
	return l;
}
Lista **inseriraresta(Lista **g, int tam, int origem, int destino, float custo){
	if(origem<tam)	
		g[origem]=inserirlista(g[origem],destino,custo);
	return g;
}
void imprime_lista(Lista* l){
    Lista *p;
    for(p=l;p!=NULL;p=p->prox){
        printf("Destino: %d ", p->destino);
        printf("Custo: %1.f -:>", p->custo);
    }
    printf("   ");
}
void imprime_grafo(Lista **g, int tam){
    int i;
    if(g!=NULL){
    	for(i=0;i<tam;i++){
        	printf("[%d] ",i);
        	imprime_lista(g[i]);
        	printf("\n");
    	}
	}
}
Lista* remover_lista(Lista *l, int destino){
	if(l!=NULL){
		if(l->destino==destino){
			Lista *temp=l->prox;
			free(l);
			return temp;
		}
		else{
			l->prox=remover_lista(l->prox,destino);
		}
	}
}
Lista** remover(Lista **g,int origem, int destino){
	g[origem]=remover_lista(g[origem],destino);
	return g;
}
int verifica_aresta(Lista **g,int tam, int origem,int destino){
	Lista *l;
	for(l=g[origem];l!=NULL;l=l->prox){
		if(l->destino==destino)
			return 1;
	}
	return 0;	
}
int calcular_grau(Lista **g, int tam, int origem){
	Lista *l;
	int j=0;
	if(origem<tam){
		for(l=g[origem];l!=NULL;l=l->prox)
			j++;
	}
	return j;	
}
int procura_lista(Lista *l, int procura){
	Lista *p;
	for(p=l;l!=NULL;l=l->prox){
		if(p->destino==procura)
			return 1;
	}
	return 0;
}
int verifica_completo(Lista **g, int tam){
	int i,j;
	for(i=1;i<tam;i++){
		for(j=1;j<tam;j++){
			if(j!=i){
				if(procura_lista(g[i],j)==0)
					return 0;
			}
		}
	}
	return 1;
}



void dijkstra(int vertices,int origem,int destino,int *custos){
	int i,v, cont = 0;
	int *ant, *tmp;  
	int *z;     /* vertices para os quais se conhece o caminho minimo */
	double min;
	double dist[vertices]; /* vetor com os custos dos caminhos */
	

	/* aloca as linhas da matriz */
	ant = calloc (vertices, sizeof(int *));
	tmp = calloc (vertices, sizeof(int *));
	if (ant == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
		exit(-1);
	}

	z = calloc (vertices, sizeof(int *));
	if (z == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
		exit(-1);
	}

	for (i = 0; i < vertices; i++) {
		if (custos[(origem - 1) * vertices + i] !=- 1) {
			ant[i] = origem - 1;
			dist[i] = custos[(origem-1)*vertices+i];
		}
		else {
			ant[i]= -1;
			dist[i] = HUGE_VAL;
		}
		z[i]=0;
	}
	z[origem-1] = 1;
	dist[origem-1] = 0;

	/* Laco principal */
	do {

		/* Encontrando o vertice que deve entrar em z */
		min = HUGE_VAL;
		for (i=0;i<vertices;i++)
			if (!z[i])
				if (dist[i]>=0 && dist[i]<min) {
					min=dist[i];v=i;
				}

		/* Calculando as distancias dos novos vizinhos de z */
		if (min != HUGE_VAL && v != destino - 1) {
			z[v] = 1;
			for (i = 0; i < vertices; i++)
				if (!z[i]) {
					if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i]) {
					   	dist[i] = dist[v] + custos[v*vertices+i];
						ant[i] =v;
				   	}
        		}
		}
	} while (v != destino - 1 && min != HUGE_VAL);

	/* Mostra o Resultado da busca */
	printf("\tDe %d para %d: \t", origem, destino);
	if (min == HUGE_VAL) {
		printf("Nao Existe\n");
		printf("\tCusto: \t- \n");
	}
	else {
		i = destino;
		i = ant[i-1];
		while (i != -1) {
		//	printf("<-%d",i+1);
			tmp[cont] = i+1;
			cont++;
			i = ant[i];
		}
		
		for (i = cont; i > 0 ; i--) {
			printf("%d -> ", tmp[i-1]);
		}
		printf("%d", destino);
		
		printf("\n\tCusto:  %d\n",(int) dist[destino-1]);
	}
}
void procurar(int tam, int origem, int destino, int* custos){
	int i, j;
	printf("Lista dos Menores Caminhos no Grafo Dado: \n");
		 	
	for (i = 0; i <=tam; i++) {
		for (j = 0; j <= tam; j++)
			dijkstra(tam,i,j,custos);
		printf("\n");
	}
}












/*
float busca_custo(Lista *l, int destino){
	Lista *p;
	for(p=l;p!=NULL;p=p->prox)
		if(p->destino==destino)
			return p->custo;
}


void caminho(Lista **g, int tam, int *o, int *d, float *auxc1, int *vet1){
	int op,o1,d1;
	float aux;
	printf("ERRO 1\n\n");
	printf("%d %d\n\n",*o,*d);
	for(*o;*o<tam;*o=*o+1){
		printf("ERRO 2\n\n");
		printf("%d %d\n\n",*o,*d);
		for(*d;*d<tam;*d=*d+1){
			printf("ERRO 3\n\n");
			printf("%d %d\n\n",*o,*d);
			if(*d!=*o){
				printf("ERRO 4\n\n");
				printf("%d %d\n\n",*o,*d);
				o1=*o;
				d1=*d;
				op=verifica_aresta(g,tam,o1,d1);
				if(op==1){
					printf("ERRO 5\n\n");
					*auxc1=busca_custo(g,&d);
					aux=aux+(*auxc1);
					vet1[*o]=*d;
					caminho(g,tam,*o+1,*d+1,&aux,&vet1);
				}
			}
		}
	}
}


int* menor_caminho(Lista **g, int tam, int origem, int destino, int* vet){
	
	int o=1,d=1,op;
	float auxc=0, auxc1=0;
	op=verifica_aresta(g,tam,origem,destino);
	if(op==1)
		auxc=busca_custo(g[origem],destino);
		caminho(g,tam,&o,&d,&auxc1,&vet);
	if (auxc<auxc1){
		printf("O menor caminho eh origem %d, destino %d, custo %f",origem,destino,auxc);
	}
	else{
		
	}
}


*/

Lista** limpar(Lista **g, int tam){
	int i=0;
	for (i=0;i<=tam;i++){
		while(g[i]!=NULL){
			Lista *p=g[i]->prox;
			free(g[i]);
			g[i]=p;
		}
	}
	return NULL;
}
int main(void){
	int x=0,tam=0,origem=0,destino=0,op=0;
	float custo=0;
	Lista **g;
	while(x!=10){
		system ("cls");
		printf ("Digite a opcao desejada\n\n");
		printf ("0 - inicializar\n");
		printf ("1 - Inserir uma Aresta\n");
		printf ("2 - Remover um Aresta\n");
		printf ("3 - Imprimir o Grafo\n");
		printf ("4 - Verificar se existe\n");
		printf ("5 - Calcular o grau de saida de um vertice\n");
		printf ("6 - Verifique se o grafo estah completo\n");
		printf ("7 - Menor caminho entre a origem e o destino\n");
		printf ("8 - Imprimir todos os caminhos\n");
		printf ("9 - Sair\n\n");
		printf ("-> ");
		scanf("%d",&x);
		system ("cls");
		switch (x){
			case 0:{
				printf("Digite o numero de vertices:\n\n");
				printf ("-> ");
				scanf("%d",&tam);
				tam=tam+1;
				g=inicializa(tam);
				printf("Grafo Inicializado!!\n\n");
				system ("pause");
				break;
			}
			case 1:{
				op=ler_dados_grafo(&tam,&origem,&destino,&custo);
				if(op==1){
					g=inseriraresta(g,tam,origem,destino,custo);
					printf("Aresta iserida com sucesso!!!\n\n");	
				}
				system ("pause");
				break;
			}
			case 2:{
				op=dados_grafo(&tam,&origem,&destino);
				if(op==1){
					g=remover(g,origem,destino);
					printf("Aresta removida com sucesso!!!\n\n");
				}
				system ("pause");
				break;
			}
			case 3:{
				imprime_grafo(g,tam);
				system ("pause");
				break;
			}
			case 4:{
				op=dados_grafo(&tam,&origem,&destino);
				if(op==1)
					op=verifica_aresta(g,tam,origem,destino);
					if(op==1)
						printf("Aresta existente!!!\n\n");
					else
						printf("Aresta nao existente!!!\n\n");
				system ("pause");
				break;
			}
			case 5:{
				printf("Digite o destino\n");
				printf("-> ");
				scanf("%d",&origem);
				op=calcular_grau(g,tam,origem);
				printf("\nO grau da aresta %d eh: %d\n\n",origem,op);	
				system ("pause");
				break;
			}
			case 6:{
				op=verifica_completo(g,tam);
				if(op==1)
					printf("Grafo estah completo!!!\n");
				else
					printf("Grafo nao estah completo!!!\n");
				system ("pause");
				break;
			}
			case 7:{
				int *custos=NULL;
				int i;
				custos = (int *) malloc(sizeof(int)*tam*tam);
				for (i=1; i<tam*tam;i++)
					custos[i] = -1;
				printf("Digite a origem\n");
				scanf("%d",&origem);
				printf("Digite o destino\n");
				scanf("%d",&destino);
				procurar(tam,origem,destino,custos);
				
				
				/*vet=(int*)malloc(tam*sizeof(int));
				printf("Digite a origem\n");
				scanf("%d",&origem);
				printf("Digite o destino\n");
				scanf("%d",&destino);
				*vet=menor_caminho(g,tam,origem,destino,&vet);
				*/
				system ("pause");
				break;
			}
			case 8:{
				system ("pause");
				break;
			}
			case 9:{
				g=limpar(g,tam);
				system ("pause");
				break;
			}
		}
	}
	return 0;
}
