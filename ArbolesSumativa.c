#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estructura del nodo 
struct nodo {
    int info;
    struct nodo *izq;
    struct nodo *der;
};

typedef struct nodo tNodo;
typedef tNodo *ABO;

// Reserva memoria para un nuevo nodo e inicializa sus valores
ABO crearNodo(int valor) {
    ABO nuevo = (ABO)malloc(sizeof(tNodo));
    nuevo->info = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}
// Insertar nuevo valor en arbol binario
ABO insertarABO(ABO A, int valor) {
    //Si el árbol está vacío se crea el primer nodo
    if (A == NULL) {
        return crearNodo(valor);
    }
    //Si el valor es menor que la raiz actual, se inserta en el subarbol izquierdo
    if (valor < A->info) {
        A->izq = insertarABO(A->izq, valor);
    }
    //Si el valor es mayor, se inserta en el subarbol derecho 
    else if (valor > A->info) {
        A->der = insertarABO(A->der, valor);
    }
    //Retorna el puntero
    return A;
}
bool estaEnABO (ABO A, int valor){
    //Si el árbol es nulo el valor no existe
    if (A==NULL)
        return false;
    // Si el valor coincide con la información del nodo actual
    if (A->info == valor)
        return true;
    // Si el valor es menor,se busca en el hijo izquierdo, sino en el derecho.
    if (valor < A->info)
        return estaEnABO (A->izq, valor);
    else
        return estaEnABO (A->der, valor);
}
ABO LeeArchivo(char nombreArchivo[50])
{
    FILE *archivo;
    ABO A;
    int valor;

    archivo = fopen(nombreArchivo, "r");
    // verificar si el archivo no existe o no se puede abrir
    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo. Revisa su ubicación.", 163);
        printf("\n\n");
        exit(0);
    }
    //Inicializar árbol vacío
    A = NULL;
    // Ciclo que recorre el archivo
    while (feof(archivo) == false)
    {
        fscanf(archivo, "%i\n", &valor);
        // insertar el valor si lo encuentra en el ABO
        if (!estaEnABO(A, valor))
        {
            A = insertaABO(A, valor);
        }
    }

    fclose(archivo);
    return A;
}
//Retorna nivel de un nodo , la raíz se considera nivel 0
int nivelDeUnNodo (ABO A, int valor) {
    if (A->info == valor){
        return 0;
    }
    if (valor < A ->info){
        return 1+ nivelDeUnNodo(A->izq, valor);
    } else {
        return 1 + nivelDeUnNodo(A->der, valor);
    }
}

//Retorna valor del nodo padre, y retorna -1 si es la raíz o no tiene padre
int padreNodoABO(ABO A, int valor) {
    // Si el árbol es nulo o el valor es la raíz , no tiene padre
    if(A==NULL || A->info==valor){
        return -1
    }
    //Revisar si alguno de los hijos es el valor buscado
    if ((A->izq != NULL && A->izq->info == valor) || (A->der != NULL && A->der->info == valor)){
        return A->info;

    }
    if (valor <A->info){
        return padreNodoABO(A->izq, valor);
    } else {
        return padreNodoABO(A->der, valor);
    }
}