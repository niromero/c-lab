#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

typedef int (*AlgoritmoResolucion)(int[], int[], int[], int*, int[2][8]);

typedef struct Movimiento {
    int cod_mov;
    int nueva_posicion;
    int movs_disponibles;
    float dist_centro;
    struct Movimiento *sgte;
} Movimiento;

AlgoritmoResolucion seleccionarEstrategia();
int puedeMover(int pos, int nuevaPos, int movs[2][8], int nroMov, int tabl[], int dim);
int fuerzaBruta(int *dim, int tabl[], int pila[], int *cantMov, int movs[2][8]);
int menosMovimientos(int *dim, int tabl[], int pila[], int *cantMov, int movs[2][8]);
int movimientosDisponibles (int *pos, int movs[2][8], int tabl[], int *dim);
float distanciaAlCentro (int *pos, int *dim);
void agregarNodo(Movimiento **movsDisponibles, Movimiento *nuevoMov);

#endif