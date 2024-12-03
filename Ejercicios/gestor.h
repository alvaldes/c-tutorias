#ifndef GESTOR_H
#define GESTOR_H

#define MAX_ESTUDIANTES 100

typedef struct
{
    char nombre[50];
    char matricula[20];
    float promedio;
} Estudiante;

void agregarEstudiante(Estudiante estudiantes[], int *contador);
void buscarEstudiante(Estudiante estudiantes[], int contador);
void mostrarEstudiantes(Estudiante estudiantes[], int contador);

#endif