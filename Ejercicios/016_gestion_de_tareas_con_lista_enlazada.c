#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Ejercicio 016: Gestión de Tareas con Lista Enlazada
 *
 * Descripción:
 * Escribe un programa en C que implemente una lista enlazada para gestionar tareas.
 * Cada tarea debe tener un título, una descripción y un estado (pendiente/completada).
 *
 * Requisitos:
 * - Permitir agregar tareas a la lista.
 * - Permitir marcar tareas como completadas.
 * - Mostrar la lista completa de tareas con sus estados.
 *
 * Ejemplo de ejecución:
 *
 * Opciones:
 * 1. Agregar tarea
 * 2. Completar tarea
 * 3. Mostrar tareas
 * 4. Salir
 *
 * Entrada: 1 (Agregar tarea)
 * Título: "Comprar pan", Descripción: "Ir a la tienda y comprar pan"
 * Salida: "Tarea agregada."
 *
 * Entrada: 3 (Mostrar tareas)
 * Salida:
 *   1. [Pendiente] Comprar pan - Ir a la tienda y comprar pan
 *
 * Pistas:
 * - Usa estructuras para definir los nodos de la lista enlazada.
 * - Maneja punteros para agregar y actualizar nodos.
 */

typedef struct Tarea
{
    char titulo[50];
    char descripcion[100];
    int completada; // 0: Pendiente, 1: Completada
    struct Tarea *siguiente;
} Tarea;

Tarea *inicio = NULL;

// Función para agregar una tarea
void agregarTarea()
{
    Tarea *nuevaTarea = (Tarea *)malloc(sizeof(Tarea));
    if (nuevaTarea == NULL)
    {
        printf("Error al asignar memoria.\n");
        return;
    }

    printf("Introduce el título de la tarea: ");
    scanf(" %[^\n]", nuevaTarea->titulo);
    printf("Introduce la descripción de la tarea: ");
    scanf(" %[^\n]", nuevaTarea->descripcion);
    nuevaTarea->completada = 0;
    nuevaTarea->siguiente = inicio;
    inicio = nuevaTarea;

    printf("Tarea agregada.\n");
}

// Función para marcar una tarea como completada
void completarTarea()
{
    int numero, contador = 1;
    Tarea *actual = inicio;

    if (actual == NULL)
    {
        printf("No hay tareas en la lista.\n");
        return;
    }

    mostrarTareas();
    printf("Introduce el número de la tarea que deseas completar: ");
    scanf("%d", &numero);

    while (actual != NULL)
    {
        if (contador == numero)
        {
            actual->completada = 1;
            printf("Tarea '%s' marcada como completada.\n", actual->titulo);
            return;
        }
        actual = actual->siguiente;
        contador++;
    }

    printf("Número de tarea no válido.\n");
}

// Función para mostrar la lista de tareas
void mostrarTareas()
{
    Tarea *actual = inicio;
    int contador = 1;

    if (actual == NULL)
    {
        printf("No hay tareas en la lista.\n");
        return;
    }

    printf("Lista de tareas:\n");
    while (actual != NULL)
    {
        printf("%d. [%s] %s - %s\n", contador,
               actual->completada ? "Completada" : "Pendiente",
               actual->titulo, actual->descripcion);
        actual = actual->siguiente;
        contador++;
    }
}

int main()
{
    int opcion;

    printf("Gestión de Tareas con Lista Enlazada\n");
    printf("Opciones:\n");
    printf("1. Agregar tarea\n");
    printf("2. Completar tarea\n");
    printf("3. Mostrar tareas\n");
    printf("4. Salir\n");

    do
    {
        printf("\nSelecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarTarea();
            break;
        case 2:
            completarTarea();
            break;
        case 3:
            mostrarTareas();
            break;
        case 4:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no válida. Intenta de nuevo.\n");
        }
    } while (opcion != 4);

    // Liberar memoria dinámica
    Tarea *actual = inicio;
    while (actual != NULL)
    {
        Tarea *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    return 0;
}