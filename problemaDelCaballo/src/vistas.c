#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "vistas.h"
#include "defs.h"

void limpiarPantalla() {
    system("cls");
    return;
}

void pausar (int milisec) {
    Sleep(milisec);
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
    return;
}

void mostrarSolucion (int dim, int tabl[]) {
    printf("\nPresione cualquier tecla para ver solucion.\n");
    getch();
    for(int i = 0; i < dim * dim; i++){
        limpiarPantalla();
        mostrarTablero(dim, tabl, i, 1);
        pausar(TIEMPO_RESULTADO);
    }
    return;
}

void mostrarNoSolucion () {
    printf("\nNo se encontro solucion para el escenario dado.\n");
    return;
}