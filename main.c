#include <stdio.h>
#include <stdlib.h>
#include "listasD.h"
#include "string.h"
///Sistemas de usuarios

/**
Cosas que necesitamos que el sistema haga:

1. registrar al usuario:
* nombre
* id
* contraseña
* monto inicial
* email
* edad
* aceptar los terminos y condiciones

tiene que buscar que ningun otro usuario tenga el mismo nombre de usuario o la misma contraseña


2. Guardar al usuario en un archivo

3. funciones del administrador
* ver listado de usuarios
* dar de baja a un usuario
* salir

4. crear pantallas principales y navegables

5. crear graficos de monedas y personaje del usuario
**/




nodoLista* pasarDelArchivo(FILE* arch)
{
    nodoLista* nueva;
    nodoLista* lista= inicLista();
    usuario aux;

    while(!feof(arch))
    {
        fread(&aux,sizeof(usuario),1,arch);
        nodoLista* nuevo = CrearNodo(aux);
        lista= agregarAlPrincipio(lista, nuevo);
    }

    return lista;
}

int buscarPorNombre(nodoLista *lista,char nombre[])
{
    int flag=1;
    while(lista!=NULL && flag == 1)
    {
        if(strcmp(nombre,lista->p.nombre)== 0)
        {
            flag=0;
        }
        lista= lista->sig;
    }
    if(strlen(nombre)>20 || strlen(nombre)<1)
        flag=-1;
    return flag;
}

int buscarPorEmail(nodoLista *lista,char nombre[])
{
    int flag=1;

    while(lista!=NULL && flag == 1)
    {
        if(strcmp(nombre,lista->p.email)== 0 )
        {
            flag=0;
        }
        lista= lista->sig;
    }


    return flag;
}

void mostrar(nodoLista* lista)
{
    nodoLista*seg=lista->sig;

    while(seg!=NULL)
    {
        mostrarPersona(seg->p);
        seg=seg->sig;
    }
}

int contrasenaSegura(char contra[])
{
    int flag=1;
    if((strlen(contra)<8 && strlen(contra)>16 ))
        flag=0;

    return flag;
}


void mostrarPersona(usuario p)
{
    printf("\nNombre: %s",p.nombre);
    printf("\nEdad: %i",p.edad);
    printf("\nid: %i",p.id);
}
/// Cargar persona
int contarElementos(nodoLista* lista)
{
    int i=0;
    while(lista!=NULL)
    {
        i++;
        lista=lista->sig;
    }
    return i;
}

usuario cargarU(FILE* archi)
{
    nodoLista* lista= pasarDelArchivo(archi);
    usuario nuevo;
    nodoLista * seg= lista;
    int i=contarElementos(lista);
    nuevo.id= i;
    nuevo.estado=1;

    int e=0;
    int aux=0;

    /// edad
    while(e==0)
    {
      printf("\nIngrese edad: ");
      fflush(stdin);
      scanf("%i",&aux);

      if(aux<=0)
            printf("\nIngrese una edad valida ");
      else
      {
          e=1;
          nuevo.edad=aux;
      }
    }
    ///nombre usuario
    e=0;
    char auxi[20];
    while(e==0)
    {
        printf("\nIngrese nombre de usuario:  ");
        fflush(stdin);
        gets(auxi);

        e= buscarPorNombre(lista,auxi);

        if(e==0)
            printf("\nEl usuario ya existe");
        else if(e==-1)
            printf("\nSu nombre de usuario debe tener entre 1 y 20 caracteres");
        else
            strcpy(nuevo.nombre,auxi);
    }
    ///contraseñas
    e=0;

    while(e==0)
    {
        printf("\nIngrese contrasena: ");
        fflush(stdin);
        gets(auxi);

        e= contrasenaSegura(auxi);

        if(e==0)
        {
            printf("\nSu contrasena debe contener entre 8 y 16 caracteres");
        }else
            strcpy(nuevo.contrasena,auxi);

    }
    ///email
    e=0;
    while(e==0)
    {
        printf("\nIngrese Email:  ");
        fflush(stdin);
        gets(auxi);

        e= buscarPorEmail(lista,auxi);

        if(e==0)
            printf("\nEl email ingresado no es valido");
        else{
            strcpy(nuevo.email,auxi);
        }
    }

    ///monedas
    /*
    int id; x
    int estado;x
    char nombre[20];
    char contrasena[16];
    int edad;x
    char email[20];
    int monedaA;
    int monedaB;
    int monedaC;
    int monedaD;*/

    return nuevo;
}

void cargarArchivo(char archi[])
{
    FILE* arch= fopen(archi,"a+b");

    if(arch)
    {
        usuario nuevo= cargarU(arch);
        fwrite(&nuevo,sizeof(nuevo),1,arch);
        fclose(arch);
    }
}
void pantallaPrincipal()
{
    printf("\n              . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .");
    printf("\n              .                                                                             .");
    printf("\n              .                                                                             .");
    printf("\n              .                              BIENVENIDOS:                                   .");
    printf("\n              .                                                                             .");
    printf("\n              .                                                                             .");
    printf("\n              .                      ..............................                         .");
    printf("\n              .                      .     1. INICIAR SESION      .                         .");
    printf("\n              .                      ..............................                         .");
    printf("\n              .                                                                             .");
    printf("\n              .                      ..............................                         .");
    printf("\n              .                      .     2. REGISTRARSE         .                         .");
    printf("\n              .                      ..............................                         .");
    printf("\n              .                                                                             .");
    printf("\n              .                      ..............................                         .");
    printf("\n              .                      .       3. SALIR             .                         .");
    printf("\n              .                      ..............................                         .");
    printf("\n              .                                                                             .");
    printf("\n              .                                                                             .");
    printf("\n              .                                                                             .");
    printf("\n              . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n");

}

void pantallaDespedida()
{
     printf("\n              . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .");
     printf("\n              .                                                                             .");
     printf("\n              .                                                                             .");
     printf("\n              .                           HASTA LA PROXIMA!!!                               .");
     printf("\n              . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n");

}
void pantallaUsuario(){
     printf("\n              . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  ");
     printf(".\n              .   ______________________________________________________________________   ");
     printf(".\n              .  |inventario:      (A): %i (B): %i (C): %i | rango: %s                      ",1,2,3,"oro");
     printf(" .\n                 ----------------------------------------------------------------------.  ");

}
int main()
{
    pantallaPrincipal();
    pantallaUsuario();
    pantallaDespedida();
    /*
    char archi[]= "archivo.dat";
    cargarArchivo(archi);


    //cargarArchivo(archi);
    //cargarArchivo(archi);

    nodoLista* lista=inicLista();
    FILE* arch= fopen(archi,"rb");
    if(arch!=NULL)
    {
        lista= pasarDelArchivo(arch);
        mostrar(lista);
        fclose(arch);
    }*/

    return 0;
}
