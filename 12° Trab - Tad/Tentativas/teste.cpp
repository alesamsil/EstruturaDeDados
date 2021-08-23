#include "imovel.h"
struct end{
	char rua[21];
	int num;
	char bairro[21];
	char cidade[31];
};
struct casa{
	char tipo;
	int preco;
	int quartos;
	struct end *e;
}Casa;
struct apto{
	char tipo;
	int preco;
	int andar;
	int quartos;
	struct end *e;
}Apto;

int main (void){
	Arv_imo *a;
	int x=0;
	while(x!=7){
		system ("cls");
        printf("[ -- Digite a opcao desejada -- ]\n\n");
        printf("1 - Ler a arvore de um arquivo\n");
		printf("2 - Inserir\n");
        printf("3 - Remover um elemento\n");
        printf("4 - Existe\n");
		printf("5 - Imprimir\n");
        printf("6 - Balancear Arvore \n");
		printf("7 - Sair\n");
        scanf("%d",&x);
        system ("cls");
        switch(x){
        	case 1:{
        		system("pause");
				break;
        	}
        	case 2:{
        		inserir_imovel(a);
				printf("Imovel inserido com sucesso!!\n");
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
}
