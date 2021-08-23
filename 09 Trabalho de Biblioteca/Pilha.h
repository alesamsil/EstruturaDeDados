/* Universidade Federal Fluminense
   Instituto de Ciência e Tecnologia de Rio das Ostras
   Trabalho de Biblioteca
   Disciplina: Estrutura de Dados
   Docente: Prof°. Dr°. Dalessandro Soares Vianna
   Discinte: Alessandro Sampaio
*/

typedef struct pilha *Pilha;
Pilha inicializar();
void destruir (Pilha p);
void inserir (Pilha p, int x);
int remover (Pilha p);
void imprimir (Pilha p);
