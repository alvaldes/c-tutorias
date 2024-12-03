#include <stdio.h>
#include <stdbool.h>

/*
 * Ejercicio 009: Juego del Tres en Raya (Tic-Tac-Toe)
 *
 * Descripción:
 * Escribe un programa en C que implemente el juego del tres en raya para dos jugadores.
 * El programa debe permitir que los jugadores coloquen sus marcas en un tablero
 * de 3x3 y determinar quién gana o si hay un empate.
 *
 * Requisitos:
 * - Mostrar el tablero en cada turno.
 * - Validar que las posiciones ingresadas sean válidas y no estén ocupadas.
 * - Determinar si hay un ganador o si el juego termina en empate.
 *
 * Ejemplo de ejecución:
 *
 * Entrada:
 *   Jugador 1 coloca 'X' en (1, 1)
 *   Jugador 2 coloca 'O' en (0, 2)
 *
 * Salida:
 *   Tablero:
 *    O |   |
 *   ---+---+---
 *      | X |
 *   ---+---+---
 *      |   |
 *
 * Pistas:
 * - Usa una matriz de caracteres para representar el tablero.
 * - Define una función para verificar el estado del juego.
 * - Alterna entre los jugadores en cada turno.
 */

// Definir el tablero
char tablero[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Mostrar el tablero en la consola
void mostrarTablero()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", tablero[i][j]);
            if (j < 2)
                printf("|");
        }
        if (i < 2)
            printf("\n---+---+---\n");
    }
    printf("\n");
}

// Verificar si hay un ganador
bool verificarGanador(char marca)
{
    // Verificar filas y columnas
    for (int i = 0; i < 3; i++)
    {
        if ((tablero[i][0] == marca && tablero[i][1] == marca && tablero[i][2] == marca) ||
            (tablero[0][i] == marca && tablero[1][i] == marca && tablero[2][i] == marca))
        {
            return true;
        }
    }
    // Verificar diagonales
    if ((tablero[0][0] == marca && tablero[1][1] == marca && tablero[2][2] == marca) ||
        (tablero[0][2] == marca && tablero[1][1] == marca && tablero[2][0] == marca))
    {
        return true;
    }
    return false;
}

// Verificar si el tablero está lleno
bool tableroLleno()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int fila, columna;
    char jugadorActual = 'X';

    printf("¡Bienvenido al juego del Tres en Raya!\n");
    printf("Jugador 1: X\nJugador 2: O\n");

    while (true)
    {
        mostrarTablero();
        printf("Turno del jugador %c. Introduce la fila y columna (0-2): ", jugadorActual);
        scanf("%d %d", &fila, &columna);

        // Validar la posición ingresada
        if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ')
        {
            printf("Movimiento inválido. Intenta de nuevo.\n");
            continue;
        }

        // Realizar el movimiento
        tablero[fila][columna] = jugadorActual;

        // Verificar si hay un ganador
        if (verificarGanador(jugadorActual))
        {
            mostrarTablero();
            printf("¡Felicidades! El jugador %c ha ganado.\n", jugadorActual);
            break;
        }

        // Verificar si hay empate
        if (tableroLleno())
        {
            mostrarTablero();
            printf("El juego termina en empate.\n");
            break;
        }

        // Cambiar de jugador
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    return 0;
}