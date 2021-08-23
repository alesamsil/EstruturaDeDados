#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
int main(void){
	Fila f = NULL;
    int i=0,x=0;
    while (x!=5){
        system ("cls");
        printf("[ -- Digite a opcao desejada -- ]\n\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover um elemento\n");
        printf("3 - Imprimir\n");
        printf("4 - Inicializar\n");
        printf("5 - Sair\n");
        scanf("%d",&x);
        system ("cls");
        switch (x){
            case 1:{
                char n[81];
                int d;
                printf("Digite o nome\n");
                scanf(" %80[^\n]",n);
                printf("\n");
				printf("Digite a idade\n");
                scanf("%d",&d);
                f=inserir(f,n,d);
                printf("Elemento inserido com sucesso\n");
				system("pause");
                break;
            }
            case 2:{
            	printf ("O primeiro elemento serah removido...\n\n");
            	f=remover(f);
            	system("pause");
            	break;
            }
            case 3:{
            	imprimir(f);
            	system("pause");
				break;
            }
            case 4:{
            	f=inicializar(f);
            	printf ("Sua fila foi iniciada\n\n");
				system("pause");
            	break;
            }
            case 5:{
            	f=destruir(f);
            	printf ("Fila encerrada\n\n");
				system("pause");
				break;
            }

        }
    }
   return 0; 
}
