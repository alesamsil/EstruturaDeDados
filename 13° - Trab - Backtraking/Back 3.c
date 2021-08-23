#include<stdlib.h>
#include<stdio.h>
void imprime(float *qtd,float *moedas){
	int i;
	for(i=0;i<4;i++)
	   printf("Moedas de %0.2f: %.f \n",moedas[i],qtd[i]);
}
int t=1;
void cmoedas(float* qtd, float *moedas, float valor, int pos){ 
    int i; 
	if(pos==4){
		float soma = qtd[0]*800+qtd[1]*700+qtd[2]*300+qtd[3]; 
		if(soma==valor){
			printf("\n\nPossibilidade: %d\n",t);
			t++;
			imprime(qtd,moedas);
			printf("\n");
			printf("---------------------------------\n");
		}
	} 
	else{ 
		float x=valor/moedas[pos]; 
		for(i=0; i<=x; i++){
			qtd[pos]=i; 
			cmoedas(qtd,moedas,valor,pos+1); 
		} 
	} 
}
int main (void){
	float vet[3],n;
	float moedas[]={8.00,7.00,3.00,1.00};
	printf("Digite o valor sem a virgula: ");
	scanf("%f",&n);
	cmoedas(vet,moedas,n,0);
    return 0;
}
