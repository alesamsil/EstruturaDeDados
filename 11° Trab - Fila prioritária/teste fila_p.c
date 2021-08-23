#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Filapri.h"

int main(void){
	Filap f=NULL;
	f=inicia(f);
	int i=0,x=0,op=0,d=0;
    char n[81];
    char *nome;
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
                printf("Digite o nome\n");
                scanf(" %80[^\n]",n);
                printf("\n");
				printf("Digite a idade\n");
                scanf("%d",&d);
                if(d>=60){
                	inserirpri(f,n,d,'p');
	                printf("Elemento inserido com sucesso\n");
                }
                else{
                	inserirpri(f,n,d,'c');
                	printf("Elemento inserido com sucesso\n");
                }
				system("pause");
                break;
            }
            case 2:{
            	removerpri(f,n,&d);
				printf ("Nome: %s\n",n);
				printf ("Idade: %d\n",d);
				system("pause");
            	break;
            }
            case 3:{
            	printf("Digite a opcao desejada:\n\n");
            	printf("1 - Imprimir Fila prioritária\n");
				printf("2 - Imprimir Fila Comun\n");
				printf("3 - Imprimir Todos\n");
				scanf("%d",&op);
				system ("cls");
				switch (op){
					case 1:{
						printf ("Fila Prioridade:\n\n");
						imprimirpri(f,'p');
						break;
					}
					case 2:{
						printf ("Fila Comun:\n\n");
            			imprimirpri(f,'c');
						break;
					}
					case 3:{
						printf ("Fila Prioritaria e Comum:\n\n");
						printf ("Fila Prioridade:\n");
						imprimirpri(f,'p');
						printf ("Fila Comum:\n");
						imprimirpri(f,'c');
						break;
					}
				}				
				system("pause");
				break;
            }
            case 4:{
            	f=inicia(f);
            	printf ("Sua fila foi iniciada\n\n");
				system("pause");
            	break;
            }
            case 5:{
            	f=destruirpri(f);
            	printf ("Fila encerrada\n\n");
				system("pause");
				break;
            }

        }
    }
   return 0; 
}

