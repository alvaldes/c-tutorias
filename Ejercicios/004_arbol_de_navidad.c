#include <stdio.h>

/*
 * Ejercicio 001: Árbol de Navidad
 *
 * Descripción:
 * Escribe un programa en C que imprima un árbol de Navidad en la consola.
 * El tamaño del árbol debe ser determinado por un número entero positivo
 * ingresado por el usuario. El árbol debe estar compuesto por caracteres
 * asterisco (*) y debe tener una base rectangular.
 *
 * Requisitos:
 * - El programa debe solicitar al usuario que ingrese un número entero positivo.
 * - El árbol debe tener una forma triangular con una base rectangular.
 * - La altura del árbol debe ser igual al número ingresado por el usuario.
 * - La base del árbol debe tener una altura de 2 líneas y un ancho de 3 caracteres.
 *
 * Ejemplo de entrada y salida:
 *
 * Entrada: 5
 * Salida:
 *
 *     *
 *    ***
 *   *****
 *  *******
 * *********
 *    ***
 *    ***
 *
 * Pistas:
 * - Utiliza bucles anidados para generar las líneas del árbol.
 * - Considera el uso de espacios en blanco para alinear correctamente los asteriscos.
 * - La base del árbol puede ser generada con un bucle separado después de generar la parte triangular.
 */

int centrado(int altura)
{
    int i, j, k;
    for (i = 0; i < altura; i++)
    {
        // Para centrar el árbol, se agregan espacios en blanco antes de imprimir los asteriscos
        for (k = 0; k < altura - i - 1; k++)
        {
            printf(" ");
        }

        for (j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // --------------------------
    // Generar la base del árbol
    int base_altura = altura / 3; // La altura de la base es un tercio de la altura del árbol
    int base_ancho = 3;

    for (i = 0; i < base_altura + 1; i++)
    {
        for (k = 0; k < (2 * altura - 1 - base_ancho) / 2; k++)
        {
            printf(" ");
        }
        for (j = 0; j < base_ancho; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    // --------------------------

    return 0;
}

int main()
{
    centrado(5);
    return 0;
}
