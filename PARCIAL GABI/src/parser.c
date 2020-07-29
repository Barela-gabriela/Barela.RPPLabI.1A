#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "empleado.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    eBici* auxEmpleado = eBici_new();
    int r;
    int i = 0;
    char idAux[50],nombreAux[50],tipoAux[50],tiempoAux[50];

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,tipoAux,tiempoAux);

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,tipoAux,tiempoAux);
        if(r==4)
        {
            auxEmpleado = empleado_nuevosParametros(idAux,nombreAux,tipoAux,tiempoAux);
            ll_add(pArrayListEmployee, auxEmpleado);
            i++;
        }
    }
    printf("Se cargaron %d bicicletas a la lista (modo texto)\n", i);

    return i;

}
