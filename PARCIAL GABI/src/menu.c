#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int pedirOpcionMenu()
{
    int opcion;
    printf("                          A B M                  \n\n");
    printf(" 1. Cargar archivo  \n 2. Listar  \n 3. Mapear\n 4. Filtrar por tipo\n 5. \n 6.\n 7. Salir\n");
    scanf("%d", &opcion);

    return opcion;

}
