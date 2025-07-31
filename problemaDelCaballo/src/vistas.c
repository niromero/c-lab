#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "vistas.h"
#include "defs.h"

Vista seleccionarVistas() {
    int opcion;

    printf("Seleccionar como visualizar el progreso durante la ejecucion:\n");
    printf("  1: No mostrar nada (mas rapido)\n");
    printf("  2: Mensajes paso a paso\n");
    printf("  3: Barra con la cantidad de movimientos\n");
    printf("  4: Tablero en tiempo real (mas lento)\n");

    do
    {
        opcion = getch();
    } while (opcion < '1' || opcion > '4');

    return (Vista) (opcion - '1');
}


void limpiarPantalla() {
    system("cls");
    return;
}

void mostrarTablero (int dim, int tabl[], int ultimo, int esExitoso) {

    for (int j = 0; j < dim; j++) {printf(" ----");}
    printf("\n");

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            int paso = tabl[i*dim + j];
            if (paso == 0) {
                printf("|    ");
            } else if (paso == ultimo + 1) {
                if (esExitoso)
                    printf("| \033[0;36m%2d\033[0m ", paso);  // Cyan
                else
                    printf("| \033[0;31m%2d\033[0m ", paso);  // Rojo
            } else {
                printf("| %2d ", paso);
            }
        }
        printf("|\n");
        for (int j = 0; j < dim; j++) {printf(" ----");}
        printf("\n");
    }
}