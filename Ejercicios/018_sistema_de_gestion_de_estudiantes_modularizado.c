#include <stdio.h>
#include "gestor.h"

int main()
{
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int contador = 0;
    int opcion;

    printf("Sistema de Gestión de Estudiantes\n");
    printf("Opciones:\n");
    printf("1. Agregar estudiante\n");
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
            agregarEstudiante(estudiantes, &contador);
            break;
        case 2:
            buscarEstudiante(estudiantes, contador);
            break;
        case 3:
            mostrarEstudiantes(estudiantes, contador);
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