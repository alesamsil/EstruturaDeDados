#include <stdlib.h>
#include <stdio.h>
#include "Fila.h"
#include "fila_p.h"
struct fila_p{
	Fila *comun;
	Fila *pri;
};
