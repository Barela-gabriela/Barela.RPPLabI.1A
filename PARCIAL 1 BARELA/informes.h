#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "bici.h"
#include "utn.h"
#include "trabajo.h"
typedef struct{

	int id;
	int cantidad;
	int isEmpty;

}eMayorColor;

void printBikeColor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp);
void menuInformes(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eColor color[],int tamCol,eTipo tipos[],int tamTip,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp);
void printBikeTipo(eBicicleta bici[],int tamBici,eColor color[],int tamCol,eTipo tipo[],int tamTip,eCliente cliente[],int tamCli,eEmpleado empl[], int tamEmp);
void printBikeRodado(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp);
void sortbikeTipo(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp);
void contadorBike(eBicicleta bici[],int tamBici,eTipo tipo[],int tamTip,eColor color[],int tamCol);
void trabajosPorBici(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eCliente client[],int tamCli);
void printMayorColor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eMayorColor listaColorMayor[]);
void serviciosTotales(eBicicleta bici[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[], int tamser,eCliente client[],int tamCli);
void serviciosPorBici(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eCliente client[],int tamCli);
void serviciosPorFecha(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eCliente client[],int tamCli);
void findSalaryMax(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp);
void printBikeRodadoMayor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp);
int sortBicisInsercion(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp);
void biciMasVieja (eBicicleta bici[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamser ,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp);
#endif // INFORMES_H_INCLUDED
