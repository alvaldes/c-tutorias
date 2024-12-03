#include <stdio.h>

/*
 * Ejercicio 008: Recursión - Factorial de un Número
 *
 * Descripción:
 * Escribe un programa en C que calcule el factorial de un número entero positivo
 * utilizando recursión. El factorial de un número n (n!) se define como el producto
 * de todos los enteros positivos desde 1 hasta n. El caso base es que el factorial
 * de 0 es igual a 1.
 *
 * Requisitos:
 * - Solicitar al usuario que ingrese un número entero positivo.
 * - Calcular el factorial utilizando una función recursiva.
 * - Mostrar el resultado al usuario.
 * - Validar que el número ingresado sea positivo.
 *
 * Ejemplo de entrada y salida:
 *
 * Entrada: 5
 * Salida: El factorial de 5 es 120.
 *
 * Entrada: -3
 * Salida: Error: El número debe ser mayor o igual a 0.
 *
 * Pistas:
 * - La definición recursiva del factorial es:
 *   factorial(n) = n * factorial(n-1), con factorial(0) = 1.
 * - Usa una condición base para detener la recursión.
 */

int factorial(int n)
{
    // Caso base: factorial de 0 es 1
    if (n == 0)
    {
        return 1;
    }
    // Llamada recursiva
    return n * factorial(n - 1);
}

int main()
{
    int numero;

    // Solicitar al usuario un número
    printf("Introduce un número entero positivo: ");
    scanf("%d", &numero);

    if (numero < 0)
    {
        printf("Error: El número debe ser mayor o igual a 0.\n");
    }
    else
    {
        printf("El factorial de %d es %d.\n", numero, factorial(numero));
    }

    return 0;
}