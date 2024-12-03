#include <stdio.h>

/*
 * Ejercicio 006: Calculadora
 *
 * Descripción:
 * Escribe un programa en C que implemente una calculadora básica. El programa debe
 * permitir realizar operaciones de suma, resta, multiplicación y división entre dos números.
 * El usuario debe poder seleccionar la operación desde un menú.
 *
 * Requisitos:
 * - Solicitar al usuario dos números.
 * - Mostrar un menú con las opciones disponibles: suma, resta, multiplicación, división.
 * - Ejecutar la operación seleccionada y mostrar el resultado.
 * - Manejar el caso de división entre cero mostrando un mensaje de error.
 *
 * Ejemplo de entrada y salida:
 *
 * Entrada:
 *   Número 1: 10
 *   Número 2: 5
 *   Opción: 1 (suma)
 * Salida:
 *   Resultado: 15
 *
 * Pistas:
 * - Usa un `switch` para manejar las opciones del menú.
 * - Valida que el denominador en la división no sea cero.
 */

void mostrarMenu()
{
    printf("Selecciona una operación:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Salir\n");
    printf("Opción: ");
}

int main()
{
    int opcion;
    float num1, num2, resultado;

    do
    {
        // Mostrar el menú y leer la opción del usuario
        mostrarMenu();
        scanf("%d", &opcion);

        // Salir si la opción es 5
        if (opcion == 5)
        {
            printf("Saliendo de la calculadora...\n");
            break;
        }

        // Solicitar los números
        printf("Introduce el primer número: ");
        scanf("%f", &num1);
        printf("Introduce el segundo número: ");
        scanf("%f", &num2);

        // Ejecutar la operación seleccionada
        switch (opcion)
        {
        case 1: // Suma
            resultado = num1 + num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 2: // Resta
            resultado = num1 - num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 3: // Multiplicación
            resultado = num1 * num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case 4: // División
            if (num2 != 0)
            {
                resultado = num1 / num2;
                printf("Resultado: %.2f\n", resultado);
            }
            else
            {
                printf("Error: No se puede dividir entre cero.\n");
            }
            break;
        default:
            printf("Opción no válida. Intenta de nuevo.\n");
        }
        printf("\n");
    } while (opcion != 5);

    return 0;
}