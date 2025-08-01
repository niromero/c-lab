# Problema del caballo

Este proyecto implementa soluciones al clásico problema del caballo, que consiste en recorrer todas las casillas de un tablero de ajedrez a partir de los movimientos de un caballo, sin repetir ninguna posición.

### Estrategias

Al ejecutar el programa, se solicitará al usuario el tamaño del tablero (entre 5x5 y 9x9) y la estrategia a utilizar:

- **Heurística (Warnsdorff):** Elige movimientos que dejen al caballo con la menor cantidad de opciones futuras. En caso de empate, prioriza aquellos que se alejan del centro.
- **Fuerza bruta:** Explora todas las posibles combinaciones de movimientos en orden fijo mediante recursión, hasta encontrar una solución válida.

### Ejecución
Para compilar y correr el programa:

```bash
    make run
```
> Es necesario tener make y gcc instalado.