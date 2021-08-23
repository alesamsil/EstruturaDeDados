/* Universidade Federal Fluminense
   Instituto de Ciência e Tecnologia de Rio das Ostras
   Trabalho de Fila Prioritaria
   Disciplina: Estrutura de Dados
   Docente: Prof°. Dr°. Dalessandro Soares Vianna
   Discinte: Alessandro Sampaio
*/

#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct filap* Filap;
struct filap* inicia(struct filap* a);
void removerpri(struct filap* f,char *nome, int *id);
void imprimirpri(struct filap*f, char tipo);
struct filap* destruirpri(struct filap* f);
