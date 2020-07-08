#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bici.h"
#include "utn.h"
#include "informes.h"
int askMenuOption()
{
    int option;
    printf("\t ******MENU DE OPERACIONES******\n\t");
    printf("\n1.Alta");
    printf("\n2.Modificar");
    printf("\n3.Baja bicicleta");
    printf("\n4.Listar bicicletas");
    printf("\n5.Listar colores");
    printf("\n6.Listar tipos");
    printf("\n7.Listar servicios");
    printf("\n8.Trabajos");
    printf("\n9.Informes");
    printf("\n10.Harcodeo");
    printf("\n11.Salir\n\n");
    scanf("%d", &option);

    fflush(stdin);
    system("pause");
    system("cls");

    return option;
}
void printBike(eBicicleta x, eTipo tipos[], int tamTip,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp)
{
    char descriptionTipo[20];
    char descriptionColor[20];
    char descripcionNombre[20];
    char descripcionEmpl[20];
    char sexo;
    float salario;

    loadDescription(descriptionTipo,descriptionColor,descripcionNombre,descripcionEmpl,x.idTipo,tipos,tamTip,x.idColor,color,tamCol,x.idCliente,client,tamCli,&sexo,x.idEmpleado,empl,tamEmp,&salario);

    printf("%d   %8s    %8s %4c   %10.2f   %10s  %10s  %10s %5.2f\n",x.id,x.marca,descripcionNombre,sexo,x.rodado,descriptionTipo,descriptionColor,descripcionEmpl,salario);

}
void printEmpl(eEmpleado empl[], int tamEmp)
{
    int i;
    system("cls");
    printf("\tLista de Empleados\n\n");
    printf("ID  EMPLEADO\n");

    for(i=0; i<tamEmp; i++)
    {
       printf("%d %2s\n",empl[i].id,empl[i].descripcion);
    }

}

void printTipos(eTipo tipos[], int tamTip)
{
    int i;
    system("cls");
    printf("\tLista de bicicletas\n\n");
    printf("ID  TIPO\n");

    for(i=0; i<tamTip; i++)
    {
       printf("%d %2s\n",tipos[i].id,tipos[i].descripcion);
    }


}

void printColores(eColor color[], int tamCol)
{
    int i;
    system("cls");
    printf("\tLista de bicicletas\n\n");
    printf("ID  COLOR \n");

    for(i=0; i<tamCol; i++)
    {
        printf("%d %2s\n",color[i].id,color[i].descripcion);
    }


}

void printServicios(eServicio servicio[],int tamSer)
{
    int i;
    system("cls");
    printf("\tLista de servicios\n\n");
    printf("ID  SERVICIO     PRECIO\n");

    for(i=0; i<tamSer; i++)
    {
        printf("%d %10s %.1f\n",servicio[i].id,servicio[i].descripcion,servicio[i].precio);
    }

}

void printBikes(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTip,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp)
{
    int i;
    system("cls");
    printf("\tLista de bicicletas\n\n");
    printf("ID      MARCA        CLIENTES    SEXO    RODADOS      TIPO       COLOR  EMPLEADO   SALARIO\n");

    for(i=0; i<tam; i++)
    {
        if(bicicletas[i].isEmpty==0)
        {
            printBike(bicicletas[i],tipos,tamTip,color,tamCol,client,tamCli,empl,tamEmp);
        }
    }


}
void loadDescription(char descripcionTipo[],char descripcionColor[],char descripcionNombre[],char descripcionEmp[],int idTip,eTipo tipos[],int tamTip,int idCol,eColor color[],int tamCol,int idCli,eCliente client[],int tamCli, char* sexo,int idEmpl,eEmpleado empl[],int tamEmp,float* salario)
{
    int i;
    for(i=0; i<tamEmp; i++) ///recorro empl
    {
        if(empl[i].id==idEmpl)///busco el id de empl
        {

            strcpy(descripcionEmp,empl[i].descripcion);
            *salario=empl[i].salario;
        }
    }

    for(i=0; i<tamTip; i++) ///recorro secotres
    {
        if(tipos[i].id==idTip)///busco el id de sectores
        {
            strcpy(descripcionTipo,tipos[i].descripcion);///copio la descripcion a l parametro

        }
    }
    for(i=0; i<tamCol; i++) ///recorro secotres
    {
        if(color[i].id==idCol)///busco el id de sectores
        {

            strcpy(descripcionColor,color[i].descripcion);
        }
    }
    for(i=0; i<tamCli;i++)
    {
        if(client[i].id==idCli)///busco el id de sectores
        {
            strcpy(descripcionNombre,client[i].nombre);
            *sexo = client[i].sexo;
        }
    }
}
void loadDescriptionEmpl(char descripcionEmp[],int idEmp,eEmpleado empl[],int tamEmp)
{
    int i;

    for(i=0; i<tamEmp; i++) ///recorro emp
    {
        if(empl[i].id==idEmp)///busco el id
        {
            strcpy(descripcionEmp,empl[i].descripcion);///copio la descripcion a l parametro

        }
    }
}
void loadDescriptionTipo(char descripcionTipo[],int idTip,eTipo tipos[],int tamTip)
{
    int i;

    for(i=0; i<tamTip; i++) ///recorro secotres
    {
        if(tipos[i].id==idTip)///busco el id de sectores
        {
            strcpy(descripcionTipo,tipos[i].descripcion);///copio la descripcion a l parametro

        }
    }
}
void loadDescriptionColor(char descripcionColor[],int idCol,eColor color[],int tamCol)
{
    int i;
    for(i=0; i<tamCol; i++) ///recorro secotres
    {
        if(color[i].id==idCol)///busco el id de sectores
        {
            ///copio la descripcion a l parametro
            strcpy(descripcionColor,color[i].descripcion);
        }
    }
}

void initBikes(eBicicleta bicicletas[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        bicicletas[i].isEmpty=1;///si esta vacio 1=verdadero 0=flaso
    }
}
int findFreespace(eBicicleta bicicletas[],int tam)
{
    int index=-1;///asi empieza desde 0
    int i;
    for(i=0; i<tam; i++)
    {
        if(bicicletas[i].isEmpty==1)///si esta abierto detecta el lugar vacio
        {
            index=i;
            break;
        }
    }
    return index;
}
int findBikeById(int id, eBicicleta bicicletas[],int tam)
{
    int index=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(bicicletas[i].id==id && bicicletas[i].isEmpty==0)///detecta si existe el alumno por id
        {
            index=i;
            break;
        }
    }
    return index;

}
int addBikes(eBicicleta bicicletas[],int tam,eTipo tipos[],int tamTip,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp)
{

    eBicicleta auxBicicletas;
    int auxCliente;
    int retorno=-1;
    float numero;
    int index=findFreespace(bicicletas,tam);///devuelve el indice -1
    char auxMarca[20];
    int auxColor;
    int auxTipo;
    int auxEmpl;
    //int exist;///aca guardo el id

    system("cls");
    printf("\nAlta Bicis");
    if(index==-1)///hay lugar?
    {
        printf("\nSistema Completao\n");
    }
    else
    {

        auxBicicletas.id=generarNextId();

        fflush(stdin);
        getValidString("\nIngrese Marca: ","\nError ingrese solo caracteres","\nError se exedio del limite de caracteres\n",auxMarca,1,19);
        strcpy(auxBicicletas.marca,auxMarca);


        printf("\nSelecciona el cliente <1-10>: ");
        for(int i=0; i<1; i++)
        {
            printf("\n 1.Patricio");
            printf("\n 2.BoB");
            printf("\n 3.Tomas");
            printf("\n 4.Elvis");
            printf("\n 5.Carla");
            printf("\n 6.Lucia");
            printf("\n 7.Merida");
            printf("\n 8.Manuel");
            printf("\n 9.Lautaro");
            printf("\n 10.Leonel");

        }
        fflush(stdin);
        getValidInt("\nIngrese numero: ","\nError dato no valido solo clientes validos <1-10>",1,10,&auxCliente);
        auxBicicletas.idCliente=auxCliente;

        printf("\nSelecciona el Empleado <10000-10002>: ");
        for(int i=0; i<1; i++)
        {
            printf("\n 10000.Javier");
            printf("\n 10001.Cristina");
            printf("\n 10002.Pancho");

        }
        fflush(stdin);
        getValidInt("\nIngrese numero: ","\nError dato no valido solo clientes validos <10000-10002>",10000,10001,&auxEmpl);
        auxBicicletas.idEmpleado=auxEmpl;

        printf("\nSelecciona el color: ");
        for(int i=0; i<1; i++)
        {
            printf("\n100.Gris");
            printf("\n101.Negro");
            printf("\n102.Blanco");
            printf("\n103.Azul");
            printf("\n104.Rojo");
        }
        fflush(stdin);
        getValidInt("\nIngrese numero: ","\nError dato no valido",100,104,&auxColor);
        auxBicicletas.idColor=auxColor;


        printf("\nSelecciona el tipo: ");
        for(int i=0; i<1; i++)
        {
            printf("\n10.Rutera");
            printf("\n11.Carrera");
            printf("\n12.Mountain");
            printf("\n13.BMX");
        }

        fflush(stdin);
        getValidInt("\nIngrese numero: ","\nError dato no valido",10,13,&auxTipo);
        auxBicicletas.idTipo=auxTipo;


        printf("\n1. 20\n2. 26\n3. 27.5\n4. 29\n");
        printf("\nIngrese rodado: (NUMERO DEL RODADO)\n");
        scanf("%f",&numero);
        if(numero==20|| numero==26||numero==27.5||numero==29)
        {
            auxBicicletas.rodado=numero;
            auxBicicletas.isEmpty=0;
            bicicletas[index]=auxBicicletas;
            retorno=1;
            system("cls");

            printBike(bicicletas[index],tipos,tamTip,color,tamCol,client,tamCli,empl,tamEmp);
        }
        else
        {
            printf("\nRodado invalido\n");
        }
        ///copio vector con empleado nuevo
    }
    return retorno;
}
void removeBikes(eBicicleta bicicletas[], int tam,eTipo tipos[], int tamTip,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp)
{
    int index;
    int id;
    char confirm;
    system("cls");

    printf("Baja bicicletas");
    printf("\nIngrese ID");

    scanf("%d",&id);

    index=findBikeById(id,bicicletas,tam);

    if(index==-1)
    {
        printf("\nNo hay registro de una bicicleta con el id: %d",id);
    }
    else
    {
        printBike(bicicletas[index],tipos,tamTip,color,tamCol,client,tamCli,empl,tamEmp);
        printf("\nConfirma Baja?(s/n)");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm== 's')
        {
            bicicletas[index].isEmpty=1;
            printf("\nSe a realizado la baja con exito");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
}
void modifyBike(eBicicleta bicicletas[],int tam, eTipo tipos[], int tamTip,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp)
{
    int options;
    int id;
    int index;
    char confirm;
    float newrodado;
    int newtipo;
    printf("Modificar empleados");
    printf("\nIngrese Id:");
    scanf("%d",&id);

    index =findBikeById(id,bicicletas,tam);

    if(index==-1)
    {
        printf("\nNo hay registro de un bicicleta con el id: %d",id);
    }
    else
    {
        printBike(bicicletas[index],tipos,tamTip,color,tamCol,client,tamCli,empl,tamEmp);

        printf("\nModificar bicicleta?(s/n)");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm== 's')
        {
            printf("\nQue desa modificar?");
            printf("\n1.rodado");
            printf("\n2.tipo");
            scanf("%d",&options);
            switch(options)
            {

            case 1:
                printf("\n1. 20\n2. 26\n3. 27.5\n4. 29\n");
                printf("\nIngrese nuevo rodado: ");
                scanf("%f",&newrodado);
                if(newrodado==20|| newrodado==26||newrodado==27.5||newrodado==29)
                {
                    bicicletas[index].rodado=newrodado;
                }
                else
                {
                    printf("\nRodado invalido\n");
                }
                break;
            case 2:
                printf("\nSeleccione nuevo tipo");
                printf("\nSelecciona el tipo: ");
                for(int i=0; i<1; i++)
                {
                    printf("\n10.Rutera");
                    printf("\n11.Carrera");
                    printf("\n12.Mountain");
                    printf("\n13.BMX");
                }

                scanf("%d",&newtipo);
                bicicletas[index].idTipo=newtipo;
                break;
            }

            printf("\nSe a realizado la modificacion con exito");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
}
void sortBike(eBicicleta bicicleta[],int tam,eTipo tipo[],int tamTip)
{
    eBicicleta auxBicicleta;
    int i;
    for(i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(bicicleta[i].isEmpty==0)
            {
                if(strcmp(bicicleta[i].marca,bicicleta[j].marca)>0 )
                {
                    auxBicicleta=bicicleta[i];
                    bicicleta[i]=bicicleta[j];
                    bicicleta[j]=auxBicicleta;
                }
                else  if(strcmp(bicicleta[i].marca,bicicleta[j].marca)==0 && bicicleta[i].idTipo==bicicleta[j].idTipo)
                {
                    auxBicicleta=bicicleta[i];
                    bicicleta[i]=bicicleta[j];
                    bicicleta[j]=auxBicicleta;
                }
            }
        }
    }
}
void hardcodeoBike(eBicicleta bicicleta[])
{
    char marcaa[10][31]= {"mc","bk","reff","lego ","man","italia","fram","wms","xx ","yyy"};
    int idClientee[10]={1,2,3,4,5,6,7,8,9,10};
    int idEmpleado[10]={10000,10000,10001,10002,10001,10001,10002,10002,10000,10001};
    int idTipoo[10]= {10,11,12,13,10,11,12,13,10,11};
    int idColoor[10]= {101,102,103,104,101,102,103,102,101,102};
    int rodadoss[10]= {20,26,27.5,29,20,26,27.5,29,20,26};

    for(int i=0; i<10; i++)
    {
        bicicleta[i].id= generarNextId();

        bicicleta[i].idCliente=idClientee[i];

        strcpy(bicicleta[i].marca, marcaa[i]);

        bicicleta[i].idTipo=idTipoo[i];

        bicicleta[i].idColor=idColoor[i];

        bicicleta[i].idEmpleado=idEmpleado[i];

        bicicleta[i].rodado=rodadoss[i];

        bicicleta[i].isEmpty=0;
    }
}
void hardcodeoCliente(eCliente cliente[])
{
    char nombreCliente[10][20]={"Patricio","BoB","Tomas","Elvis","Carla","Lucia","Merida","Manuel","Lautaro","Leonel"};
    int idClientee [10]={1,2,3,4,5,6,7,8,9,10};
    char sexoCliente[10] ={'m','m','m','m','f','f','f','m','m','m'};
    for (int i=0;i<10;i++)
    {
        cliente[i].id=idClientee[i];
        strcpy(cliente[i].nombre,nombreCliente[i]);
        cliente[i].sexo=sexoCliente[i];
    }

}
int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}
