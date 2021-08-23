/* Universidade Federal Fluminense
   Instituto de Ciência e Tecnologia de Rio das Ostras
   Trabalho de TAD
   Disciplina: Estrutura de Dados
   Docente: Prof°. Dr°. Dalessandro Soares Vianna
   Discinte: Alessandro Sampaio
*/

typedef struct arvore *Arvore;
Arvore inicializar();
Arvore inserir(Arvore a, int n, char c, void *x);
void imprime_pre(Arvore a);
void imprime_ordem(Arvore a);
void imprime_pos(Arvore a);
void imprime_nivel(Arvore a, int nivel, int cont);
void imprime_largura(Arvore a, int cont);
Arvore remover(Arvore a, int n);
int balanceada (Arvore a);
int existe(Arvore a,int n);
Arvore libera(Arvore a);
