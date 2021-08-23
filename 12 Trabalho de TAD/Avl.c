/* Universidade Federal Fluminense
   Instituto de Ciência e Tecnologia de Rio das Ostras
   Trabalho de TAD
   Disciplina: Estrutura de Dados
   Docente: Prof°. Dr°. Dalessandro Soares Vianna
   Discinte: Alessandro Sampaio
*/

#include<stdio.h>
#include<stdlib.h>
#include"Avl.h"
struct arvore{
	int id;
	char tipo;
	void* info;
	struct arvore *esq;
	struct arvore *dir;
};
Arvore inicializar(){
	return NULL;
}
void imprime_pre(Arvore a){
	if(a!=NULL){
	   printf("%d\t",a->id);
	   imprime_pre(a->esq);
	   imprime_pre(a->dir);
	}
}
void imprime_ordem(Arvore a){
	if(a!=NULL){
		imprime_ordem(a->esq);
        printf("%d\t",a->id);
        imprime_ordem(a->dir);
    }
}
void imprime_pos(Arvore a){
	if(a!=NULL){
		imprime_pos(a->esq);
        imprime_pos(a->dir);
        printf("%d\t",a->id);
    }
}
void imprime_nivel(Arvore a, int nivel, int cont){ 
	if(a!=NULL){
		if(cont==nivel)
			printf("%d\t",a->id);
		else{
			imprime_nivel(a->esq,nivel,cont+1);
			imprime_nivel(a->dir,nivel,cont+1); 
        } 
    } 
}
int altura(Arvore a){
	if(a==NULL)
		return 0;
	else{
		int he,hd;
		he=altura(a->esq);
		hd=altura(a->dir);
		if(he>hd)
		   return he+1;
          else
			return hd+1;
	}
}
void imprime_largura(Arvore a, int cont){
     int i;
	 int b; 
	 b=altura(a); 
     if(a!=NULL){
       for(i=0;i<b;i++){
          imprime_nivel(a,i,cont); 
          printf("\n");
       }
     } 
}
 Arvore inserir(Arvore a, int n, char c, void *x){
 	Arvore no=(Arvore)malloc(sizeof(struct arvore));
	 no->id=n;
	 no->tipo=c;
	 no->info=x;
	 if(a==NULL){
	 	no->dir=NULL;
		no->esq=NULL;
		return no;
    }
    else{
		if(n<=a->id)
			a->esq=inserir(a->esq,n,c,x);
		else if(n>a->id)
			a->dir=inserir(a->dir,n,c,x);
		return a;
	}
 }                     
 Arvore remover(Arvore a, int n){
   if(a!=NULL){
     if(n<a->id)
       a->esq=remover(a->esq,n);
       else if(n>a->id)
         a->dir=remover(a->dir,n);
         else{
            if(a->esq==NULL && a->dir==NULL){
              free(a);
              return NULL;
            }
            else if(a->esq==NULL || a->dir==NULL){
              Arvore aux;
              if(a->esq==NULL)
                aux=a->dir;
				else
                  aux=a->esq;
              free(a);
              return aux;
            }
            else{
              Arvore aux=a->esq;
              while(aux->dir != NULL)
                 a=aux->dir;
              a->id=aux->id;
              a->esq=remover(a->esq,aux->id);
              return a;
            }
       }
       return a;
  }
}      
 int existe(Arvore a,int n){
     if(a==NULL)
         return 0;
     else{
         if(a->id==n)
             return 1;
         else{
             if(existe(a->esq,n)==1)
               return 1;
             else
              return existe(a->dir,n);
         }
     }
 }
 int balanceada (Arvore a){
     if(a==NULL)
       return 0;
       else{
            int he,hd;
            he=altura(a->esq);
            hd=altura(a->dir);
            if(he>hd+1)
               return 1+balanceada(a->esq);
               else if(hd>he+1)
                  return 1+balanceada(a->dir);
                  else
                     return 0;
       }
 }
 Arvore balancear(Arvore a){
      if(a!=NULL){
         int hd,he;
         a->esq=balancear(a->esq);
         a->dir=balancear(a->dir);
         he=altura(a->esq);
         hd=altura(a->dir);
         if(he-hd>1){
           Arvore p=a->esq;
           int aux1,aux2;
           char tipo;
           while(p->dir!=NULL)
               p=p->dir;
           aux1=a->id;
           tipo=a->tipo;
           void *y=a->info;
           aux2=p->id;           
		   a->esq=remover(a->esq,aux2);
           a->dir=inserir(a->dir,aux1,tipo,y);
           a->id=aux2;
           a=balancear(a);
         }
           else if(hd-he>1){
                Arvore p=a->dir;
                int aux1,aux2;
                char tipo;
                while(p->esq!=NULL)
                     p=p->esq;
                aux1=a->id;
                tipo=a->tipo;
                void *y=a->info;
                aux2=p->id;
                a->dir=remover(a->dir,aux2);
                a->esq=inserir(a->esq,aux1,tipo,y);
                a->id=aux2;
                a=balancear(a);
           }
     }
     return a;
}
Arvore libera(Arvore a){
     if(a!=NULL){
        libera(a->esq);
        libera(a->dir);
        free(a);
     }
     return NULL;
}
