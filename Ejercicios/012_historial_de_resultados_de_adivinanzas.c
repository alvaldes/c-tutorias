#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Ejercicio 012: Historial de Resultados de Adivinanzas
 *
 * Descripción:
 * Escribe un programa en C que implemente un juego de adivinanza donde el usuario
 * debe adivinar un número generado aleatoriamente entre 1 y 100. El programa debe
 * guardar un historial de intentos en un archivo de texto.
 *
 * Requisitos:
 * - Generar un número aleatorio entre 1 y 100 al inicio del juego.
 * - Permitir al usuario realizar múltiples intentos hasta adivinar.
 * - Guardar en un archivo los detalles del juego: número generado, número de intentos y resultados.
 *
 * Ejemplo de entrada y salida:
 *
 * Entrada: 50 (intento)
 * Salida: "El número es mayor. Intenta de nuevo."
 *
 * Entrada: 75 (intento)
 * Salida: "El número es menor. Intenta de nuevo."
 *
 * Entrada: 62 (correcto)
 * Salida: "¡Felicidades! Adivinaste el número en 3 intentos."
 *
 * Historial guardado en archivo:
 * Número objetivo: 62
 * Intentos realizados: 3
 *
 * Pistas:
 * - Usa la función `rand()` para generar números aleatorios.
 * - Usa `fprintf` para escribir el historial en un archivo.
 * - Maneja la apertura y cierre del archivo con `fopen` y `fclose`.
 */

void guardarHistorial(int numeroObjetivo, int intentos)
{
    FILE *archivo = fopen("historial_adivinanzas.txt", "a");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo de historial.\n");
        return;
    }
    fprintf(archivo, "Número objetivo: %d, Intentos realizados: %d\n", numeroObjetivo, intentos);
    fclose(archivo);
    printf("El historial del juego ha sido guardado.\n");
}

int main()
{
    int numeroObjetivo, intento, intentos = 0;

    // Inicializar el generador de números aleatorios
    srand(time(NULL));
    numeroObjetivo = rand() % 100 + 1;

    printf("¡Bienvenido al juego de adivinanza!\n");
    printf("He pensado en un número entre 1 y 100. ¿Puedes adivinar cuál es?\n");

    do
    {
        printf("Introduce tu intento: ");
        scanf("%d", &intento);
        intentos++;

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
            guardarHistorial(numeroObjetivo, intentos);
        }
    } while (intento != numeroObjetivo);

    return 0;
}