#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "defs.h"
#include "inicializacion.h"
#include "estrategias.h"
#include "vistas.h"

int main() {

    int movs[2][8];     // movimientos legales del caballo ( [eje: X, Y] [id_movimiento] )
    inicializarMovimientos(movs);

    int dim = ingresarDimension();                  // dimension del tablero (dim x dim)
    int *tabl = inicializarEstructura(dim, 1);      // tablero: mapa de celdas ocupadas
    int *pila = inicializarEstructura(dim, 0);      // pila: registro de celdas recorridas

    if(tabl == NULL || pila == NULL) {
        free(tabl); // Por si uno si fue asignado
        free(pila);
        fprintf(stderr, "Error al asignar memoria.\n");
        return EXIT_FAILURE;
    }

    // Configuracion

    AlgoritmoResolucion resolver = seleccionarEstrategia();     // estrategia de recorrido

    if(resolver == NULL) {
        free(tabl);
        free(pila);
        fprintf(stderr, "Error al selecionar estrategia.\n");
        return EXIT_FAILURE;
    }

    // Ejecucion

    int cant = 0;
    int resultado = resolver(&dim, tabl, pila, &cant, movs);

    if(resultado) {
        mostrarSolucion(dim, tabl);
    } else {
        mostrarNoSolucion();
    }

    free(tabl);
    free(pila);

    return 0;
}