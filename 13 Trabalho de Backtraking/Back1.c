#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cont=1;
int repetidos(char *str,int n){
	int i,j,r= 0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(str[i]<str[j])
				r=1;
    	}
	}
	return r;
}
void combinacoes( int *vet, int pos, int n, char *vetaux ){
	int i;
  	char vet2[n];
	if (pos==n){
  		for(i=0;i<n;i++)
			vet2[i]=vet[i];
		if( repetidos(vet2,n) == 0 ){
			if(n==1)
				printf("%d: %c", cont,vet2[n-1]);
			else
				printf("%d: %s", cont,vet2);
         	printf("\n");
         	cont++;
      	}
  	}	
	else{
		for(i=0;i<5;i++){
			vet[pos]=vetaux[i];
			combinacoes(vet,pos+1,n,vetaux);
    	}

  	}
}
int main(void){
	int n=0;
	char vetaux[5]= {'A','E','I','O','U'};
	printf("Digite o numero de combinacoes desejadas ateh 5\n");
	scanf("%d",&n);
	int vet[n];
	printf("\n\n");
	printf("Combinacoes de tamanho %d de (A E I O U)  \n\n",n);
	combinacoes(vet,0,n,vetaux);
	return 0;
}
