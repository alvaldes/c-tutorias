#include <stdio.h>

/*
 * Ejercicio 005: Ordenamiento de Números
 *
 * Descripción:
 * Escribe un programa en C que ordene un conjunto de números ingresados por el usuario.
 * El programa debe solicitar al usuario la cantidad de números y los números a ordenar,
 * y luego mostrar el arreglo en orden ascendente utilizando el algoritmo de burbuja.
 *
 * Requisitos:
 * - Solicitar al usuario la cantidad de números a ordenar.
 * - Leer los números desde la entrada estándar.
 * - Utilizar el algoritmo de burbuja para ordenar los números en orden ascendente.
 * - Mostrar el arreglo ordenado.
 *
 * Ejemplo de entrada y salida:
 *
 * Entrada:
 *   Cantidad: 5
 *   Números: 34 7 23 32 5
 * Salida:
 *   Números ordenados: 5 7 23 32 34
 *
 * Pistas:
 * - Utiliza un arreglo para almacenar los números.
 * - Implementa bucles anidados para realizar el algoritmo de burbuja.
 */

void ordenarBurbuja(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Intercambiar los elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int cantidad;

    // Solicitar la cantidad de números
    printf("Introduce la cantidad de números: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0)
    {
        printf("La cantidad de números debe ser mayor a 0.\n");
        return 1;
    }

    int numeros[cantidad];

    // Leer los números
    printf("Introduce los %d números separados por espacio: ", cantidad);
    for (int i = 0; i < cantidad; i++)
    {
        scanf("%d", &numeros[i]);
    }

    // Ordenar los números
    ordenarBurbuja(numeros, cantidad);

    // Mostrar los números ordenados
    printf("Números ordenados: ");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}