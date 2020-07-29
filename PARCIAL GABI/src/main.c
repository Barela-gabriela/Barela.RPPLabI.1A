#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "menu.h"
#include <time.h>
#include "empleado.h"

int main()
{
    int opcion;
    int flag1 = 0;
    LinkedList* listaBici = ll_newLinkedList();
    do
    {
        opcion = pedirOpcionMenu();
        switch(opcion)
        {
        case 1:
            if(flag1 == 0)
            {
            controller_loadFromText("bicicletas.csv",listaBici);
            flag1 = 1;
            break;
            }
            else{
                printf("Ya ha cargado los datos\n");
                system("pause");
                system("cls");
            }
        case 2:
            controller_ListEmployee(listaBici);
            printf("\n");
            break;
        case 3:
            controller_mapEmployee(listaBici);
            controller_ListEmployee(listaBici);
            break;
        case 4:
            controller_fil(listaBici);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            printf("opcion invalida\n");
            break;

        }
        fflush(stdin);
        system("pause");
        system("cls");
    }
    while(opcion != 7);
    return 0;
}
