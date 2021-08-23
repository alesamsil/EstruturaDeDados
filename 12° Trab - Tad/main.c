#include<stdio.h>
#include<stdlib.h>
#include"Avl.h"
typedef struct musica{
    int numeroc;
    char artista[50];
    char album[50];
	int ano;
}Musica;
Musica *novo_musica(){
     Musica *m;
     m=(Musica*)malloc(sizeof(Musica));
     printf("Nome do Artista: \n");
     scanf("%s",m->artista);
     printf("Nome do Album: \n");
     scanf("%s",m->album);
     printf("Digite o ano: \n");
     scanf("%d",&m->ano);
	 printf("Numero de Copias: \n");
     scanf("%d",&m->numeroc);
	 return m;
}
int main(void) { 
    int b,c,cont=0;
    Arvore a;
    a=inicializar();
    Musica *m=NULL;
    int op,op1;
	while(op!=6){
		system("cls");
        printf("Digite a opcao desejada:\n\n");
		printf("1- Inserir\n");
        printf("2- Imprimir\n");
        printf("3- Remover\n");
        printf("4- Verificar se existe\n");
        printf("5- Verificar se a arvore esta balanceada\n");
        printf("6- Sair.\n\n");
        scanf("%d",&op);
        system("cls");
		switch(op){
			case 1:{
				m=novo_musica();
				char c;
				a=inserir(a,m->numeroc,c,m);
				system("pause");
                break;
            }
            case 2:{
				printf("1- Imprimir em pre-ordem.\n");
				printf("2- Imprimir em ordem.\n");
				printf("3- Imprimir em pos-ordem.\n");
				printf("4- Imprimir largura.\n\n");
				printf("Digite a opcao: ");
				scanf("%d",&op1);
				system("cls");
				switch(op1){
					case 1:{
						printf("Imprimindo em pre-ordem:\n");
						imprime_pre(a);
						printf("\n\n");
						break;
					}
					case 2:{
						printf("Imprimindo em ordem:\n");
						imprime_ordem(a);
						printf("\n\n");
						break;
					}
					case 3:{
						printf("Imprimindo em pos-ordem:\n");
						imprime_pos(a);
						printf("\n\n");
						break;
					}
					case 4:{
						printf("Imprimindo largura:\n");
						cont=0;
						imprime_largura(a,cont);
						printf("\n\n");
						break;
					}
				}
				system("pause");
				break;
			}
			case 3:{
				printf("Digite um numero: ");
				scanf("%d",&b);
				c=existe(a,b);
				if(c==1){
					a=remover(a,b);
					printf("\nElemento encontrado e removido com sucesso.\n\n");     
				}
				else
					printf("Elemento nao encontrado\n");
				system("pause");
				break;
            }
			case 4:{
				printf("Digite o numero de copias: ");
				scanf("%d",&b);
				c=existe(a,b);
				if(c==1)
					printf("Elemento encontrado\n");
				else
					printf("Elemento nao encontrado\n");
				system("pause");
				break;
            }
			case 5:{
				b=balanceada(a);
				if(b==0)
					printf("Arvore estah balanceada\n");
				else{
					printf("Arvore nao estah balanceada...\n\n");
					balancear(a);
					printf("Arvore balanceada com sucesso!!\n");
				}
				system("pause");
            	break;
			}
			case 6:{
				a=libera(a);
				break;
			}
        }
    }
	return 0;
}
