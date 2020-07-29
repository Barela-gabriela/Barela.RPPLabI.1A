#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "empleado.h"
#include "controller.h"
#include "parser.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pArchivo;

    if((pArchivo = fopen(path, "r"))==NULL)
    {
        printf("No se puedo leer\n");
        exit(1);
    }
    else
    {
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);

        return 1;
    }


}
void controller_fil(LinkedList* parray)
{
    LinkedList* filtipos = ll_newLinkedList();
    int option;
    do
    {
        printf("1. BMX\n2. PLAYERA\n3. MTB\n4. PASEO\n5. SALIR\n");
        scanf("%d",&option);
        fflush(stdin);
        switch(option)
        {
        case 1:
            filtipos=ll_filter(parray,filtrarbmx);
            controller_saveAsText("bmx.txt",filtipos);
            break;
        case 2:
            filtipos=ll_filter(parray,filtrarplayera);
            controller_saveAsText("playera.txt",filtipos);
            break;
        case 3:
            filtipos=ll_filter(parray,filtrarmtb);
            controller_saveAsText("mtb.txt",filtipos);
            break;
        case 4:
            filtipos=ll_filter(parray,filtrarpaseo);
            controller_saveAsText("paseo.txt",filtipos);
            break;
        case 5:
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(option != 5);
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    eBici* pEmpleadoAux;
    int ret = 0;
    int idAux;
    char paisAux[50];
    char tipoAux[50];
    int tiempoAux;
    int lenList = ll_len(pArrayListEmployee);
    int i;
    if(pArrayListEmployee!=NULL)
    {
        if(lenList>0)
        {
            printf("Id--nombre----------------tipo--------------tiempo \n \n");

            for(i = 0; i < lenList; i++)
            {
                pEmpleadoAux = (eBici*)ll_get(pArrayListEmployee, i);

                eBici_get_id(pEmpleadoAux, &idAux);
                eBici_get_nombre(pEmpleadoAux,paisAux);
                eBici_get_tipo(pEmpleadoAux,tipoAux);
                eBici_get_tiempo(pEmpleadoAux,&tiempoAux);


                printf("%2d  %s\t\t  %s\t\t  %d\t\t \n",idAux, paisAux, tipoAux, tiempoAux);
            }

            ret = 1;

        }
        else
        {
            printf("No se cargaron los datos.\n");
        }
    }
    return ret;
}
/*
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_sortPorNombre, 0);/// 0 = DESCENDENTE, 1 = ASCENDENTE
    }

    return 1;
}*/
/*
int controller_sortEmployeeI(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_sortPorInfectados, 0);/// 0 = DESCENDENTE, 1 = ASCENDENTE
    }

    return 1;
}*/

int controller_mapEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        ll_map(pArrayListEmployee, employee_mapeo);
    }

    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayLista)
{
    int retorno=-1;
    int len;
    int idAuxiliar;
    char paisAuxiliar[50];
    char tipoAux[50];
    int tiempoAux;
    int i;
    FILE* Pfile = fopen(path,"w+");
    eBici* auxPais=eBici_new();

    if(Pfile != NULL && pArrayLista != NULL && auxPais!=NULL )
    {
        len=ll_len(pArrayLista);
        fprintf(Pfile, "id,nombre,tipo,tiempo\n");

        for(i=0; i<len; i++)
        {
                auxPais= ll_get(pArrayLista,i);

                eBici_get_id(auxPais, &idAuxiliar);
                eBici_get_nombre(auxPais,paisAuxiliar);
                eBici_get_tipo(auxPais,tipoAux);
                eBici_get_tiempo(auxPais,&tiempoAux);
                fflush(stdin);

            fprintf(Pfile,"%d,%s,%s,%d\n",idAuxiliar,paisAuxiliar,tipoAux,tiempoAux);
        }
            retorno = 1;
        }
        else
        {
            retorno=-1;
        }

    fclose(Pfile);

    return retorno;
}

/*LinkedList* controller_mayor(LinkedList* pArrayListEmployee)
{
    int mayor;
    int flag=0;
    eBici* auxPais=eBici_new();
    LinkedList* aux=ll_newLinkedList();
    if(pArrayListEmployee != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxPais= ll_get(pArrayListEmployee,i);

            if( auxPais->muertos > mayor || flag==0)
            {
                mayor=auxPais->muertos;
                flag=1;
            }
        }

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxPais= ll_get(pArrayListEmployee,i);
            if( auxPais->muertos==mayor)
            {
              ll_add(aux,ll_get(pArrayListEmployee,i));
            }
        }
    }
    return aux;
}*/
