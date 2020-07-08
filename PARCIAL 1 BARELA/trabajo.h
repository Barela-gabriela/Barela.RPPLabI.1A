#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "bici.h"
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
   int id;
   int idBicicleta;
   int idServicio;
   eFecha fecha;
   int isEmpty;
}eTrabajo;

int buscarLibreTrabajo(eTrabajo trabajo[], int tamTra);
int altaTrabajos(eTrabajo trabajo[],int tamTra,eBicicleta bicicleta[],int tam,eServicio servicio[],int tamSer);
void hardcodeoTrabajo(eTrabajo trabajo[]);
void mostrarTrabajoInforme(eTrabajo trabajo, eBicicleta bici, eServicio servicio[],int tamSer,eCliente client[],int tamCli );
void cargarFechaTrabajo(eTrabajo trabajo[],int indice);
int generarNextIdTrabajo();
int inicializarTrabajo(eTrabajo trabajo[], int tamTrab);
int hayTrabajosCargados(eTrabajo trabajo[], int tamTra);
void menuTrabajo(eTrabajo trabajo[],int tamTra,eBicicleta bicicleta[],int tam,eServicio servicio[],int tamSer,eCliente client[],int tamCli);
void mostrarTrabajo(eTrabajo trabajo[],int tamTra,eBicicleta bicicleta[],int tam,eServicio servicio[],int tamSer,eCliente client[],int tamCli);

#endif // TRABAJO_H_INCLUDED
