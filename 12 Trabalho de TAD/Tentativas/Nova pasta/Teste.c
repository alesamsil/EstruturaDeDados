#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imovel.h"
#include "Arv_avl.h"

int main (void){
	Imovel m;
	int x=0,y=0,x1=0;
	while(x!=6){
		system ("cls");
        printf("[ -- Digite a opcao desejada -- ]\n\n");
        printf("1 - Inserir\n");
        printf("2 - Remover um elemento\n");
        printf("3 - Imprimir\n");
		printf("4 - Existe\n");
        printf("5 - Balancear Arvore \n");
		printf("6 - Sair\n");
        scanf("%d",&x);
        system ("cls");
        switch(x){
        	case 1:{
        		m=novoimov();
				inserir_imovel(m);
				printf("\n\nImovel inserido com sucesso!!\n\n");
				system("pause");
				break;
        	}
        	case 2:{
        		imprimir_ordem();
				system("pause");
        		break;
        	}
        	case 3:{
        		
				system("pause");
        		break;
        	}
        	case 4:{
        		system("pause");
        		break;
        	}
        	case 5:{
        		system("pause");
        		break;
        	}
        	case 6:{
        		system("pause");
        		break;
        	}
        	case 7:{
        		system("pause");
        		break;
        	}
        }
	}
	return 0;
}
