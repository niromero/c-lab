#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "inicializacion.h"
#include "defs.h"
#include "vistas.h"

int ingresarDimension() {
    char dimension;

    limpiarPantalla();
    printf("Ingresar un valor entre 3 y 8 para la dimension del tablero\n");
    do
    {
        dimension = getch();
    } while (dimension < '3' || dimension > '8');
    limpiarPantalla();

    return dimension - '0';
}

int *inicializarEstructura(int dimension, int primerElemento) {
    int *estructura = malloc(sizeof(int) * dimension * dimension);
    if (estructura == NULL) {
        return NULL;
    }

    estructura[0] = primerElemento;

    for(int i = 1; i < dimension * dimension; i++) {
        estructura[i] = 0;
    }

    return estructura;
}

void inicializarMovimientos(int movimientos[2][8]) {
    int dx[8] = { 2,  1, -1, -2, -2, -1,  1,  2};
    int dy[8] = {-1, -2, -2, -1,  1,  2,  2,  1};
    for (int i = 0; i < 8; i++) {
        movimientos[X][i] = dx[i];
        movimientos[Y][i] = dy[i];
    }
}