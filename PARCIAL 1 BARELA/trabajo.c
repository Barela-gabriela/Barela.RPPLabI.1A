#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "bici.h"
#include "trabajo.h"
#include "utn.h"

/// 0 = ocupado
/// 1 = vacio


void hardcodeoTrabajo(eTrabajo trabajo[])
{
    int codigoServicio[10] = { 1000, 1001, 1002, 1003, 1003, 1002, 1002, 1000, 1001, 1001};
    int codigoBici[10] = {1, 2, 4, 4, 6, 6, 8, 8, 8, 10};
    eFecha fechaTrabajo[10] = {{13,7,2018},{1,9,2017},{2,10,2008},{24,12,2005},{12,2,2019},{12,2,2019},{28,3,2017},{7,4,2019},{5,5,2005},{13,7,2018}};


    for(int i=0; i<10; i++)
    {
        trabajo[i].id=generarNextIdTrabajo();

        trabajo[i].idBicicleta=codigoBici[i];

        trabajo[i].idServicio=codigoServicio[i];

        trabajo[i].fecha=fechaTrabajo[i];

        trabajo[i].isEmpty=0;

    }
}

int altaTrabajos(eTrabajo trabajo[],int tamTra,eBicicleta bicicleta[],int tam,eServicio servicio[],int tamSer)
{

    int indice;
    int respuesta;
    //int bici=0;
    int auxIdBici;
    int auxIdServicio;
    int myReturn=-1;
    int existeBici=-1;
    int existeServicio=-1;

    indice = buscarLibreTrabajo(trabajo, tamTra);
    if( indice == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        system("cls");

        for(int i=0; i<tam; i++)
        {
            if(bicicleta[i].isEmpty==0)
            {
                printf("\nId biciclceta:  %d",bicicleta[i].id);
            }
        }
        do
        {
            printf("\nIngrese el ID bicicleta: ");
            fflush(stdin);
            scanf("%d",&auxIdBici);

            for(int i=0; i < tam; i++)
            {
                if(auxIdBici==bicicleta[i].id && bicicleta[i] .isEmpty==0)
                {
                    existeBici=0;
                    trabajo[indice].idBicicleta=auxIdBici;
                    break;
                }
            }
        }
        while(existeBici==-1);
        //bici=findBikeById(auxIdBici,bicicleta,tam);

        for(int i=0; i<tamSer; i++)
        {
            printf("\nIngrese ID del servicio: %d",servicio[i].id);
        }
        do
        {
            printf("\nIngrese ID servico: ");
            fflush(stdin);
            scanf("%d",&auxIdServicio);

            for(int i=0; i < tamSer; i++)
            {
                if(auxIdServicio==servicio[i].id )
                {
                    trabajo[indice].idServicio=auxIdServicio;
                    existeServicio=0;
                }
            }
        }
        while(existeServicio==-1);
        system("cls");

        printf("Ingrese fecha del Trabajo: \n");
        cargarFechaTrabajo(trabajo,indice);



        fflush(stdin);
        getValidInt("Esta seguro que quiere darle de alta a este Trabajo? <1.Si-2.No>","\Eerror ingrese un dato valido  <1-2>\n",1,2,&respuesta);

        if(respuesta==1)
        {

            trabajo[indice].isEmpty = 0;


            trabajo[indice].id=generarNextIdTrabajo();

            printf("Alta Trabajo exitosa!!!\n\n");

            myReturn=0;

        }
        else
        {

            printf("alta cancelada");

        }
    }

    return myReturn;

}
int buscarLibreTrabajo(eTrabajo trabajo[], int tamTra)
{
    int indice = -1;

    for(int i=0; i < tamTra; i++)
    {
        if(trabajo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void cargarFechaTrabajo(eTrabajo trabajo[],int indice)
{
    int auxDia;
    int auxMes;
    int auxAnio;


    getValidInt("Ingrese dia: ","\nPor favor ingrese un dia valido entre 1 y 30: \n",1,30,&auxDia);

    trabajo[indice].fecha.dia=auxDia;


    getValidInt("Ingrese mes:","Por favor ingrese un mes valido entre 1 y 12: \n",1,12,&auxMes);

    trabajo[indice].fecha.mes=auxMes;


    getValidInt("Ingrese anio: ","Por favor ingrese un anio valido entre 1960 y 2030: \n",1980,2020,&auxAnio);

    trabajo[indice].fecha.anio=auxAnio;
}
int generarNextIdTrabajo()
{
    static int id=200;

    id ++;

    return id;
}
void mostrarTrabajo(eTrabajo trabajo[],int tamTra,eBicicleta bicicleta[],int tam,eServicio servicio[],int tamSer,eCliente client[],int tamCli)
{
    int index;

    system("cls");
    printf("  *** Listado de trabajos ***\n\n");
    printf("\nTRABAJO    BICICLETA      MARCA   CLIENTE     SERVICIO       PRECIO       FECHA\n");

    for(int i=0; i< tamTra; i++)
    {
        if(trabajo[i].isEmpty==0)
        {

         index=findBikeById(trabajo[i].idBicicleta,bicicleta,tam);
         mostrarTrabajoInforme(trabajo[i],bicicleta[index],servicio,tamSer,client,tamCli);
        }


    }

}

void mostrarTrabajoInforme(eTrabajo trabajo, eBicicleta bici, eServicio servicio[],int tamSer,eCliente client[],int tamCli )
{

    char marcaBici[20];
    char descripcionServicio[20]= {"asd"};
    char descripcionCliente[20]= {"asd"};
    float precio=0;

    strcpy(marcaBici, bici.marca);

    for( int k = 0; k < tamSer; k++)
    {
        if(trabajo.idServicio == servicio[k].id)
        {

            for(int l=0; l<tamCli; l++)
            {
                if(client[l].id==bici.idCliente)///busco el id de sectores
                {
                    strcpy(descripcionCliente,client[l].nombre);
                    strcpy(descripcionServicio, servicio[k].descripcion);
                    precio = servicio[k].precio;
                    break;

                }
            }


        }

    }

    printf("%d %11d %15s %10s %10s %12.2f %10d/%d/%d\n",trabajo.id
           ,trabajo.idBicicleta
           ,marcaBici
           ,descripcionCliente
           ,descripcionServicio
           ,precio
           ,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
}


int inicializarTrabajo(eTrabajo trabajo[], int tamTrab)
{
    int myReturn=-1;

    for(int i=0; i < tamTrab; i++)
    {
        trabajo[i].isEmpty = 1;

        myReturn=0;
    }

    return myReturn;
}
void menuTrabajo(eTrabajo trabajo[],int tamTra,eBicicleta bicicleta[],int tam,eServicio servicio[],int tamSer,eCliente client[],int tamCli)
{
    int option;

    do
    {

        system("cls");
        printf("  *** TRABAJOS ***\n\n");
        printf("1- Alta trabajo\n");
        printf("2- Listar los trabajos\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)

        {
        case 1:

            altaTrabajos(trabajo,tamTra,bicicleta,tam,servicio,tamSer);

            break;
        case 2:
            if(hayTrabajosCargados(trabajo,tamTra)==1)
            {

                mostrarTrabajo(trabajo,tamTra,bicicleta,tam,servicio,tamSer,client,tamCli);
            }
            else
            {
                printf("ERROR, por favor cargue un Trabajo antes de continuar\n");

            }
            break;
        case 3:
            printf("\nREGRESANDO AL MENU PRINCIPAL\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-7>\n");
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option!=3);
}
int hayTrabajosCargados(eTrabajo trabajo[], int tamTra)
{
    int hayTrabajos = -1;

    for(int i=0; i < tamTra; i++)
    {
        if(trabajo[i].isEmpty == 0)
        {
            hayTrabajos = 1;
            break;
        }
    }

    return hayTrabajos;
}
