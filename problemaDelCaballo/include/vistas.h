#ifndef VISTAS_H
#define VISTAS_H

#define TIEMPO_RESULTADO 500

void limpiarPantalla();
void pausar (int milisec);
void mostrarTablero(int dim, int tabl[], int ultimo, int esExitoso);
void mostrarSolucion(int dim, int tabl[]);
void mostrarNoSolucion();

#endif