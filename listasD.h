typedef struct{
    int id;
    int estado;
    char nombre[20];
    char contrasena[16];
    int edad;
    char email[20];
    int monedaA;
    int monedaB;
    int monedaC;
    int monedaD;

}usuario;
typedef struct
{
    usuario p;
    struct nodoLista* sig;
    struct nodoLista* ante;
} nodoLista;

nodoLista* inicLista();
nodoLista* CrearNodo(usuario p);
nodoLista* agregarAlPrincipio(nodoLista* lista,nodoLista* nuevo);
nodoLista* buscarNodoMayor(nodoLista* lista);
nodoLista* crearListaOrdenada(nodoLista* lista);
char confirmar();
nodoLista* cargarLista(nodoLista* lista);

