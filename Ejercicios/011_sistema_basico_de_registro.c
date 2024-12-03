#include <stdio.h>
#include <string.h>

/*
 * Ejercicio 011: Sistema Básico de Registro
 *
 * Descripción:
 * Escribe un programa en C que permita registrar estudiantes, buscar por nombre
 * y mostrar la lista de estudiantes registrados. Cada estudiante tiene un nombre,
 * una matrícula y un promedio.
 *
 * Requisitos:
 * - Registrar hasta 50 estudiantes en memoria.
 * - Permitir buscar un estudiante por nombre y mostrar su información.
 * - Mostrar la lista completa de estudiantes.
 * - Finalizar el programa cuando el usuario lo decida.
 *
 * Ejemplo de ejecución:
 *
 * Opciones:
 * 1. Registrar estudiante
 * 2. Buscar estudiante
 * 3. Mostrar lista de estudiantes
 * 4. Salir
 *
 * Entrada: 1 (Registrar)
 * Nombre: "Juan", Matrícula: "A123", Promedio: 8.5
 * Salida: "Estudiante registrado."
 *
 * Entrada: 2 (Buscar "Juan")
 * Salida: "Nombre: Juan, Matrícula: A123, Promedio: 8.5"
 *
 * Entrada: 3 (Mostrar lista)
 * Salida:
 *   1. Juan - A123 - 8.5
 *   2. María - B456 - 9.2
 *
 * Pistas:
 * - Usa un arreglo de estructuras para almacenar la información de los estudiantes.
 * - Maneja índices para controlar el registro.
 */

#define MAX_ESTUDIANTES 50

// Definir la estructura Estudiante
typedef struct
{
    char nombre[50];
    char matricula[20];
    float promedio;
} Estudiante;

Estudiante estudiantes[MAX_ESTUDIANTES];
int contador = 0;

// Función para registrar un estudiante
void registrarEstudiante()
{
    if (contador >= MAX_ESTUDIANTES)
    {
        printf("El sistema está lleno. No se pueden registrar más estudiantes.\n");
        return;
    }

    printf("Introduce el nombre del estudiante: ");
    scanf(" %[^\n]", estudiantes[contador].nombre);
    printf("Introduce la matrícula del estudiante: ");
    scanf(" %[^\n]", estudiantes[contador].matricula);
    printf("Introduce el promedio del estudiante: ");
    scanf("%f", &estudiantes[contador].promedio);

    contador++;
    printf("Estudiante registrado.\n");
}

// Función para buscar un estudiante por nombre
void buscarEstudiante()
{
    char nombreBuscado[50];
    printf("Introduce el nombre del estudiante que deseas buscar: ");
    scanf(" %[^\n]", nombreBuscado);

    for (int i = 0; i < contador; i++)
    {
        if (strcmp(estudiantes[i].nombre, nombreBuscado) == 0)
        {
            printf("Nombre: %s, Matrícula: %s, Promedio: %.2f\n",
                   estudiantes[i].nombre, estudiantes[i].matricula, estudiantes[i].promedio);
            return;
        }
    }

    printf("Estudiante no encontrado.\n");
}

// Función para mostrar la lista de estudiantes
void mostrarEstudiantes()
{
    if (contador == 0)
    {
        printf("No hay estudiantes registrados.\n");
        return;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d. %s - %s - %.2f\n", i + 1, estudiantes[i].nombre, estudiantes[i].matricula, estudiantes[i].promedio);
    }
}

int main()
{
    int opcion;

    printf("Sistema Básico de Registro de Estudiantes\n");
    printf("Opciones:\n");
    printf("1. Registrar estudiante\n");
    printf("2. Buscar estudiante\n");
    printf("3. Mostrar lista de estudiantes\n");
    printf("4. Salir\n");

    do
    {
        printf("\nSelecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            registrarEstudiante();
            break;
        case 2:
            buscarEstudiante();
            break;
        case 3:
            mostrarEstudiantes();
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