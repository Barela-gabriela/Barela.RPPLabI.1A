#include "empleado.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

eBici* eBici_new()
{
    eBici* pPais;
    pPais = (eBici*)calloc(sizeof(eBici), 1);

    pPais->id=0;
    pPais->tiempo=0;
    strcpy(pPais->nombre," ");
    strcpy(pPais->tipo," ");
    return pPais;
}

eBici* empleado_nuevosParametros(char idAux[50],char nombreAux[50],char tipoAux[50],char tiempoAux[50])
{
    eBici* auxEmpleado = eBici_new();

    if( auxEmpleado != NULL )
    {
        int id = atoi(idAux);
        eBici_set_id(auxEmpleado, id);

        int tiempo = atoi(tiempoAux);
        eBici_set_tiempo(auxEmpleado, tiempo);

        eBici_set_nombre(auxEmpleado,nombreAux);
        eBici_set_tipo(auxEmpleado,tipoAux);

    }
    return auxEmpleado;
}



int eBici_get_id (eBici* ptrPais,int* this)
{
    int ret = -1;
    if (ptrPais!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrPais->id;
            ret = 0;
        }
    }
    return ret;
}
int eBici_set_id (eBici* ptrPais,int this)
{
    int ret = -1;
    if (ptrPais!=NULL)
    {
        if (this>0)
        {
            ptrPais->id = this;
            ret = 0;
        }
    }
    return ret;
}

int eBici_get_nombre (eBici* ptrPais,char* this)
{
    int ret = -1;
    if (ptrPais!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrPais->nombre);
            ret = 0;
        }
    }
    return ret;
}

int eBici_set_nombre(eBici* ptrPais,char* this)
{
    int ret = -1;
    if (ptrPais!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrPais->nombre,this);
            ret = 0;
        }
    }
    return ret;
}
int eBici_get_tipo (eBici* ptrPais,char* this)
{
    int ret = -1;
    if (ptrPais!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrPais->tipo);
            ret = 0;
        }
    }
    return ret;
}

int eBici_set_tipo(eBici* ptrPais,char* this)
{
    int ret = -1;
    if (ptrPais!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrPais->tipo,this);
            ret = 0;
        }
    }
    return ret;
}



int eBici_get_tiempo(eBici* ptrPais,int* this)
{
    int ret = -1;
    if (ptrPais!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrPais->tiempo;
            ret = 0;
        }
    }
    return ret;
}

int eBici_set_tiempo (eBici* ptrPais,int this)
{
    int ret = -1;
    if (ptrPais!=NULL)
    {
        if (this>0)
        {
            ptrPais->tiempo = this;
            ret = 0;
        }
    }
    return ret;
}



int employee_sortPorNombre(void* employeeA,void* employeeB)
{
    char auxNameA [50], auxNameB [50];
    int ret;

    if((employeeA != NULL)&&(employeeB !=NULL))
    {
        eBici_get_nombre(employeeA, auxNameA);
        eBici_get_nombre(employeeB, auxNameB);

        ret = stricmp(auxNameA, auxNameB);

    }

    return ret;

}
/*int employee_sortPorInfectados(void* employeeA, void* employeeB)
{
    int paisA, paisB;
    int ret=0;

    if((employeeA !=NULL)&&(employeeB !=NULL))
    {
        eBici_get_infectados(employeeA,&paisA);
        eBici_get_infectados(employeeB,&paisB);
        if (paisA>paisB)
        {
            ret=1;
        }
        else if(paisA<paisB)
        {
            ret=-1;
        }
    }
    return ret;
}*/



int employee_mapeo(void* persona)
{
    eBici* auxPais = (eBici*)persona;
    int aleatorio1;
     aleatorio1 = rand()%120;

     eBici_set_tiempo(auxPais, aleatorio1);

     return 1;
}
int filtrarbmx(void*persona)
{
    eBici*auxBici=(eBici*)persona;
    int retorno=0;
    if(strcmp(auxBici->tipo,"BMX")==0)
    {
        retorno=1;
    }
    return retorno;
}
int filtrarplayera(void*persona)
{
    eBici*auxBici=(eBici*)persona;
    int retorno=0;
    if(strcmp(auxBici->tipo,"PALYERA")==0)
    {
        retorno=1;
    }
    return retorno;
}
int filtrarmtb(void*persona)
{
    eBici*auxBici=(eBici*)persona;
    int retorno=0;
    if(strcmp(auxBici->tipo,"MTB")==0)
    {
        retorno=1;
    }
    return retorno;
}
int filtrarpaseo(void*persona)
{
    eBici*auxBici=(eBici*)persona;
    int retorno=0;
    if(strcmp(auxBici->tipo,"PASEO")==0)
    {
        retorno=1;
    }
    return retorno;
}
