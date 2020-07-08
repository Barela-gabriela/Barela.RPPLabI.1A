#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define TAMTIP 4
#define TAMBICI 30
#define TAMCOL 5
#define TAMSER 4
#define TAMTRA 20
#define TAMCLI 30
#include "utn.h"
#include "trabajo.h"
#include "bici.h"
int main()
{
    ///TAREA
    /// 12 informes

    char confirm;
    char seguir='s';
    eCliente client[TAMCLI]={{11,'f',"carlos"},{12,'m',"pepito"},{13,'f',"tomas"},{14,'m',"franco"},{15,'f',"zeus"}};
    eBicicleta bicicletas[TAMBICI];
    eTrabajo trabajo[TAMTRA];
    eTipo tipos[TAMTIP]= {{10,"rutera"},{11,"Carerra"},{12,"mountain"},{13,"BMX"}};
    eColor color[TAMCOL]= {{100,"gris"},{101,"negro"},{102,"blaco"},{103,"azul"},{104,"rojo"}};
    eServicio servicio[TAMSER]= {{1000,"Limpieza",250},{1001,"Parche",300},{1002,"Centrado",400},{1003,"Cadena",350}};
    initBikes(bicicletas,TAMBICI);
    inicializarTrabajo(trabajo,TAMTRA);
    int flagOne=0;///para validar personas cargadas
    int flagTwo=0;
    do
    {
        switch(askMenuOption())
        {
        case 1:
            printf("\t\tAlta");
            if(addBikes(bicicletas,TAMBICI,tipos,TAMTIP,color,TAMCOL,client,TAMCLI))
            {
                printf("alta exitosa\n");
                flagOne=1;
            }
            break;
        case 2:
            if(flagOne==1)/// (==)COMPARA(es igual?)
            {
                modifyBike(bicicletas,TAMBICI,tipos,TAMTIP,color,TAMCOL,client,TAMCLI);
            }else
            {
                printf("\n\nNo hay datos cargados");
            }
            break;
        case 3:
            if(flagOne==1)
            {
              removeBikes(bicicletas,TAMBICI,tipos,TAMTIP,color,TAMCOL,client,TAMCLI);
            }else
            {
                printf("\n\nNo hay datos cargados");
            }

            break;
        case 4:
            printf("\nListado de bicicletas\n");
            if(flagOne==1)
            {
                sortBike(bicicletas,TAMBICI,tipos,TAMTIP);
                printBikes(bicicletas,TAMBICI,tipos,TAMTIP,color,TAMCOL,client,TAMCLI);
            }else
            {
                printf("\n\nNo hay datos cargados");
            }
            break;
        case 5:
            printColores(color,TAMCOL);
            break;
        case 6:
            printTipos(tipos,TAMTIP);
            break;
        case 7:
            printServicios(servicio,TAMSER);
            break;
        case 8:
            if(flagOne==1)
            {
                 menuTrabajo(trabajo,TAMTRA,bicicletas,TAMBICI,servicio,TAMSER);
            }else
            {
                printf("\n\nNo hay datos cargados");
            }

            break;
        case 9:
           if(flagOne==1)
            {
                menuInformes(bicicletas,TAMBICI,trabajo,TAMTRA,servicio, TAMSER,color,TAMCOL,tipos,TAMTIP,client,TAMCLI);
            }else
            {
                printf("\n\nNo hay datos cargados");
            }
            break;
        case 10:
            if(flagTwo==0)
            {
            hardcodeoCliente(client);
            hardcodeoBike(bicicletas);
            hardcodeoTrabajo(trabajo);
            flagTwo=1;
            flagOne=1;
            }

            break;
        case 11:
            printf("\nConfirma salida?(s/n)\t");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm=='s')
            {
                seguir='n';
            }
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(seguir=='s');
    return 0;
}
