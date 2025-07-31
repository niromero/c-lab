#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define TAMANIO 6 // Tamaño del tablero: TxT

#define CELDAS TAMANIO*TAMANIO
#define X 0
#define Y 1

void inicializarMovimientos(int movimientos[2][8]);
int moverCaballoFuerzaBruta(int tablero[CELDAS], int pila[CELDAS], int* cantidadMovimientos, int movimientos[2][8]);
int puedeMover(int posicion, int nuevaPosicion, int movimientos[2][8], int nro_mov, int tablero[CELDAS]);
void mostrarTablero(int pila[CELDAS], int paso, int pasoExitoso);
// void imprimirMovimiento(int pila[CELDAS], int paso, int pasoExitoso);

// void (*visualizador) (int[CELDAS], int, int) = NULL;

int main() {
    int tablero[CELDAS] = {1};
    int pila[CELDAS] = {0};
    int cantidadMovimientos = 0;

    int movimientos[2][8];
    inicializarMovimientos(movimientos);

    system("cls");

    /* printf("1 rapido 2 lento\n");
    char a;
    do
    {
        a = getch();
    } while (a != '1' && a != '2'); */

    moverCaballoFuerzaBruta(tablero, pila, &cantidadMovimientos, movimientos);

    printf("\n\nPresiona cualquier tecla para ver la resolucion\n");
    getch();

    for(int i=0; i<CELDAS; i++){
        system("cls");
        mostrarTablero(pila, i, 1);
        Sleep(500);
    }

    return 0;
}

void inicializarMovimientos(int movimientos[2][8]) {
    int dx[8] = { 2,  1, -1, -2, -2, -1,  1,  2};
    int dy[8] = {-1, -2, -2, -1,  1,  2,  2,  1};
    for (int i = 0; i < 8; i++) {
        movimientos[X][i] = dx[i];
        movimientos[Y][i] = dy[i];
    }
}

int moverCaballoFuerzaBruta(int tablero[CELDAS], int pila[CELDAS], int *cantidadMovimientos, int movimientos[2][8]) {

    for(int i=0; i<8; i++) {

        int nuevaPosicion = pila[*cantidadMovimientos] + movimientos[Y][i] * TAMANIO + movimientos[X][i];
        if(puedeMover(pila[*cantidadMovimientos], nuevaPosicion, movimientos, i, tablero)) {

                printf("Movimiento %d: %d -> %d\n", *cantidadMovimientos + 1, pila[*cantidadMovimientos], nuevaPosicion);

                /* system("cls");
                mostrarTablero(pila, *cantidadMovimientos, 1);
                Sleep(250); */

                tablero[nuevaPosicion] = 1;
                *cantidadMovimientos += 1;
                pila[*cantidadMovimientos] = nuevaPosicion;

                moverCaballoFuerzaBruta(tablero, pila, cantidadMovimientos, movimientos);
                if (pila[CELDAS - 1] != 0) return 0;

                tablero[nuevaPosicion] = 0;
                pila[*cantidadMovimientos] = 0;
                *cantidadMovimientos -= 1;

                printf("Vuelve a %d\n", pila[*cantidadMovimientos]);

                /* system("cls");
                mostrarTablero(pila, *cantidadMovimientos, 0);
                Sleep(250); */
        }
    }

    return 1;
}

int puedeMover(int posicion, int nuevaPosicion, int movimientos[2][8], int nro_mov, int tablero[CELDAS]) {
    if(posicion%TAMANIO + movimientos[X][nro_mov] < 0 || posicion%TAMANIO + movimientos[X][nro_mov] >= TAMANIO)
        return 0;
    if(posicion/TAMANIO + movimientos[Y][nro_mov] < 0 || posicion/TAMANIO + movimientos[Y][nro_mov] >= TAMANIO)
        return 0;
    if(tablero[nuevaPosicion] != 0)
        return 0;
    return 1;
}

void mostrarTablero(int pila[CELDAS], int paso, int pasoExitoso) {
    int tablero[TAMANIO][TAMANIO] = {0};

    for (int i = 0; i <= paso; i++) {
        int posicion = pila[i];
        int fila = posicion / TAMANIO;
        int col = posicion % TAMANIO;
        tablero[fila][col] = i + 1;
    }

    for (int j = 0; j < TAMANIO; j++) {
        printf(" ----");
    }
    printf("\n");

    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            int valor = tablero[i][j];
            if (valor == 0) {
                printf("|    ");
            } else if (valor == paso + 1) {
                if (pasoExitoso)
                    printf("| \033[0;36m%2d\033[0m ", valor);  // Cyan
                else
                    printf("| \033[0;31m%2d\033[0m ", valor);  // Rojo
            } else {
                printf("| %2d ", valor);
            }
        }
        printf("|\n");
        for (int j = 0; j < TAMANIO; j++) {
            printf(" ----");
        }
        printf("\n");
    }
}

/* void imprimirMovimiento(int pila[CELDAS], int paso, int pasoExitoso) {

} */