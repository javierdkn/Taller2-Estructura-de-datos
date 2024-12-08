#include <iostream>
#include "Tablero.h"

using namespace std;

char letraJugador;


void insertarFichaCPU(Tablero &tablero){
    tablero.insertarFichaCPU();
}

void insertarFichaHumano(Tablero &tablero) {
    tablero.insertarFichaHumano();
}

void comenzarJuego(Tablero &tablero) {
    
    if (letraJugador == ' ') {
        cout << "ERROR: No se ha elegido una ficha para el jugador." << endl;
        return;
    }
    
    if (letraJugador == 'X')
        insertarFichaHumano(tablero);
    else
        insertarFichaHumano(tablero);

    
}

void elegirValor(Tablero &tablero) {
    int opcion;

    cout << "Ingrese con qué valor desea jugar:\n";
    cout << "1. X (comenzar primero)\n";
    cout << "2. O (comenzar segundo)\n";

    do {
        cout << "Opción elegida: ";
        cin >> opcion;

        if (opcion == 1) {
            tablero.elegirFicha('X');
        } else if (opcion == 2) {
            tablero.elegirFicha('O');
        } else {
            cout << "ERROR: La opción elegida no es válida. Intente de nuevo.\n";
        }
    } while (opcion != 1 && opcion != 2);
}

void ejecutarMenu() {
    Tablero tablero;
    int opcion;

    while (true) {
        cout << "Bienvenido/a juguemos al GATO.\n";
        cout << "1. Elegir ficha\n";
        cout << "2. Comenzar juego\n";
        cout << "3. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                elegirValor(tablero);
                break;
            case 2:
                comenzarJuego(tablero);
                break;
            case 3:
                cout << "Saliendo del GATO. ¡Hasta luego!\n";
                return;
            default:
                cout << "ERROR: Opción inválida.\n";
        }

        cout << endl; 
    }
}

/* metodo mostra menu para 1vs1
void mostrarMenu() {
    std::cout << "==== TRES EN LINEA ====\n";
    std::cout << "1. Jugar\n";
    std::cout << "2. Salir\n";
    std::cout << "Elige una opción: ";
}
*/

/* metodo para comprobar que funciona el 1vs1
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
*/


int main() {   
    /*
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
    */

    ejecutarMenu();
    return 0;
}
