#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

//El resto de las funciones se encuentran documentadas en LinkedList.h

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor o igual al len de la lista)
 *                   (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                    ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);




LinkedList* ll_newLinkedList(void)
{
    LinkedList* newList;///declaro un puntero
    newList=(LinkedList*)malloc(sizeof(LinkedList));///asigno memoria dinamica a la likend list
    if(newList !=NULL)///pregunt si le asigno el espacio en memoria
    {
        newList->size=0;///seteo sizeen 0 porque no posee vagones/nodos
        newList->pFirstNode=NULL;///seteo el primer nodo en null ya que no posee un primer nodo
    }
    return newList;
}

int ll_len(LinkedList* this)
{
    int cant = -1;
    if(this!=NULL)///pregunto si la linkes es nula
    {
        cant= this->size;///guardo el tam de la linkedlist
    }
    return cant;
}


static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo = NULL;///declaro un puntero a nodo auxiliar
    if(this !=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))///pregunto si la linked list es nula, si el indice pasado sea mayor o igual a 0 y si el indice es menor a tamaño de la linked list
    {
        nodo=this->pFirstNode;///guardo el puentero en el primer lugar/nodo de la linked list
        while(nodeIndex>0)
        {
            nodo=nodo->pNextNode;///el puntero pasa al siguiente lugar de la linked list
            nodeIndex--;
        }
    }
    return nodo;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode=NULL;///asigno puntero
    Node*anterior=NULL;///asigno puntero
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))///pregunto si la linkedlist es nula y que el indice se encuentre dentro del rango
    {
        newNode=(Node*)malloc(sizeof(Node));
        if(newNode!=0)
        {
            newNode->pElement=pElement;///se agrega al nodo al que apunte
            newNode->pNextNode=NULL;///porque no tien nodo siguiente
            if(nodeIndex==0)
            {
                newNode->pNextNode=this->pFirstNode;
                this->pFirstNode=newNode;
            }
            else
            {
                anterior=getNode(this,nodeIndex-1);///se posisiona en el nodo anterior
                newNode->pNextNode = anterior->pNextNode;
                anterior->pNextNode=newNode;///el anterior nodo pasa a apuntar al nuevo nodo
            }
            this->size++;///aumento el tamaño de la lista
            returnAux=0;
        }
    }
    return returnAux;
}



int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}



int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this!=NULL)///verifico que el parametro no sea nulo
    {
        addNode(this,ll_len(this),pElement);///le agrego la fun addnode con el ultimo index para que se agregue al final
        returnAux=0;
    }

    return returnAux;
}



void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;///declaro un puntero a nodo aux

    if (this != NULL && index>=0 && index<ll_len(this))///pregunto si la  lista es nula y que el index este en el rango de la lista
    {
        pNode = getNode(this, index);///pido un nodo con otra funcion y le paso el index
        returnAux = pNode->pElement;///guardo en el return el elemento del nodo
    }

    return returnAux;
}


int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node*pNode=NULL;///puntero a nodoaux
    if(this!=NULL && index<ll_len(this)&& index>=0)///verifico que este pasando en el rango de la lista
    {
        pNode = getNode(this, index);///llamo a un nodo con getnode
        pNode->pElement = pElement;///cambio el elemento del nodo que llame
        returnAux = 0;
    }
    return returnAux;
}



int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;///declaro un puntero a nodo auxiliar
    Node* pLeftNode = NULL;///declaro un puntero al nodo anterior al que voy a eliminar

    if (this != NULL && index >= 0 && index < ll_len(this))///pregunto que lista pasada no sea nula y que el indice se encuentre en el rango de la linkedlist
    {
        if (index == 0)///si el indice es 0
        {
            pNode = this->pFirstNode;///pnode pasa a apuntar a la direccion de memoria del primer nodo
            this->pFirstNode = pNode->pNextNode;///el primer nodo pasa a apuntar a la direccion de memoria del que sigue al nodo
    ///que tome
        }
        else if (index>=0 && index<ll_len(this))///si el indice es mayor a 0 y menor al size del linked list
        {
            pNode = getNode(this, index);///punteero a node toma la direccion de memoria del nodo del indice pasado
            pLeftNode = getNode(this, index-1);///pido la direccion de memoria del nodo a su izquierda
            pLeftNode->pNextNode = pNode->pNextNode;///el nodo a su izquierda pasa a apuntar al siguiente nodo
        }
        else///si el indice pasado es el ultimo del linked list
        {
            pLeftNode = getNode(this, ll_len(this)-1);///pido el nodo a la izquierda del indice
            pLeftNode->pNextNode = NULL;///el nodo a la izquierda pasa a apuntar a NULL
        }
        free(pNode);///libero al memoria del nodo que saque
        this->size--;///disminuyo el tamanio del linked list
        returnAux = 0;
    }
    return returnAux;
}






int ll_clear(LinkedList* this)
{

    int returnAux = -1;
    if (this != NULL)///verifico que la lista no sea nula
    {
        int i;
        for (i = 0; i < ll_len(this); i++)///recorro la lista
        {
            ll_remove(this, i);///elimino el nodo
        }
        returnAux = 0;
    }

    return returnAux;
}



int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this !=NULL)///pregunto si es nula lista
    {
        ll_clear(this);///elimino los lugares/nodos/vagones de la lista
        free(this);///limpio la memoria de la linked list
        returnAux=0;
    }

    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* pAuxElement = NULL;///puntero a auxiliar de elemento

    if (this != NULL)///verifico que la lista pasada no sea nula
    {
        int i;
        for (i=0; i<ll_len(this); i++)///recorro toda la lista
        {
            pAuxElement = ll_get(this, i);///guardo el elemento de la posicion i en el auxiliar

            if (pAuxElement == pElement)///si el auxiliar es igual al elemento pasado como parametro
            {
                returnAux = i;///retorno el indice
                break;
            }
        }
    }
    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)///verifica que la lista pasada no sea nula
    {
        returnAux = 1;

        if (this->size != 0)///verifica que el tamanio sea distinto a 0
        {
            returnAux = 0;
        }
    }
    return returnAux;
}



int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this != NULL && index >= 0 && index <= ll_len(this))///verifica que la lista no sa nula, y que el indice este dentro del rango
        ///del linked list
    {
        if (addNode(this, index, pElement) == 0)///agrega un nodo en la posicion pasada como parametro
        {
            returnAux = 0;
        }
    }
    return returnAux;
}



/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if (this != NULL && index >= 0 && index < ll_len(this))///verifica que la lista no sea nula y que el indice este dentro del rango
        ///del linked list
    {
        returnAux = ll_get(this, index);///guardo la direccion de memoria en el retorno auxiliar
        ll_remove(this, index);///remuevo el nodo con el indice pasado como parametro
    }
    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)>=0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pAuxElement = NULL;///puntero a elemento auxiliar
    if (this != NULL && this2 != NULL)///verifico que las listas no sean nulas
    {
        returnAux = 1;
        int i;
        for (i=0; i < ll_len(this2); i++)///recorro la lista 2
        {
            pAuxElement = ll_get(this2, i);///guardo en el auxiliar el elemento i de this2
            if (ll_contains(this, pAuxElement) == 0)///verifico que el elemento i de this2 este en la lista this
            {
                returnAux = 0;///si no esta, guarda el retorno
                break;///sale del for
            }
        }
    }
    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(!(this==NULL || from<0 || from>ll_len(this)|| to<=from||to>ll_len(this)))///pregunto si el dato es valido
    {
        cloneArray=ll_newLinkedList();///asigno memoria
        if(cloneArray!=NULL)
        {
            for(int i=from;i<to;i++)
            {
                ll_add(cloneArray,ll_get(this,i));
            }
        }
    }
    return cloneArray;
}


LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)///pregunto si la lista es nula
    {
        cloneArray=ll_subList(this,0,ll_len(this));///llamo la funcion que va a clonar el index desde 0
    }

    return cloneArray;
}



int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* auxElement;
    int tam;
    if(this!=NULL &&pFunc!=NULL &&order>=0&&order<=1)
    {
        tam=ll_len(this);
        for(int i=0; i<tam-1;i++)
        {
            for(int j=i+1;j<tam;j++)
            {
                if(pFunc(ll_get(this,i),ll_get(this,j))>0&& order==1)
                {
                    auxElement=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,auxElement);
                }
                else if(pFunc(ll_get(this,i),ll_get(this,j))<0&& order==0)
                {
                    auxElement=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,auxElement);
                }
            }
        }
        returnAux=0;
    }
    return returnAux;
}





// Funciones propias

int ll_increase_size(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->size +=1;
        retVal = 0;
    }
    return retVal;
}

int ll_decrease_size(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->size--;
        retVal = 0;
    }
    return retVal;
}


int ll_setFirstNode(LinkedList* this, Node* pNode)
{
    int retorno = -1;

    if(this !=NULL && pNode != NULL)
    {
        this->pFirstNode = pNode;
        retorno = 0;
    }
    return retorno;
}


int ll_setNextNode(Node* this, Node* nextNode)
{
    int retorno = -1;

    if(this !=NULL && nextNode != NULL)
    {
        this->pNextNode = nextNode;
        retorno = 0;
    }
    return retorno;
}


int ll_set_NodeElement(Node* this, void* pElement)
{
    int retorno = -1;
    if (this!=NULL)
    {
        this->pElement = pElement;
        retorno = 0;
    }
    return retorno;
}

int ll_set_Size(LinkedList* this, int size)
{
    int retorno = -1;

    if (this!=NULL)
    {
        this->size = size;
        retorno = 0;
    }
    return retorno;
}


Node* ll_get_firstNode(LinkedList* this)
{
    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        retornoNode = this->pFirstNode;
    }
    return retornoNode;

}


Node* ll_get_LastNode(LinkedList* this)
{
    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        if (ll_isEmpty(this)==0)
        {
            Node* lastNode = ll_get_firstNode(this);
            while (lastNode!=NULL)
            {
                retornoNode = lastNode;
                lastNode = ll_get_NextNode(retornoNode);
            }
        }
    }
    return retornoNode;
}


Node* ll_get_NextNode(Node* this)
{
    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        retornoNode = this->pNextNode;
    }
    return retornoNode;


}


Node* ll_get_NodeElement(Node* this)
{
    void* ret = NULL;
    if (this!=NULL)
    {
        ret = this->pElement;
    }
    return ret;


}


int ll_get_Size(LinkedList* this)
{
    int retorno = 0;
    if (this!=NULL)
    {
        retorno = this->size;
    }
    return retorno;
}

//Del parcial


int ll_map(LinkedList* this, int(*pFunc)(void*))
{
    int retVal = -1;
    if (this!=NULL&&pFunc!=NULL)
    {
        int i;
        for (i=0;i<ll_len(this);i++)
        {
            //void* temp;
            //temp = ll_get(this,i);
            //pFunc(temp);

            pFunc(ll_get(this,i));

        }//esta funcion va a recorrer la linkedlist, por cada elemento de la linkedlist le vamos a pasar ese elemento al puntero a funcion
        //el puntero a funcion lo que tiene es una funcion valga la redundancia criterio que se va a encargar en este caso de completar los campos
        //vacios de la lista
        retVal = 0;
    }
    return retVal;
}



LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* listaFiltrada = NULL;
    int i;

    if(this != NULL && ll_len(this) > 0 && pFunc != NULL)
    {
        listaFiltrada = ll_newLinkedList();

        for(i=0; i<ll_len(this); i++)
        {

            if((*pFunc)(ll_get(this,i)) ==1)
            {
                ll_add(listaFiltrada, ll_get(this,i));
            }
        }
    }
    return listaFiltrada;
}
