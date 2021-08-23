#include "fila_pri.h"
#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>


struct fila_p{
	Fila *comun;
	Fila *pri;
};
