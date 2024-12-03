#include <stdio.h>
#include <stdlib.h>

/*
 * Ejercicio 014: Calculadora con Tamaño Dinámico
 *
 * Descripción:
 * Escribe un programa en C que implemente una calculadora básica con operaciones
 * de suma, resta, multiplicación y división. Los resultados de las operaciones deben
 * almacenarse en un arreglo dinámico, y el tamaño del arreglo debe ajustarse
 * automáticamente según sea necesario.
 *
 * Requisitos:
 * - Ofrecer un menú para seleccionar la operación y mostrar el historial.
 * - Permitir agregar resultados al arreglo dinámico.
 * - Ajustar el tamaño del arreglo dinámico según la cantidad de resultados.
 *
 * Ejemplo de ejecución:
 *
 * Opciones:
 * 1. Suma
 * 2. Resta
 * 3. Multiplicación
 * 4. División
 * 5. Mostrar historial
 * 6. Salir
 *
 * Entrada: 1 (Suma)
 * Número 1: 5
 * Número 2: 3
 * Salida: Resultado: 8
 *
 * Entrada: 5 (Mostrar historial)
 * Salida: Historial de resultados: [8]
 *
 * Pistas:
 * - Usa `malloc` y `realloc` para manejar la memoria dinámica.
 * - Usa un arreglo dinámico para almacenar los resultados.
 */

void agregarResultado(float **historial, int *contador, int *capacidad, float resultado)
{
    if (*contador >= *capacidad)
    {
        *capacidad *= 2; // Duplicar la capacidad
        *historial = (float *)realloc(*historial, *capacidad * sizeof(float));
        if (*historial == NULL)
        {
            printf("Error: No se pudo asignar más memoria.\n");
            exit(1);
        }
    }
    (*historial)[*contador] = resultado;
    (*contador)++;
}

void mostrarHistorial(float *historial, int contador)
{
    if (contador == 0)
    {
        printf("No hay resultados en el historial.\n");
        return;
    }
    printf("Historial de resultados:\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%.2f ", historial[i]);
    }
    printf("\n");
}

int main()
{
    int opcion, contador = 0, capacidad = 2;
    float numero1, numero2, resultado;
    float *historial = (float *)malloc(capacidad * sizeof(float));
    if (historial == NULL)
    {
        printf("Error: No se pudo asignar memoria inicial.\n");
        return 1;
    }

    printf("Calculadora con Tamaño Dinámico\n");
    printf("Opciones:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Mostrar historial\n");
    printf("6. Salir\n");

    do
    {
        printf("\nSelecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1: // Suma
            printf("Introduce el primer número: ");
            scanf("%f", &numero1);
            printf("Introduce el segundo número: ");
            scanf("%f", &numero2);
            resultado = numero1 + numero2;
            printf("Resultado: %.2f\n", resultado);
            agregarResultado(&historial, &contador, &capacidad, resultado);
            break;

        case 2: // Resta
            printf("Introduce el primer número: ");
            scanf("%f", &numero1);
            printf("Introduce el segundo número: ");
            scanf("%f", &numero2);
            resultado = numero1 - numero2;
            printf("Resultado: %.2f\n", resultado);
            agregarResultado(&historial, &contador, &capacidad, resultado);
            break;

        case 3: // Multiplicación
            printf("Introduce el primer número: ");
            scanf("%f", &numero1);
            printf("Introduce el segundo número: ");
            scanf("%f", &numero2);
            resultado = numero1 * numero2;
            printf("Resultado: %.2f\n", resultado);
            agregarResultado(&historial, &contador, &capacidad, resultado);
            break;

        case 4: // División
            printf("Introduce el primer número: ");
            scanf("%f", &numero1);
            printf("Introduce el segundo número: ");
            scanf("%f", &numero2);
            if (numero2 != 0)
            {
                resultado = numero1 / numero2;
                printf("Resultado: %.2f\n", resultado);
                agregarResultado(&historial, &contador, &capacidad, resultado);
            }
            else
            {
                printf("Error: No se puede dividir entre cero.\n");
            }
            break;

        case 5: // Mostrar historial
            mostrarHistorial(historial, contador);
            break;

        case 6: // Salir
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción no válida. Intenta de nuevo.\n");
        }
    } while (opcion != 6);

    // Liberar memoria dinámica
    free(historial);

    return 0;
}