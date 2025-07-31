#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

typedef int (*AlgoritmoResolucion)(int[], int[], int[], int*, int[2][8]);

AlgoritmoResolucion seleccionarEstrategia();
int puedeMover(int pos, int nuevaPos, int movs[2][8], int nroMov, int tabl[], int dim);
int fuerzaBruta(int *dim, int tabl[], int pila[], int *cantMov, int movs[2][8]);

#endif