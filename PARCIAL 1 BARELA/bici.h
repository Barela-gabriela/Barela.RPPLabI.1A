#ifndef BICI_H_INCLUDED
#define BICI_H_INCLUDED
typedef struct
{
   int id;
   char descripcion[20];
   float salario;
}eEmpleado;
typedef struct
{
    int id;
    char marca[20];///nombre
    float rodado;///sueldo
    int isEmpty;
    int idTipo;
    int idColor;
    int idServicio;
    int idCliente;
    int idEmpleado;
}eBicicleta;
typedef struct
{
    int id;
    char sexo;
    char nombre[20];
}eCliente;
typedef struct
{
   int id;
   char descripcion[20];
}eTipo;
typedef struct
{
   int id;
   char descripcion[20];
}eColor;
typedef struct
{
   int id;
   char descripcion[20];
   float precio;
}eServicio;

int askMenuOption();
void printBike(eBicicleta x, eTipo tipos[], int tamTip,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp);
void printColores(eColor color[], int tamCol);
void printTipos(eTipo tipos[], int tamTip);
void printServicios(eServicio servicio[],int tamSer);
void printEmpl(eEmpleado empl[], int tamEmp);

void printBikes(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTip,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp);

void loadDescription(char descripcionTipo[],char descripcionColor[],char descripcionNombre[],char descripcionEmp[],int idTip,eTipo tipos[],int tamTip,int idCol,eColor color[],int tamCol,int idCli,eCliente client[],int tamCli, char* sexo,int idEmpl,eEmpleado empl[]
                     ,int tamEmp,float* salario);

void loadDescriptionTipo(char descripcionTipo[],int idTip,eTipo tipos[],int tamTip);
void loadDescriptionColor(char descripcionColor[],int idCol,eColor color[],int tamCol);
void loadDescriptionEmpl(char descripcionEmp[],int idEmp,eEmpleado empl[],int tamEmp);
void initBikes(eBicicleta bicicletas[],int tam);
int findFreespace(eBicicleta bicicletas[],int tam);
int findBikeById(int id, eBicicleta bicicletas[],int tam);
int generarNextId();
void hardcodeoBike(eBicicleta bicicleta[]);
void hardcodeoCliente(eCliente cliente[]);
void hardcodeoempleado(eEmpleado empl[]);

int addBikes(eBicicleta bicicletas[],int tam,eTipo tipos[],int tamTip,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp);

void removeBikes(eBicicleta bicicletas[], int tam,eTipo tipos[], int tamTipe,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp);

void modifyBike(eBicicleta bicicletas[],int tam, eTipo tipos[], int tamTip,eColor color[],int tamCol,eCliente client[],int tamCli,eEmpleado empl[],int tamEmp);
void sortBike(eBicicleta bicicleta[],int tam,eTipo tipo[],int tamTip);



#endif // BICI_H_INCLUDED
