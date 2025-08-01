#ifndef VISTAS_H
#define VISTAS_H

typedef enum {
    NADA,
    LOGS,
    BARRA,
    TABLERO
} Vista;

#define TIEMPO_RESOLUCION 100
#define TIEMPO_RESULTADO 500

Vista seleccionarVista();
void limpiarPantalla();
void mostrarTablero(int dim, int tabl[], int ultimo, int esExitoso);
void mostrarSolucion(int dim, int tabl[]);
void mostrarNoSolucion();

#endif