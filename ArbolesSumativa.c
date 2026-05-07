#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

// MAIN
int main(){
    ABO arbolPrincipal = NULL;
    int valorBuscado;
    char archivoNodos[] = "1.txt";

    // Carga de datos
    arbolPrincipal = LeeArchivo(archivoNodos);

    printf("--- Analisis de Nodos ABO ---\n");
    printf("Ingrese el valor a buscar: ");
    scanf("%i", &valorBuscado);

    // Validacion de existencia
    if (estaEnABO(arbolPrincipal, valorBuscado)) {
        printf("\n1. Nivel del nodo: %d", nivelDeUnNodo(arbolPrincipal, valorBuscado));

        int padre = padreNodoABO(arbolPrincipal, valorBuscado);
        if (padre != -1) {
            printf("\n2. Padre del nodo: %d", padre);
        } else {
            printf("\n2. El nodo es la raiz (no tiene padre)");
        }

        printf("\n3. Antecesores: ");
        antecesoresNodoABO(arbolPrincipal, valorBuscado);
        printf("\n");
    } else {
        printf("\nEl valor %i no existe en el arbol cargado.\n", valorBuscado);
    }
    return 0;
}
