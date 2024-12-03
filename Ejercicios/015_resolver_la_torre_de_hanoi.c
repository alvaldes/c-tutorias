#include <stdio.h>

/*
 * Ejercicio 015: Resolver la Torre de Hanói
 *
 * Descripción:
 * Escribe un programa en C que resuelva el problema de la Torre de Hanói para n discos.
 * El programa debe mostrar los movimientos necesarios para trasladar los discos desde
 * la torre de origen hasta la torre de destino, respetando las reglas del problema:
 * - Solo se puede mover un disco a la vez.
 * - Un disco no puede colocarse sobre otro disco más pequeño.
 *
 * Requisitos:
 * - Solicitar al usuario el número de discos.
 * - Mostrar los pasos necesarios para resolver el problema.
 *
 * Ejemplo de ejecución:
 *
 * Entrada: 3
 * Salida:
 *   Mover disco 1 de A a C
 *   Mover disco 2 de A a B
 *   Mover disco 1 de C a B
 *   Mover disco 3 de A a C
 *   Mover disco 1 de B a A
 *   Mover disco 2 de B a C
 *   Mover disco 1 de A a C
 *
 * Pistas:
 * - Usa recursión para resolver el problema.
 * - La estrategia recursiva consiste en:
 *   1. Mover los n-1 discos superiores a la torre auxiliar.
 *   2. Mover el disco más grande a la torre de destino.
 *   3. Mover los n-1 discos desde la torre auxiliar a la torre de destino.
 */

void torreDeHanoi(int n, char origen, char destino, char auxiliar)
{
    if (n == 1)
    {
        // Caso base: Mover un único disco
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }

    // Mover n-1 discos a la torre auxiliar
    torreDeHanoi(n - 1, origen, auxiliar, destino);

    // Mover el disco más grande al destino
    printf("Mover disco %d de %c a %c\n", n, origen, destino);

    // Mover los n-1 discos desde la torre auxiliar al destino
    torreDeHanoi(n - 1, auxiliar, destino, origen);
}

int main()
{
    int n;

    printf("Introduce el número de discos: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("El número de discos debe ser mayor a 0.\n");
        return 1;
    }

    printf("Resolviendo la Torre de Hanói para %d discos:\n", n);
    torreDeHanoi(n, 'A', 'C', 'B');

    return 0;
}