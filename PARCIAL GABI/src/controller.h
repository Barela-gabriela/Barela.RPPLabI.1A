#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);

int controller_sortEmployee(LinkedList* pArrayListEmployee);

int controller_mapEmployee(LinkedList* pArrayListEmployee);

int controller_ListEmployeeDedic(LinkedList* pArrayListEmployee);

int controller_saveAsText(char* path, LinkedList* pArrayLista);

int controller_ListEmployee(LinkedList* pArrayListEmployee);

//LinkedList* controller_mayor(LinkedList* pArrayListEmployee);
void controller_fil(LinkedList* parray);
int controller_sortEmployeeI(LinkedList* pArrayListEmployee);
#endif // CONTROLLER_H_INCLUDED
