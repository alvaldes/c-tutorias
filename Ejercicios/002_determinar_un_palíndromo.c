#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Ejercicio 002: Determinar un Palíndromo
 *
 * Descripción:
 * Escribe un programa en C que determine si una palabra ingresada por el usuario
 * es un palíndromo. Un palíndromo es una palabra que se lee igual de izquierda
 * a derecha y de derecha a izquierda, ignorando mayúsculas y minúsculas.
 *
 * Requisitos:
 * - El programa debe solicitar al usuario que ingrese una palabra.
 * - Ignorar diferencias entre mayúsculas y minúsculas.
 * - Mostrar un mensaje indicando si la palabra es o no un palíndromo.
 *
 * Ejemplo de entrada y salida:
 *
 * Entrada: "radar"
 * Salida: "La palabra 'radar' es un palíndromo."
 *
 * Entrada: "Hola"
 * Salida: "La palabra 'Hola' no es un palíndromo."
 *
 * Pistas:
 * - Usa un bucle para comparar los caracteres de la palabra.
 * - Convierte los caracteres a minúsculas para ignorar diferencias.
 * - Recorre la palabra desde ambos extremos hacia el centro.
 */

int esPalindromo(char palabra[])
{
    int inicio = 0;
    int fin = strlen(palabra) - 1;

    while (inicio < fin)
    {
        // Convertir a minúsculas para ignorar diferencias de mayúsculas/minúsculas
        if (tolower(palabra[inicio]) != tolower(palabra[fin]))
        {
            return 0; // No es un palíndromo
        }
        inicio++;
        fin--;
    }

    return 1; // Es un palíndromo
}

int main()
{
    char palabra[100];

    printf("Introduce una palabra: ");
    scanf("%s", palabra);

    if (esPalindromo(palabra))
    {
        printf("La palabra '%s' es un palíndromo.\n", palabra);
    }
    else
    {
        printf("La palabra '%s' no es un palíndromo.\n", palabra);
    }

    return 0;
}