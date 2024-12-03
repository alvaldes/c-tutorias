#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Ejercicio 017: Calculadora Segura
 *
 * Descripción:
 * Escribe un programa en C que implemente una calculadora básica. El programa debe
 * manejar errores como la división por cero y validar que las entradas sean números.
 * Las operaciones soportadas son suma, resta, multiplicación y división.
 *
 * Requisitos:
 * - Solicitar al usuario dos números y una operación.
 * - Validar que las entradas sean números válidos.
 * - Manejar la división por cero mostrando un mensaje de error.
 * - Permitir al usuario realizar múltiples operaciones hasta que decida salir.
 *
 * Ejemplo de ejecución:
 *
 * Opciones:
 * 1. Suma
 * 2. Resta
 * 3. Multiplicación
 * 4. División
 * 5. Salir
 *
 * Entrada: 1 (Suma)
 * Número 1: 10
 * Número 2: 5
 * Salida: Resultado: 15
 *
 * Pistas:
 * - Usa bucles para mantener el programa activo hasta que el usuario decida salir.
 * - Usa funciones para realizar las operaciones y validar las entradas.
 */

float realizarOperacion(int opcion, float num1, float num2)
{
    switch (opcion)
    {
    case 1:
        return num1 + num2;
    case 2:
        return num1 - num2;
    case 3:
        return num1 * num2;
    case 4:
        if (num2 == 0)
        {
            printf("Error: No se puede dividir entre cero.\n");
            return NAN; // Retorna un valor no numérico
        }
        return num1 / num2;
    default:
        printf("Operación no válida.\n");
        return NAN;
    }
}

int main()
{
    int opcion;
    float num1, num2, resultado;
    char buffer[50];

    printf("Calculadora Segura\n");
    printf("Opciones:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Salir\n");

    do
    {
        printf("\nSelecciona una opción: ");
        scanf("%d", &opcion);

        if (opcion == 5)
        {
            printf("Saliendo de la calculadora...\n");
            break;
        }

        if (opcion < 1 || opcion > 4)
        {
            printf("Opción no válida. Intenta de nuevo.\n");
            continue;
        }

        printf("Introduce el primer número: ");
        scanf("%s", buffer);
        if (sscanf(buffer, "%f", &num1) != 1)
        {
            printf("Entrada inválida. Debes introducir un número.\n");
            continue;
        }

        printf("Introduce el segundo número: ");
        scanf("%s", buffer);
        if (sscanf(buffer, "%f", &num2) != 1)
        {
            printf("Entrada inválida. Debes introducir un número.\n");
            continue;
        }

        resultado = realizarOperacion(opcion, num1, num2);

        if (!isnan(resultado))
        {
            printf("Resultado: %.2f\n", resultado);
        }
    } while (1);

    return 0;
}