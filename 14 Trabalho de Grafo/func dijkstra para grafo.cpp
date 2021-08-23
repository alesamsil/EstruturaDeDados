/* Universidade Federal Fluminense
   Instituto de Ciência e Tecnologia de Rio das Ostras
   Trabalho de Grafos
   Disciplina: Estrutura de Dados
   Docente: Prof°. Dr°. Dalessandro Soares Vianna
   Discinte: Alessandro Sampaio
*/

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

