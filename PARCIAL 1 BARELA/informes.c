#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "informes.h"
#include "utn.h"
#include "trabajo.h"
#include "bici.h"

void menuInformes(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eColor color[],int tamCol,eTipo tipos[],int tamTip,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp)
{
    int option;
    eMayorColor listaColorMayor[10];
    do
    {

        printf("\t ******MENU DE INFORMES******\n\t");
        printf("\n1.Bicicletas por color");
        printf("\n2.Bicicletas por tipo");
        printf("\n3.Bicicletas menor rodado");
        printf("\n4.Mostrar listado de bicicletas por tipo");
        printf("\n5.Contador de Color y tipo");
        printf("\n6.Contador mayor color");
        printf("\n7.Trabajos por bicicleta");
        printf("\n8.Servicios totales por bicicleta");
        printf("\n9.Trabajos por servicio");
        printf("\n10.Servicios por fecha");
        printf("\n11.Salario mayor y promedio de los salarios");
        printf("\n12.Bicicletas mayor rodado");
        printf("\n13.Ordenar bicis por insercion");
        printf("\n14.Trabajo mas viejo");
        printf("\n15.Salir\n\n");
        scanf("%d", &option);

        switch(option)

        {
        case 1:
            printBikeColor(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli,empl,tamEmp);
            break;
        case 2:
            printBikeTipo(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli,empl,tamEmp);

            break;
        case 3:
            printBikeRodado(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli,empl,tamEmp);
            break;
        case 4:
            sortbikeTipo(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli,empl,tamEmp);

            break;
        case 5:
            contadorBike(bicicletas,tamBici,tipos,tamTip,color,tamCol);

            break;
        case 6:
            printMayorColor(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli,listaColorMayor);
            break;
        case 7:
            trabajosPorBici(bicicletas,tamBici,trabajo,tamTra,servicio,tamSer,client,tamCli);
            break;
        case 8:

            serviciosTotales(bicicletas,tamBici,trabajo,tamTra,servicio,tamSer,client,tamCli);
            break;
        case 9:

            serviciosPorBici(bicicletas,tamBici,trabajo,tamTra,servicio,tamSer,client,tamCli);
            break;
        case 10:

            serviciosPorFecha(bicicletas,tamBici,trabajo,tamTra,servicio,tamSer,client,tamCli);
            break;
             case 11:

            findSalaryMax(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli,empl,tamEmp);

            break;
             case 12:

              printBikeRodadoMayor(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli,empl,tamEmp);
            break;
             case 13:
                sortBicisInsercion(bicicletas,tamBici,color,tamCol,tipos,tamTip,client,tamCli,empl,tamEmp);

            break;
             case 14:

                biciMasVieja(bicicletas,tamBici,trabajo,tamTra,servicio,tamSer,color,tamCol,tipos,tamTip,client,tamCli,empl,tamEmp);

                break;

        case 15:
            printf("\nREGRESANDO AL MENU PRINCIPAL\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-15>\n");
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");
    }
    while(option!=15);
}

void  serviciosPorFecha(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eCliente client[],int tamCli)
{
    int dia;
    int mes;
    int anio;
    int encontroFecha=0;
    int index;

    system("cls");


    getValidInt("Ingrese dia: ","\nPor favor ingrese un dia valido entre 1 y 30: \n",1,30,&dia);

    getValidInt("Ingrese mes: ","\nPor favor ingrese un mes valido entre 1 y 12: \n",1,12,&mes);

    getValidInt("Ingrese anio: ","\nPor favor ingrese un anio valido entre 1960 y 2019: \n",1980,2020,&anio);

    system("cls");
    printf("\nTRABAJO    BICICLETA      MARCA   CLIENTE     SERVICIO       PRECIO       FECHA\n");

    for (int i=0; i<tamTra; i++)
    {
        if (trabajo[i].isEmpty == 0 && trabajo[i].fecha.dia == dia && trabajo[i].fecha.mes == mes && trabajo[i].fecha.anio == anio)
        {
            for (int j=0; j<tamSer; j++)
            {
                if (trabajo[i].idServicio == servicio[j].id )
                {
                    index=findBikeById(trabajo[i].idBicicleta,bicicletas,tamBici);
                    mostrarTrabajoInforme(trabajo[i],bicicletas[index],servicio,tamSer,client,tamCli);
                    encontroFecha=1;
                }
            }
        }
    }

    if(encontroFecha==0)
    {
        printf("no existe un servicio de esa fecha\n");
    }


}

void trabajosPorBici(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eCliente client[],int tamCli)
{

    int index;
    int id;

    system("cls");

    printf("\nIngrese ID: ");

    scanf("%d",&id);

    index=findBikeById(id,bicicletas,tamBici);

    if(index==-1)
    {
        printf("\nNo hay registro de una bicicleta con el id: %d",id);
    }
    else
    {
        printf("  *** Listado de trabajos ***\n\n");
        printf("\nTRABAJO    BICICLETA      MARCA   CLIENTE     SERVICIO       PRECIO       FECHA\n");
        for(int i=0; i<tamTra; i++)
        {
            if(trabajo[i].idBicicleta==id && trabajo[i].isEmpty==0)
            {
                mostrarTrabajoInforme(trabajo[i],bicicletas[i],servicio,tamSer,client,tamCli);

            }


        }

    }


}

void serviciosTotales(eBicicleta bici[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[], int tamser,eCliente client[],int tamCli)
{
    int index;
    int id;
    float precioTotal=0;
    int contador=0;

    system("cls");

    printf("\nIngrese ID: ");

    scanf("%d",&id);

    index=findBikeById(id,bici,tamBici);

    if(index==-1)
    {
        printf("\nNo hay registro de una bicicleta con el id: %d",id);
    }
    else
    {
        printf("\nTRABAJO    BICICLETA      MARCA   CLIENTE     SERVICIO       PRECIO       FECHA\n");
        for(int i=0; i<tamTra; i++)
        {
            if(trabajo[i].idBicicleta==id  && trabajo[i].isEmpty==0 )
            {

                //if(trabajo[i].idBicicleta==id && trabajo[i].isEmpty==1)
                //{
                    mostrarTrabajoInforme(trabajo[i],bici[index],servicio,tamser,client,tamCli);

               // }


                for(int j=0; j<tamser; j++)
                {
                    if(servicio[j].id== trabajo[i].idServicio)
                    {
                        contador++;
                        precioTotal += servicio[j].precio;

                    }

                }



            }

        }

        printf("\nel precio total de los servicios es de: %.2f\n",precioTotal);
    }
}

void printBikeColor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp)
{
    system("cls");
    int i;
    int auxColor;
    int flag=0;
    printf("\n100.Gris");
    printf("\n101.Negro");
    printf("\n102.Blanco");
    printf("\n103.Azul");
    printf("\n104.Rojo");
    getValidInt("\nIngrese numero: ","\nError dato no valido",100,104,&auxColor);
    printf("ID      MARCA     RODADO     TIPO     COLOR\n");
    for(i=0; i<tamBici; i++)
    {
        if(bici[i].idColor==auxColor)
        {
            printBike(bici[i],tipo,tamTipo,color,tamCol,client,tamCli,empl,tamEmp);
            flag=1;
        }
    }

    if(flag==0)
    {

        printf("ninguna bici tiene este color");
    }
}
void printBikeTipo(eBicicleta bici[],int tamBici,eColor color[],int tamCol,eTipo tipo[],int tamTip,eCliente cliente[],int tamCli,eEmpleado empl[], int tamEmp)
{
    system("cls");
    int i;
    int auxTipo;
    printf("\n10.Rutera");
    printf("\n11.Carrera");
    printf("\n12.Mountain");
    printf("\n13.BMX");
    getValidInt("\nIngrese numero: ","\nError dato no valido",10,13,&auxTipo);
    printf("ID      MARCA     RODADO     TIPO     COLOR\n");
    for(i=0; i<tamBici; i++)
    {
        if(bici[i].idTipo==auxTipo)
        {
            printBike(bici[i],tipo,tamTip,color,tamCol,cliente,tamCli,empl,tamEmp);
        }
    }
}
void printBikeRodado(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp)
{

    for(int i=0; i<tamBici; i++)
    {
        if(bici[i].rodado==20)
        {
            printBike(bici[i],tipo,tamTipo,color,tamCol,client,tamCli,empl,tamEmp);
        }
    }

}

void printBikeRodadoMayor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp)
{

    for(int i=0; i<tamBici; i++)
    {
        if(bici[i].rodado==29)
        {
            printBike(bici[i],tipo,tamTipo,color,tamCol,client,tamCli,empl,tamEmp);
        }
    }

}


void sortbikeTipo(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp)
{
    eBicicleta auxBicicleta;
    int i;
    for(i=0; i<tamBici-1; i++)
    {
        for(int j=i+1; j<tamBici; j++)
        {
            if(bici[i].isEmpty==0)
            {

                if(bici[i].idTipo>bici[j].idTipo)
                {
                    auxBicicleta=bici[i];
                    bici[i]=bici[j];
                    bici[j]=auxBicicleta;
                }
            }
        }
    }
    printBikes(bici,tamBici,tipo,tamTipo,color,tamCol,client,tamCli,empl,tamEmp);
}

void contadorBike(eBicicleta bici[],int tamBici,eTipo tipo[],int tamTip,eColor color[],int tamCol)

{
    system("cls");
    char descriptionTipo[20];
    char descriptionColor[20];
    int contadorColor=0;
    int contadorTipo=0;
    int i;
    int auxTipo;
    printf("\n10.Rutera");
    printf("\n11.Carrera");
    printf("\n12.Mountain");
    printf("\n13.BMX");
    getValidInt("\nIngrese numero: ","\nError dato no valido",10,13,&auxTipo);

    for(i=0; i<tamBici; i++)
    {
        if(bici[i].idTipo==auxTipo)
        {
            contadorTipo++;
        }
    }
    int auxColor;
    printf("\n100.Gris");
    printf("\n101.Negro");
    printf("\n102.Blanco");
    printf("\n103.Azul");
    printf("\n104.Rojo");
    getValidInt("\nIngrese numero: ","\nError dato no valido",100,104,&auxColor);

    for(i=0; i<tamBici; i++)
    {
        if(bici[i].idColor==auxColor)
        {
            contadorColor ++;
        }
    }

    loadDescriptionTipo(descriptionTipo,auxTipo,tipo,tamTip);
    loadDescriptionColor(descriptionColor,auxColor,color,tamCol);


    printf("\nCantidad de bicis del color: %s  %d",descriptionColor,contadorColor);
    printf("\nCantidad de bicis del Tipo: %s   %d\n",descriptionTipo,contadorTipo);

}
void printMayorColor(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eMayorColor listaColorMayor[])
{
    system("cls");

	int counter;
	int indexColorMayor = 0;
	int flag = 0;
	eMayorColor auxColorMayor;
	char descripcionColor[20];
	int i;

	for(int i=0; i<tamCol; i++)//recorro colores
	{
		counter = 0;

		for(int j=0; j<tamBici; j++)//recorro motos
		{
			if(bici[j].isEmpty == 0 && bici[j].idColor == color[i].id)//si la moto tiene el id de ese color
			{
				counter++;//se cuenta como una vez que eligieron una moto de ese color
			}
		}

		listaColorMayor[indexColorMayor].id = color[i].id;  //en ese elemento de la lista va a quedar guardado color: tal, veces que lo eligieron: tal
		listaColorMayor[indexColorMayor].cantidad = counter;
		listaColorMayor[indexColorMayor].isEmpty = 1;

		indexColorMayor++; //ya se setearon los datos de un color, asi que se pasa al elemento siguiente de la lista para guardar los de otro
		//el contador vuelve a 0 para contar las veces que eligieron al color que sigue

	}

	for(int i=0; i<tamCol; i++)
	{
		if(flag == 0)
		{
			auxColorMayor = listaColorMayor[i]; //en la posicion 0 auxColorMayor va a tener cargado el color mas elegido
			flag = 1;
		}
		else if(listaColorMayor[i].cantidad > auxColorMayor.cantidad && listaColorMayor[i].isEmpty == 1)
		{
			auxColorMayor = listaColorMayor[i];//cuando termina el for auxColorMayor va a tener cargado el color mas elegido
		}
	}

     printf("Los Colores mas pedidos son\n\n");

	 printf("ID   COLOR \n");

	for( i=0; i<tamCol; i++)
	{
		if(auxColorMayor.cantidad == listaColorMayor[i].cantidad && listaColorMayor[i].isEmpty == 1)
		{

            loadDescriptionColor(descripcionColor,listaColorMayor[i].id,color,tamCol);
	        printf("%d  %5s\n",listaColorMayor[i].id,descripcionColor);
		}
	}

}

void serviciosPorBici(eBicicleta bicicletas[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamSer,eCliente client[],int tamCli)
{

    int index;
    int auxIdServicio;
    int existeServicio=-1;
    int j;

    for(int i=0; i<tamSer; i++)
    {
        printf("\nServicio: %d",servicio[i].id);
    }

    getValidInt("\nIngrese el id del servicio: ","Servicio Incorrecto",1000,1003,&auxIdServicio);


    printf("\nTRABAJO    BICICLETA      MARCA   CLIENTE     SERVICIO       PRECIO       FECHA\n");
    for( j=0; j < tamTra; j++)
    {

        if(auxIdServicio==trabajo[j].idServicio && trabajo[j].isEmpty==0)
        {
            index=findBikeById(trabajo[j].idBicicleta,bicicletas,tamBici);
            mostrarTrabajoInforme(trabajo[j],bicicletas[index],servicio,tamSer,client,tamCli);
            existeServicio=0;
        }
    }

    if(existeServicio==-1)
    {
        printf("NINGUNA BICI TIENE ESTE SERVICIO");
    }


}

void findSalaryMax(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp)
{
    float averageSalary=0;
    int overAverageCounter=0;
    float totalSalary=0;
    int employeeQuantity=0;
    int i;
    int flag=0;

    for(i=0; i<tamEmp; i++)
    {

            totalSalary = empl[i].salario + totalSalary;

            employeeQuantity++;

            flag=1;
    }

    if(flag==1)
    {
        averageSalary=totalSalary/employeeQuantity;

        for(i=0; i<tamEmp; i++)
        {
            if(empl[i].salario>averageSalary)
            {
                overAverageCounter++;
            }
        }
    }


    printf("\nEl total de los salarios es: %.3f\n",totalSalary);
    printf("El promedio de los salarios es: %.3f\n",averageSalary);
    printf("La cantidad de empleados que superan el promedio es: %d\n", overAverageCounter);

}


int sortBicisInsercion(eBicicleta bici[],int tamBici,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp)
{
    eBicicleta auxbici;
    int j;
    int retorno=-1;

    for(int i=1; i<tamBici; i++)
    {
        auxbici = bici[i];
        j=i-1;

        while(strcmp(bici[j].marca, auxbici.marca)>0 && j>=0)
        {
            bici[j+1] = bici[j];
            j--;
        }
        bici[j+1]=auxbici;
    }
    system("cls");
    printf("ORDENADOS ASCENDENTEMENTE\n\n");

    printBikes(bici,tamBici,tipo,tamTipo,color,tamCol,client,tamCli,empl,tamEmp);
    retorno=0;

    return retorno;
}


void biciMasVieja (eBicicleta bici[],int tamBici,eTrabajo trabajo[],int tamTra,eServicio servicio[],int tamser ,eColor color[],int tamCol, eTipo tipo[],int tamTipo,eCliente client[],int tamCli,eEmpleado empl[], int tamEmp)
{
    int i;
    int j;
    int masVieja = 2020;
    int index;

    printf("el trabajo /s bici/s mas viejo/s es/son: \n");
    for(i=0; i<tamTra; i++)
    {
        if(trabajo[i].fecha.anio < masVieja && trabajo[i].isEmpty == 0)
        {
            masVieja=trabajo[i].fecha.anio;
        }

    }
    for(j=0; j<tamTra; j++)
    {
        if(trabajo[j].fecha.anio == masVieja)
        {
            index=findBikeById(trabajo[j].idBicicleta,bici,tamBici);
            mostrarTrabajoInforme(trabajo[j],bici[index],servicio,tamser,client,tamCli);
        }
    }
}
