#include <stdio.h>

/*
 * Ejercicio 001: Factorial de un Número
 *
 * Descripción:
 * Escribe un programa en C que calcule el factorial de un número entero positivo
 * ingresado por el usuario. El factorial de un número n (n!) se define como el
 * producto de todos los enteros positivos desde 1 hasta n.
 *
 * Requisitos:
 * - El programa debe solicitar al usuario que ingrese un número entero positivo.
 * - Si el usuario ingresa un número negativo, mostrar un mensaje de error y finalizar.
 * - El programa debe calcular el factorial utilizando un bucle.
 *
 * Ejemplo de entrada y salida:
 *
 * Entrada: 5
 * Salida: El factorial de 5 es 120.
 *
 * Pistas:
 * - Usa un bucle para calcular el producto.
 * - Considera que el factorial de 0 es 1.
 * - Asegúrate de manejar el caso de números negativos correctamente.
 */

int calcularFactorial(int numero)
{
    if (numero < 0)
    {
        // El factorial no está definido para números negativos
        printf("Error: El factorial no está definido para números negativos.\n");
        return -1;
    }

    int resultado = 1;
    for (int i = 1; i <= numero; i++)
    {
        resultado *= i;
    }
    return resultado;
}

int main()
{
    int numero;
    printf("Introduce un número entero positivo: ");
    scanf("%d", &numero);

    int factorial = calcularFactorial(numero);
    if (factorial != -1)
    {
        printf("El factorial de %d es %d.\n", numero, factorial);
    }

    return 0;
}