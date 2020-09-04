#include <stdio.h>
#include <stdlib.h>

#include "persona.h"

typedef struct _nodo
{
    persona dato;
    struct _nodo * siguiente;
} nodo;

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato= dato;
    aux->siguiente = NULL;
    return aux;
}

nodo * agregarPpio(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}



void mostrarNodo(nodo * aux)
{
    mostrarPersona(aux->dato);
}

void recorrerYmostrar(nodo * lista)
{
    nodo * seg = lista;
    while (seg->siguiente != NULL)
    {
        mostrarNodo(seg);
        seg= seg->siguiente;
    }
}

nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    if(seg)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}

nodo * buscarNodo( nodo * lista, char nombre[20])
///busca un nodo por nombre y retorna su posici�n de memoria
///si no lo encuentra retorna NULL.
{
    nodo * seg;		//apunta al nodo de la lista que est� siendo leido.
    seg = lista;  	//con esto evito cambiar el valor de la variable
    //lista, que contiene un puntero al primer nodo de la
    //lista vinculada
    while ((seg != NULL) && ( strcmp(nombre, seg->dato.nombre)!=0 ))
        //busco mientras me quede lista por recorrer y no haya encontrado el nombre
    {
        seg=seg->siguiente;	//avanzo hacia el siguiente nodo.
    }
    //en este punto puede ha fallado alguna de las dos condiciones del while
    //si fallo la primera es debido a que no encontro lo que buscaba (seg es NULL)
    //si fall la segunda es debido a que se encontro el nodo buscado.
    return seg;
}

nodo * borrarNodo(nodo * lista, char nombre[20])
{
    nodo * seg;
    nodo * ante;	//apunta al nodo anterior que seg.

    if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0 ))
    {
        nodo * aux = lista;
        lista = lista->siguiente; //salteo el primer nodo.
        free(aux); //elimino el primer nodo.
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0 ))
        {
            ante = seg;	//adelanto una posicion la var ante.
            seg = seg->siguiente; //avanzo al siguiente nodo.
        }

        if( seg!= NULL)
        {
            ante->siguiente = seg->siguiente; //salteo el nodo que quiero eliminar.
            free(seg); //elimino el nodo.
        }
    }
    return lista;
}


int main()
{
    printf("Hello listas!\n");

    nodo * lista;

    persona aux1={"pepe", 23};
    persona aux2={"maria", 34};
    persona aux3={"jose", 30};


    lista=inicLista();

    lista=agregarPpio(lista, crearNodo(aux1));
    lista=agregarPpio(lista, crearNodo(aux2));
    lista=agregarPpio(lista, crearNodo(aux3));


    lista=inicLista();

    recorrerYmostrar(lista);


    return 0;
}
