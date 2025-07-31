#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "defs.h"
#include "inicializacion.h"
#include "estrategias.h"
#include "vistas.h"

int main() {
    limpiarPantalla();
    int dim = ingresarDimension();                          // dimension del tablero (dim x dim)
    int *tabl = inicializarEstructura(dim, 1);              // tablero: mapa de celdas ocupadas
    int *pila = inicializarEstructura(dim, 0);              // pila: registro de celdas recorridas

    if(tabl == NULL || pila == NULL) {
        free(tabl); // Por si uno si fue asignado
        free(pila);
        fprintf(stderr, "Error al asignar memoria.\n");
        return EXIT_FAILURE;
    }

    int cant = 0;                                   // cantidad de movimientos efectuados
    int movs[2][8];                                 // movimientos legales del caballo
    inicializarMovimientos(movs);

    limpiarPantalla();
    AlgoritmoResolucion resolver = seleccionarEstrategia();     // estrategia de recorrido

    // TODO
    // limpiarPantalla();
    // Vista vist = seleccionarVistas();                       // vista al recorrer los caminos

    resolver(&dim, tabl, pila, &cant, movs);

    // TODO: nueva funcion en vistas.c
    for(int i = 0; i < dim * dim; i++){
        limpiarPantalla();
        mostrarTablero(dim, tabl, i, 1);
        Sleep(500);
    }

    free(tabl);
    free(pila);

    return 0;
}