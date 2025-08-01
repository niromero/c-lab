#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "estrategias.h"
#include "defs.h"
#include "vistas.h"

AlgoritmoResolucion seleccionarEstrategia() {
    int opcion;
    int (*algoritmoDeResolucion)(int*, int[], int[], int*, int[2][8]);

    printf("Seleccionar la estrategia para resolver el recorrido:\n");
    printf("  1: Fuerza bruta (probar todas las combinaciones posibles)\n");
    printf("  2: Priorizar las casillas con menos movimientos disponibles\n");

    do
    {
        opcion = getch();
    } while (opcion < '1' || opcion > '2');

    switch (opcion)
    {
    case '1':
        algoritmoDeResolucion = fuerzaBruta;
        break;
    case '2':
        algoritmoDeResolucion = menosMovimientos;
        break;
    default:
        return NULL;
    }
    limpiarPantalla();

    return algoritmoDeResolucion;
}

int puedeMover(int pos, int nuevaPos, int movs[2][8], int nroMov, int tabl[], int dim) {
    if(pos%dim + movs[X][nroMov] < 0 || pos%dim + movs[X][nroMov] >= dim)
        return 0;
    if(pos/dim + movs[Y][nroMov] < 0 || pos/dim + movs[Y][nroMov] >= dim)
        return 0;
    if(tabl[nuevaPos] != 0)
        return 0;
    return 1;
}

int fuerzaBruta(int *dim, int tabl[], int pila[], int *cantMov, int movs[2][8]) {

    if (pila[(*dim) * (*dim) - 1] != 0)
        return 1;
    
    for(int i=0; i<8; i++) {

        int nuevaPos = pila[*cantMov] + movs[Y][i] * (*dim) + movs[X][i];
        if(puedeMover(pila[*cantMov], nuevaPos, movs, i, tabl, *dim)) {

                *cantMov += 1;
                tabl[nuevaPos] = *cantMov + 1;
                pila[*cantMov] = nuevaPos;

                printf("Movimiento %d: %d -> %d\n", *cantMov, pila[*cantMov - 1], pila[*cantMov]);

                /* limpiarPantalla();
                mostrarTablero(*dim, tabl, *cantMov, 1);
                Sleep(TIEMPO_RESOLUCION); */

                if (fuerzaBruta(dim, tabl, pila, cantMov, movs))
                    return 1;

                tabl[nuevaPos] = 0;
                pila[*cantMov] = 0;
                *cantMov -= 1;

                printf("Vuelve a %d\n", pila[*cantMov]);

                /* limpiarPantalla();
                mostrarTablero(*dim, tabl, *cantMov, 0);
                Sleep(TIEMPO_RESOLUCION); */
        }
    }

    return 0;
}

int menosMovimientos(int *dim, int tabl[], int pila[], int *cantMov, int movs[2][8]) {

    if (pila[(*dim) * (*dim) - 1] != 0)
        return 1;
    
    Movimiento *movsDisponibles = NULL;
    
    for(int i=0; i<8; i++) {
        int nuevaPos = pila[*cantMov] + movs[Y][i] * (*dim) + movs[X][i];
        if(puedeMover(pila[*cantMov], nuevaPos, movs, i, tabl, *dim)) {

            Movimiento *mov = malloc(sizeof(Movimiento));
            mov->cod_mov = i;
            mov->movs_disponibles = movimientosDisponibles(&nuevaPos, movs, tabl, dim) - 1;
            mov->dist_centro = distanciaAlCentro(&nuevaPos, dim);
            mov->nueva_posicion = nuevaPos;

            agregarNodo(&movsDisponibles, mov);
        }
    }

    while(movsDisponibles != NULL) {
        *cantMov += 1;
        tabl[movsDisponibles->nueva_posicion] = *cantMov + 1;
        pila[*cantMov] = movsDisponibles->nueva_posicion;

        printf("Movimiento %d: %d -> %d\n", *cantMov, pila[*cantMov - 1], pila[*cantMov]);

        if(menosMovimientos(dim, tabl, pila, cantMov, movs)) {
            while (movsDisponibles != NULL) {
                Movimiento *mov = movsDisponibles;
                movsDisponibles = mov->sgte;
                free(mov);
            }
            return 1;
        }
        
        tabl[movsDisponibles->nueva_posicion] = 0;
        pila[*cantMov] = 0;
        *cantMov -= 1;

        printf("Vuelve a %d\n", pila[*cantMov]);

        Movimiento *mov = movsDisponibles;
        movsDisponibles = mov->sgte;
        free(mov);
    }
    
    return 0;
}

int movimientosDisponibles (int *pos, int movs[2][8], int tabl[], int *dim) {
    int contador = 0;
    for (int i = 0; i < 8; i++) {
        int nuevaPos = *pos + movs[Y][i] * (*dim) + movs[X][i];
        if (puedeMover(*pos, nuevaPos, movs, i, tabl, *dim)) {
            contador++;
        }
    }
    return contador;
}

float distanciaAlCentro (int *pos, int *dim) {
    int fila = *pos / *dim;
    int col  = *pos % *dim;

    float centro = (*dim - 1) / 2.0f;

    float dx = col - centro;
    float dy = fila - centro;

    return dx * dx + dy * dy;
}

void agregarNodo(Movimiento **movsDisponibles, Movimiento *nuevoMov) {    
    if (*movsDisponibles == NULL) {
        nuevoMov->sgte = NULL;
        *movsDisponibles = nuevoMov;
    } else {
        Movimiento *actual = *movsDisponibles;
        Movimiento *anterior = NULL;

        while (actual != NULL) {
            int dif = actual->movs_disponibles - nuevoMov->movs_disponibles;

            if (dif > 0) break;
            if (dif == 0 && nuevoMov->dist_centro > actual->dist_centro) break;

            anterior = actual;
            actual = actual->sgte;
        }

        if (anterior == NULL) {
            nuevoMov->sgte = *movsDisponibles;
            *movsDisponibles = nuevoMov;
        } else {
            anterior->sgte = nuevoMov;
            nuevoMov->sgte = actual;
        }
    }
}