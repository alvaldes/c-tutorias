#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*
 * Ejercicio 019: Temporizador Multitarea
 *
 * Descripción:
 * Escribe un programa en C que implemente dos temporizadores simultáneos utilizando
 * hilos (`pthread`). Cada temporizador cuenta de forma independiente, y ambos se
 * ejecutan al mismo tiempo.
 *
 * Requisitos:
 * - Implementar dos hilos: uno para contar segundos y otro para contar minutos.
 * - Mostrar el progreso de cada temporizador en tiempo real.
 * - Terminar el programa cuando ambos temporizadores completen su tarea.
 *
 * Ejemplo de ejecución:
 *
 * Temporizador 1: 1 segundos
 * Temporizador 2: 1 minutos
 * Temporizador 1: 2 segundos
 * Temporizador 1: 3 segundos
 * ...
 *
 * Pistas:
 * - Usa `pthread_create` para iniciar los hilos.
 * - Usa `pthread_join` para esperar a que los hilos finalicen.
 * - Usa `sleep` para simular el paso del tiempo.
 */

// Función para el temporizador de segundos
void *temporizadorSegundos(void *args)
{
    int segundos = *((int *)args);
    for (int i = 1; i <= segundos; i++)
    {
        printf("Temporizador 1: %d segundos\n", i);
        sleep(1); // Pausa de 1 segundo
    }
    printf("Temporizador 1 completado.\n");
    return NULL;
}

// Función para el temporizador de minutos
void *temporizadorMinutos(void *args)
{
    int minutos = *((int *)args);
    for (int i = 1; i <= minutos; i++)
    {
        printf("Temporizador 2: %d minutos\n", i);
        sleep(60); // Pausa de 60 segundos
    }
    printf("Temporizador 2 completado.\n");
    return NULL;
}

int main()
{
    pthread_t hiloSegundos, hiloMinutos;
    int segundos = 10; // Duración del temporizador de segundos
    int minutos = 1;   // Duración del temporizador de minutos

    printf("Iniciando temporizadores...\n");

    // Crear los hilos
    pthread_create(&hiloSegundos, NULL, temporizadorSegundos, &segundos);
    pthread_create(&hiloMinutos, NULL, temporizadorMinutos, &minutos);

    // Esperar a que los hilos terminen
    pthread_join(hiloSegundos, NULL);
    pthread_join(hiloMinutos, NULL);

    printf("Todos los temporizadores han finalizado.\n");
    return 0;
}