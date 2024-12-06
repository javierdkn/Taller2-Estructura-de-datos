#include <iostream>
#include <vector>
#include <string>
#include "Tablero.h"

using namespace std;

void mostrarMenu() {
    std::cout << "==== TRES EN LINEA ====\n";
    std::cout << "1. Jugar\n";
    std::cout << "2. Salir\n";
    std::cout << "Elige una opción: ";
}

void jugar() {
    Tablero tablero;
    char jugadorActual = 'X'; // X comienza primero.
    int fila, columna;
    bool juegoTerminado = false;

    std::cout << "\n=== INICIO DEL JUEGO ===\n";

    while (!juegoTerminado) {
        // Mostrar el tablero actual.
        tablero.mostrarTablero();

        // Pedir al jugador actual que haga su movimiento.
        std::cout << "\nTurno del jugador " << jugadorActual << ".\n";
        std::cout << "Ingresa la fila (0-2): ";
        std::cin >> fila;
        std::cout << "Ingresa la columna (0-2): ";
        std::cin >> columna;

        // Intentar colocar el símbolo en el tablero.
        if (!tablero.colocar(fila, columna, jugadorActual)) {
            std::cout << "Movimiento inválido, intenta nuevamente.\n";
            continue;
        }

        // Verificar si hay un ganador.
        char ganador = tablero.verificarGanador();
        if (ganador != ' ') {
            tablero.mostrarTablero();
            std::cout << "\n¡El jugador " << ganador << " gana!\n";
            juegoTerminado = true;
        } else {
            // Cambiar de jugador.
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';

            // Verificar si el tablero está lleno.
            bool lleno = true;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (tablero.colocar(i, j, ' ')) {
                        lleno = false;
                        break;
                    }
                }
                if (!lleno) break;
            }
            if (lleno) {
                tablero.mostrarTablero();
                std::cout << "\n¡Empate! El tablero está lleno.\n";
                juegoTerminado = true;
            }
        }
    }
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            jugar();
            break;
        case 2:
            std::cout << "Gracias por jugar. ¡Hasta luego!\n";
            break;
        default:
            std::cout << "Opción inválida, intenta nuevamente.\n";
        }
    } while (opcion != 2);

    return 0;
}
