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
}; 

Casa* novocasa(){
	char t, r[21],b[21],c[31];
	Casa *no=(Casa*)malloc(sizeof(Casa));
	printf("Digite A para aluguel ou V para venda:\n");
	scanf("%c",&t);
	strcpy(no->tipo,t);
	printf("Digite o Preco:\n");
	scanf("%d",&no->preco);
	printf("Digite o Numero de Quartos:\n");
	scanf("%d",&no->quartos);
	printf("Digite a Rua:\n");
	scanf(" 20[^\n]",r);
	strcpy(no->e->rua,r);
	printf("Digite o Numero:\n");
	scanf("%d",&no->e->num);
	printf("Digite o Bairro:\n");
	scanf(" 20[^\n]",b);
	strcpy(no->e->bairro,b);
	printf("Digite a Cidade:\n");
	scanf(" 20[^\n]",c);
	strcpy(no->e->cidade,c);
	return no;
}
void inserir_imovel(Arv_imo a){
	int y=0;
	Casa n;
	n=novocasa();
	y=n->preco;
	inserir_no(a,y,n);
}
