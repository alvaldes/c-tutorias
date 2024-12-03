#include <stdio.h>
#include <string.h>

/*
 * Ejercicio 013: Lista de Contactos
 *
 * Descripción:
 * Escribe un programa en C que permita gestionar una lista de contactos. Cada
 * contacto debe tener un nombre, un número de teléfono y una dirección. El
 * programa debe permitir agregar contactos, buscar un contacto por nombre y
 * mostrar la lista completa de contactos.
 *
 * Requisitos:
 * - Registrar hasta 100 contactos en memoria.
 * - Buscar un contacto por nombre.
 * - Mostrar la lista completa de contactos.
 *
 * Ejemplo de ejecución:
 *
 * Opciones:
 * 1. Agregar contacto
 * 2. Buscar contacto
 * 3. Mostrar lista de contactos
 * 4. Salir
 *
 * Entrada: 1 (Agregar contacto)
 * Nombre: "Juan", Teléfono: "123456789", Dirección: "Calle Falsa 123"
 * Salida: "Contacto registrado."
 *
 * Entrada: 2 (Buscar contacto "Juan")
 * Salida: "Nombre: Juan, Teléfono: 123456789, Dirección: Calle Falsa 123"
 *
 * Entrada: 3 (Mostrar lista)
 * Salida:
 *   1. Juan - 123456789 - Calle Falsa 123
 *   2. María - 987654321 - Av. Principal 456
 *
 * Pistas:
 * - Usa un arreglo de estructuras para almacenar los contactos.
 * - Define una función para buscar contactos por nombre.
 * - Maneja índices para gestionar los registros.
 */

#define MAX_CONTACTOS 100

// Definir la estructura Contacto
typedef struct
{
    char nombre[50];
    char telefono[15];
    char direccion[100];
} Contacto;

Contacto contactos[MAX_CONTACTOS];
int contador = 0;

// Función para agregar un contacto
void agregarContacto()
{
    if (contador >= MAX_CONTACTOS)
    {
        printf("La lista de contactos está llena.\n");
        return;
    }

    printf("Introduce el nombre: ");
    scanf(" %[^\n]", contactos[contador].nombre);
    printf("Introduce el teléfono: ");
    scanf(" %[^\n]", contactos[contador].telefono);
    printf("Introduce la dirección: ");
    scanf(" %[^\n]", contactos[contador].direccion);

    contador++;
    printf("Contacto registrado.\n");
}

// Función para buscar un contacto por nombre
void buscarContacto()
{
    char nombreBuscado[50];
    printf("Introduce el nombre del contacto que deseas buscar: ");
    scanf(" %[^\n]", nombreBuscado);

    for (int i = 0; i < contador; i++)
    {
        if (strcmp(contactos[i].nombre, nombreBuscado) == 0)
        {
            printf("Nombre: %s, Teléfono: %s, Dirección: %s\n",
                   contactos[i].nombre, contactos[i].telefono, contactos[i].direccion);
            return;
        }
    }

    printf("Contacto no encontrado.\n");
}

// Función para mostrar la lista de contactos
void mostrarContactos()
{
    if (contador == 0)
    {
        printf("No hay contactos registrados.\n");
        return;
    }

    printf("Lista de contactos:\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d. %s - %s - %s\n", i + 1, contactos[i].nombre, contactos[i].telefono, contactos[i].direccion);
    }
}

int main()
{
    int opcion;

    printf("Sistema de Gestión de Contactos\n");
    printf("Opciones:\n");
    printf("1. Agregar contacto\n");
    printf("2. Buscar contacto\n");
    printf("3. Mostrar lista de contactos\n");
    printf("4. Salir\n");

    do
    {
        printf("\nSelecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarContacto();
            break;
        case 2:
            buscarContacto();
            break;
        case 3:
            mostrarContactos();
            break;
        case 4:
            printf("Saliendo del sistema...\n");
            break;
        default:
            printf("Opción no válida. Intenta de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}