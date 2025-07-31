#include <stdio.h>
#include <conio.h>

#include "estrategias.h"
#include "defs.h"

AlgoritmoResolucion seleccionarEstrategia() {
    int opcion;
    int (*algoritmoDeResolucion)(int*, int[], int[], int*, int[2][8]);

    printf("Seleccionar la estrategia para resolver el recorrido:\n");
    printf("  1: Fuerza bruta (probar todas las combinaciones posibles)\n");
    printf("  2: Priorizar las casillas con mas movimientos disponibles\n");
    printf("  3: Priorizar las casillas con menos movimientos disponibles\n");

    do
    {
        opcion = getch();
    } while (opcion < '1' || opcion > '3');

    switch (opcion)
    {
    case '1':
        algoritmoDeResolucion = fuerzaBruta;
        break;
    case '2':
        algoritmoDeResolucion = fuerzaBruta;
        break;
    case '3':
        algoritmoDeResolucion = fuerzaBruta;
        break;
    default:
        break;
    }

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

    for(int i=0; i<8; i++) {

        int nuevaPos = pila[*cantMov] + movs[Y][i] * (*dim) + movs[X][i];
        if(puedeMover(pila[*cantMov], nuevaPos, movs, i, tabl, *dim)) {

                printf("Movimiento %d: %d -> %d\n", *cantMov + 1, pila[*cantMov], nuevaPos);

                /* system("cls");
                mostrarTablero(pila, *cantMov, 1);
                Sleep(250); */

                *cantMov += 1;
                tabl[nuevaPos] = *cantMov;
                pila[*cantMov] = nuevaPos;

                fuerzaBruta(dim, tabl, pila, cantMov, movs);
                if (pila[(*dim) * (*dim) - 1] != 0) return 0;

                tabl[nuevaPos] = 0;
                pila[*cantMov] = 0;
                *cantMov -= 1;

                printf("Vuelve a %d\n", pila[*cantMov]);

                /* system("cls");
                mostrarTablero(pila, *cantMov, 0);
                Sleep(250); */
        }
    }

    return 1;
}