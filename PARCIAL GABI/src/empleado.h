#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct
{
    int id;
    char nombre[50];
    char tipo[50];
    int tiempo;

} eBici;

eBici* eBici_new();

eBici* empleado_nuevosParametros(char idAux[50],char nombreAux[50],char tipoAux[50],char tiempo[50]);


int eBici_get_nombre  (eBici* ptrPais,char* this);
int eBici_set_nombre (eBici* ptrPais,char* this);

int eBici_get_tipo  (eBici* ptrPais,char* this);
int eBici_set_tipo (eBici* ptrPais,char* this);

int eBici_get_id (eBici* ptrPais,int* this);
int eBici_set_id (eBici* ptrPais,int this);

int eBici_get_tiempo(eBici* ptrPais,int* this);
int eBici_set_tiempo(eBici* ptrPais,int this);

//int employee_sortPorNombre(void* employeeA,void* employeeB);
//int employee_sortPorInfectados(void* employeeA, void* employeeB);


int employee_mapeo(void* persona);

int funcionCriterio(void* persona);
int funcionCriterioDos(void* persona);
int funcionCriterioTres(void*persona);

int filtrarbmx(void*persona);

int filtrarplayera(void*persona);

int filtrarmtb(void*persona);

int filtrarpaseo(void*persona);



#endif // EMPLEADO_H_INCLUDED
