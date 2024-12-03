#include <stdio.h>

/*
 * Ejercicio 003: Triángulo de Pascal
 *
 * Descripción:
 * Escribe un programa en C que genere el Triángulo de Pascal hasta una altura
 * especificada por el usuario. El Triángulo de Pascal es una representación
 * triangular de coeficientes binomiales.
 *
 * Requisitos:
 * - El programa debe solicitar al usuario que ingrese un número entero positivo.
 * - Calcular y mostrar el triángulo con bucles anidados.
 * - Asegúrate de alinear correctamente los números en forma de triángulo.
 *
 * Ejemplo de entrada y salida:
 *
 * Entrada: 5
 * Salida:
 *        1
 *       1 1
 *      1 2 1
 *     1 3 3 1
 *    1 4 6 4 1
 *
 * Pistas:
 * - Usa una función auxiliar para calcular factoriales.
 * - Los elementos del triángulo pueden calcularse con coeficientes binomiales:
 *   C(n, k) = n! / (k! * (n - k)!)
 */

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int resultado = 1;
    for (int i = 2; i <= n; i++)
    {
        resultado *= i;
    }
    return resultado;
}

int coeficienteBinomial(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void generarTrianguloDePascal(int altura)
{
    for (int i = 0; i < altura; i++)
    {
        // Imprimir espacios para alinear el triángulo
        for (int j = 0; j < altura - i - 1; j++)
        {
            printf(" ");
        }

        // Calcular y mostrar los valores del nivel i
        for (int k = 0; k <= i; k++)
        {
            printf("%d ", coeficienteBinomial(i, k));
        }
        printf("\n");
    }
}

int main()
{
    int altura;
    printf("Introduce la altura del Triángulo de Pascal: ");
    scanf("%d", &altura);

    if (altura > 0)
    {
        generarTrianguloDePascal(altura);
    }
    else
    {
        printf("Por favor, introduce un número entero positivo.\n");
    }

    return 0;
}