#include "listasD.h"
#include <stdio.h>
#include <stdlib.h>

nodoLista* CrearNodo(usuario p)
{
    nodoLista* nuevo= (nodoLista*)malloc(sizeof(nodoLista));
    nuevo->p=p;
    nuevo->ante=inicLista();
    nuevo->sig=inicLista();

    return nuevo;
}

nodoLista* agregarAlPrincipio(nodoLista* lista,nodoLista* nuevo)
{
    nuevo->sig=lista;

    if(lista!=NULL)
    {
        lista->ante=nuevo;
    }
    return nuevo;

}

char confirmar()
{
    char s;
    printf("\n Ingrese (s) para continuar: ");
    fflush(stdin);
    scanf("%c",&s);
    return s;
}

nodoLista* inicLista()
{
    return NULL;
}

