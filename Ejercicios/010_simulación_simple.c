#include <stdio.h>
#include <stdbool.h>

/*
 * Ejercicio 010: Simulación Simple - Cola de Clientes en un Banco
 *
 * Descripción:
 * Escribe un programa en C que simule la gestión de una cola de clientes en un banco.
 * Los clientes llegan y son atendidos por orden de llegada. El programa debe permitir
 * agregar clientes, atender al cliente al frente de la cola y mostrar la cola actual.
 *
 * Requisitos:
 * - La cola debe tener un tamaño máximo de 10 clientes.
 * - Permitir al usuario agregar clientes con su nombre.
 * - Permitir atender al cliente en la parte frontal de la cola.
 * - Mostrar el estado actual de la cola.
 * - Finalizar el programa cuando el usuario lo decida.
 *
 * Ejemplo de ejecución:
 *
 * Opciones:
 * 1. Agregar cliente
 * 2. Atender cliente
 * 3. Mostrar cola
 * 4. Salir
 *
 * Entrada: 1 (Agregar cliente "Juan")
 * Salida: Cliente "Juan" agregado a la cola.
 *
 * Entrada: 2 (Atender cliente)
 * Salida: Cliente "Juan" ha sido atendido.
 *
 * Entrada: 3 (Mostrar cola)
 * Salida: Clientes en la cola: ["María", "Carlos"]
 *
 * Pistas:
 * - Usa un arreglo para almacenar los nombres de los clientes.
 * - Maneja un índice de inicio y final para la cola.
 */

#define MAX_COLA 10

// Declarar la cola y sus índices
char cola[MAX_COLA][50];
int inicio = 0;
int final = 0;

// Verificar si la cola está vacía
bool colaVacia()
{
    return inicio == final;
}

// Verificar si la cola está llena
bool colaLlena()
{
    return (final - inicio) == MAX_COLA;
}

// Agregar un cliente a la cola
void agregarCliente()
{
    if (colaLlena())
    {
        printf("La cola está llena. No se puede agregar más clientes.\n");
        return;
    }
    printf("Introduce el nombre del cliente: ");
    scanf("%s", cola[final % MAX_COLA]);
    final++;
    printf("Cliente agregado a la cola.\n");
}

// Atender al cliente al frente de la cola
void atenderCliente()
{
    if (colaVacia())
    {
        printf("No hay clientes en la cola.\n");
        return;
    }
    printf("Cliente '%s' ha sido atendido.\n", cola[inicio % MAX_COLA]);
    inicio++;
}

// Mostrar los clientes en la cola
void mostrarCola()
{
    if (colaVacia())
    {
        printf("La cola está vacía.\n");
        return;
    }
    printf("Clientes en la cola:\n");
    for (int i = inicio; i < final; i++)
    {
        printf("- %s\n", cola[i % MAX_COLA]);
    }
}

int main()
{
    int opcion;

    printf("Simulación de Cola de Clientes en un Banco\n");
    printf("Opciones:\n");
    printf("1. Agregar cliente\n");
    printf("2. Atender cliente\n");
    printf("3. Mostrar cola\n");
    printf("4. Salir\n");

    do
    {
        printf("\nSelecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarCliente();
            break;
        case 2:
            atenderCliente();
            break;
        case 3:
            mostrarCola();
            break;
        case 4:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no válida. Intenta de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}