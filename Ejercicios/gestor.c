#include <stdio.h>
#include <string.h>
#include "gestor.h"

// Función para agregar un estudiante
void agregarEstudiante(Estudiante estudiantes[], int *contador)
{
    if (*contador >= MAX_ESTUDIANTES)
    {
        printf("El sistema está lleno. No se pueden registrar más estudiantes.\n");
        return;
    }

    printf("Introduce el nombre del estudiante: ");
    scanf(" %[^\n]", estudiantes[*contador].nombre);
    printf("Introduce la matrícula del estudiante: ");
    scanf(" %[^\n]", estudiantes[*contador].matricula);
    printf("Introduce el promedio del estudiante: ");
    scanf("%f", &estudiantes[*contador].promedio);

    (*contador)++;
    printf("Estudiante registrado.\n");
}

// Función para buscar un estudiante por nombre
void buscarEstudiante(Estudiante estudiantes[], int contador)
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
void mostrarEstudiantes(Estudiante estudiantes[], int contador)
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