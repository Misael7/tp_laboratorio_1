#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);
void ll_swapper(Node *first,Node *second);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList*));
    if(this!=NULL)
    {
		this->pFirstNode=NULL;
		this->size=0;
		/*
		this->pFirstNode->pNextNode=NULL;*/
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;
	if(this!=NULL)
	{

		returnAux=this->size;
	}

    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int length = ll_len(this);
		if(this!=NULL)
		{
			Node* nodoAux=this->pFirstNode;
			if(nodeIndex < 0 || nodeIndex >= length)
			{
				return NULL;
			}


			for(int i = 0 ; i <= nodeIndex ; i++ )
			{
				if(nodoAux->pNextNode != NULL)
				{
					if(i!=nodeIndex)
					{
						nodoAux = nodoAux->pNextNode;
					}

				}
				if(nodeIndex == 0)
				{
					nodoAux = this->pFirstNode;
				}
			}

			return nodoAux;
		}
		return NULL;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int length = ll_len(this);
	int returnAux = -1;
	Node* auxNode;
	Node* auxNodeNext;

		if(this!=NULL && nodeIndex >= 0 && nodeIndex <= length)
		{
			auxNode = (Node*)malloc(sizeof(Node*));
			this->size=length+1;
			auxNode->pElement= pElement;

				if(nodeIndex==0)
				{
					auxNode->pNextNode=this->pFirstNode;
					this->pFirstNode=auxNode;

				}
				else
				{
					auxNodeNext = getNode(this, nodeIndex-1);
					auxNode->pNextNode = auxNodeNext->pNextNode;
					auxNodeNext->pNextNode = auxNode;
					returnAux=0;
				}
				returnAux=0;
		}


    return returnAux;

}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{

	int length = ll_len(this);
	int returnAux = -1;
	Node* auxNode;

	if(this!=NULL)
	{
		//auxNode = (Node*)malloc(sizeof(Node*));//La función AddNode realiza el malloc para el nodo nuevo, además de aumentar el tamaño de la lista
		auxNode = addNode(this,length, pElement);
		returnAux=0;

	}

    return returnAux;

}

/** \brief Permite obtener un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

void* ll_get(LinkedList* this, int index)
{
	void* returnAux = NULL;
	int length = ll_len(this);
    Node* auxNode;
    if(this!=NULL && index >= 0 && index < length)
    {
		auxNode = getNode(this,index);
		returnAux=auxNode->pElement; //retorna el elemento del nodo, a diferencia de getNode que retorna el Nodo entero.
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;
    int length = ll_len(this);
    if(this!=NULL && index >= 0 && index <= length)
    {
    	auxNode = getNode(this,index);
    	if(auxNode!=NULL)
    	{
    		auxNode->pElement=pElement; //Settea el elemento del nodo, sin modificar el resto
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	//Sale copypaste de addNode
	int length = ll_len(this);
	int returnAux = -1;
	Node* auxNode;
	Node* auxNodeNext;

	if(this!=NULL && index >= 0 && index < length)
	{
	if(index==0)
	{
		auxNode= getNode(this, index);
		this->pFirstNode = auxNode->pNextNode;
		/*if(ll_get(this, index)==NULL)
		{*/
			free(auxNode);
		//}
	}

	else
	{
		auxNodeNext = getNode(this, index);
		auxNode = getNode(this,index-1);
		auxNode->pNextNode = auxNodeNext->pNextNode; //encaja puntero de nodo next en nodo anterior.
		auxNodeNext->pNextNode = NULL;
		/*if(ll_get(this, index)==NULL)
		{*/
			free(auxNodeNext);
		//}

	}
	this->size=length-1;
	returnAux=0;
	}
	return returnAux;

}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this !=NULL)
    {
    	this->pFirstNode=NULL;
    	this->size=0;
    	returnAux=0;
    }
    else
    {
    	returnAux = -1;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux=0;
    }
    else
    {
    	returnAux= -1;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int length=ll_len(this);

    if(this !=NULL)
    {
    	Node* auxNode=this->pFirstNode; //Asigna valor del primer nodo al auxNode.
    	for(int i=0 ; i <length ; i++)
    	{
			if(auxNode->pElement==pElement)
			{
				return i;
				break;
			}
    	auxNode = auxNode->pNextNode; //Asigna el valor del nextnode a auxNode luego de iterar comparando el elemento del actual previo al cambio
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
		if(this->pFirstNode!=NULL)
		{
			returnAux = 0;
		}
		if(this->pFirstNode==NULL)
		{
			returnAux = 1;
		}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if (this!=NULL && index>=0)
    {
    	returnAux=addNode(this, index, pElement);
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
    int length = ll_len(this);
    if(this!=NULL && index >= 0 && index < length)
    {
    	returnAux = ll_get(this,index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int length = ll_len(this);
    if(this!=NULL && length >=0)
    {
    	Node* auxNode=this->pFirstNode; //Asigna valor del primer nodo al auxNode.
    	for(int i = 0 ; i < length ; i++)
    	{
    		if(auxNode->pElement == pElement)
    		{
    			returnAux=1;
    			break;
    		}
    		auxNode=auxNode->pNextNode;
    	}
    	if(returnAux!=1)
    	{
    		return 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int length = ll_len(this2);
    if(this!=NULL && this2!=NULL)
    {
    	Node* auxNodo = this2->pFirstNode;//elementos segunda lista
    	returnAux=1;
    	for(int i=0 ; i < length ; i++)
    	{
			if(ll_contains(this, auxNodo->pElement)!=1) //Si los elementos de la segunda lista, no estan en la lista 1, retorna 0
			{
				returnAux= 0;
				break;
			}
			auxNodo = auxNodo->pNextNode;
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int length = ll_len(this);
    if(this != NULL && from >= 0 && from < length && to >= from && to <= length)
    {
    	cloneArray=ll_newLinkedList(); //Asigno memoria para la nueva lista
    	Node* auxCloneNode;
    	for(;from < to ; from++)
    	{
    		/*auxCloneNode = getNode(this, from);  //Agarra element
    		addNode(cloneArray, from , auxCloneNode);*/ //Mete element en la nueva lista
    		auxCloneNode = ll_get(this, from);
    		ll_add(cloneArray,auxCloneNode);
    	}

    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	//Igual que subList pero entera.
    LinkedList* cloneArray = NULL;
    int length = ll_len(this);
    if(this != NULL)
    {
    	cloneArray=ll_newLinkedList();
    	Node* auxCloneNode;
    	for(int i = 0;i < length; i++)
    	{
    		auxCloneNode = ll_get(this, i);
    		ll_add(cloneArray,auxCloneNode);
    	}

    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int length = ll_len(this);
    Node* firstNode;
    Node* secondNode;
    int swapFlag = 0;
    //IMPORTANTE!
    //Se debe comentar las llamadas al ll_swapper para probar el programa, de lo contrario jamás para de ejecutarse
    //y no devuelve el resultado de Test.
    if(this != NULL && pFunc != NULL && length>1 && (order==1 || order==0)) //Verifica sentido ordenamiento
    {
    	do
    	{
    		for(int i = 0 ; i < length-1 ; i++)
    		{
    			firstNode = getNode(this, i);
    			secondNode = getNode(this, i+1);
    			if(order == 1 && pFunc( firstNode->pElement, secondNode->pElement)>0) //usa el valor de retorno pFunc como condicional
    			{
    				ll_swapper(firstNode, secondNode);
    				swapFlag = 1;
    			}
    			if(order == 0 && pFunc( firstNode->pElement, secondNode->pElement)<0) //usa el valor de retorno pFunc como condicional
    			{
    				ll_swapper(firstNode, secondNode);
    				swapFlag = 1;
    			}

    		}

    	}while(swapFlag!=0);
        returnAux = 0;
    }

    return returnAux;

}

void ll_swapper(Node *first,Node *second)
{
    Node* auxNode = first->pElement;
    first->pElement = second->pElement;
    second->pElement = auxNode;
}

