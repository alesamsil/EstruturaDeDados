/* Universidade Federal Fluminense
   Instituto de Ciência e Tecnologia de Rio das Ostras
   Trabalho de Fila Prioritaria
   Disciplina: Estrutura de Dados
   Docente: Prof°. Dr°. Dalessandro Soares Vianna
   Discinte: Alessandro Sampaio
*/

#include "fila_pri.h"
#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>


struct fila_p{
	Fila *comun;
	Fila *pri;
};
