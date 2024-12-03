#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Ejercicio 007: Juego Simple - Adivina el Número
 *
 * Descripción:
 * Escribe un programa en C que implemente un juego donde el usuario deba adivinar
 * un número generado aleatoriamente entre 1 y 100. El programa debe dar pistas al
 * usuario sobre si el número ingresado es mayor o menor al número objetivo.
 *
 * Requisitos:
 * - Generar un número aleatorio entre 1 y 100 al inicio del juego.
 * - Solicitar al usuario que ingrese un número para intentar adivinar.
 * - Indicar si el número ingresado es mayor, menor o igual al número objetivo.
 * - Contar la cantidad de intentos realizados.
 * - Finalizar cuando el usuario adivine el número.
 *
 * Ejemplo de entrada y salida:
 *
 * Entrada: 50
 * Salida: "El número es mayor. Intenta de nuevo."
 * Entrada: 75
 * Salida: "El número es menor. Intenta de nuevo."
 * Entrada: 62
 * Salida: "¡Felicidades! Adivinaste el número en 3 intentos."
 *
 * Pistas:
 * - Usa la función `rand()` para generar números aleatorios.
 * - Usa un bucle `while` para permitir intentos múltiples.
 * - Usa variables para rastrear el número de intentos.
 */

int main()
{
    int numeroObjetivo, intento, intentos = 0;

    // Inicializar el generador de números aleatorios
    srand(time(NULL));
    numeroObjetivo = rand() % 100 + 1; // Generar un número entre 1 y 100

    printf("¡Bienvenido al juego de adivinanza!\n");
    printf("He pensado en un número entre 1 y 100. ¿Puedes adivinar cuál es?\n");

    do
    {
        // Leer el intento del usuario
        printf("Introduce tu intento: ");
        scanf("%d", &intento);
        intentos++;

        // Proporcionar pistas
        if (intento < numeroObjetivo)
        {
            printf("El número es mayor. Intenta de nuevo.\n");
        }
        else if (intento > numeroObjetivo)
        {
            printf("El número es menor. Intenta de nuevo.\n");
        }
        else
        {
            printf("¡Felicidades! Adivinaste el número en %d intentos.\n", intentos);
        }
    } while (intento != numeroObjetivo);

    return 0;
}