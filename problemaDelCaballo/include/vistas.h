#ifndef VISTAS_H
#define VISTAS_H

typedef enum {
    NADA,
    LOGS,
    BARRA,
    TABLERO
} Vista;

Vista seleccionarVista();
void limpiarPantalla();
void mostrarTablero(int dim, int tabl[], int ultimo, int esExitoso);

#endif