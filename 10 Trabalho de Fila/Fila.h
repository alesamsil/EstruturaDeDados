/* Universidade Federal Fluminense
   Instituto de Ciência e Tecnologia de Rio das Ostras
   Trabalho de Fila
   Disciplina: Estrutura de Dados
   Docente: Prof°. Dr°. Dalessandro Soares Vianna
   Discinte: Alessandro Sampaio
*/


typedef struct fila *Fila;
Fila inserir(Fila f, char *nome, int id);
Fila remover (Fila f);
void imprimir (Fila f);
Fila inicializar (Fila f);
Fila destruir (Fila f);
