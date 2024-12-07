#include "Tablero.h"
#include <iostream>
#include <limits>

#define CLEAR "clear" // Cambia a "cls" si estás en Windows

using namespace std;

// Constructor
Tablero::Tablero() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tabla[i][j] = ' ';
        }
    }
    espaciosLibres = 9;
    letraJugador = ' ';
    letraCPU = ' ';
}

// Mostrar el tablero
void Tablero::mostrarTabla() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << tabla[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
}

// Verificar si el estado es terminal
bool Tablero::estadoTerminal() {
    for (int i = 0; i < 3; i++) {
        if (tabla[i][0] == tabla[i][1] && tabla[i][1] == tabla[i][2] && tabla[i][0] != ' ')
            return true;
        if (tabla[0][i] == tabla[1][i] && tabla[1][i] == tabla[2][i] && tabla[0][i] != ' ')
            return true;
    }
    if (tabla[0][0] == tabla[1][1] && tabla[1][1] == tabla[2][2] && tabla[0][0] != ' ')
        return true;
    if (tabla[0][2] == tabla[1][1] && tabla[1][1] == tabla[2][0] && tabla[0][2] != ' ')
        return true;
    return false;
}

// Verificar si la posición está fuera de rango
bool Tablero::fueraDeRango(int fila, int columna) {
    return fila < 0 || fila >= 3 || columna < 0 || columna >= 3;
}

// Insertar ficha del jugador
void Tablero::insertarFichaHumano() {
    mostrarTabla();
    if (estadoTerminal()) {
        cout << endl << "GANADOR: CPU" << endl;
        return;
    } else if (espaciosLibres == 0) {
        cout << endl << "LA POSICION TERMINA EN EMPATE. Ultimo turno: CPU" << endl;
        return;
    }

    bool valido;
    int fila, columna;
    do {
        valido = true;
        cout << "Ingrese fila (1-3): ";
        cin >> fila;
        cout << "Ingrese columna (1-3): ";
        cin >> columna;
        if (fueraDeRango(fila - 1, columna - 1) || tabla[fila - 1][columna - 1] != ' ')
            valido = false;
    } while (!valido);

    tabla[fila - 1][columna - 1] = letraJugador;
    espaciosLibres--;
    system(CLEAR);
    insertarFichaCPU();
}

// Insertar ficha de la CPU
void Tablero::insertarFichaCPU() {
    if (estadoTerminal()) {
        mostrarTabla();
        cout << endl << "GANADOR: JUGADOR" << endl;
        return;
    } else if (espaciosLibres == 0) {
        mostrarTabla();
        cout << endl << "LA POSICION TERMINA EN EMPATE. Ultimo turno: Jugador" << endl;
        return;
    }

    int movValor, mejorMovValor = -100;
    int mejorMovFila = -1, mejorMovColumna = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabla[i][j] == ' ') {
                tabla[i][j] = letraCPU;
                espaciosLibres--;
                movValor = minimax(false);
                if (movValor > mejorMovValor) {
                    mejorMovValor = movValor;
                    mejorMovFila = i;
                    mejorMovColumna = j;
                }
                tabla[i][j] = ' ';
                espaciosLibres++;
            }
        }
    }

    tabla[mejorMovFila][mejorMovColumna] = letraCPU;
    espaciosLibres--;
    system(CLEAR);
    insertarFichaHumano();
}

// Elegir ficha para el jugador
void Tablero::elegirFicha(char jugadorFicha) {
    letraJugador = jugadorFicha;
    letraCPU = (jugadorFicha == 'X') ? 'O' : 'X';
}

// Minimax
int Tablero::minimax(bool turnoCPU) {
    if (estadoTerminal()) {
        if (turnoCPU)
            return -1 * (espaciosLibres + 1);
        else
            return 1 * (espaciosLibres + 1);
    } else if (espaciosLibres == 0)
        return 0;

    int mejorValor, valMinimax, modificador;
    char ficha;

    if (turnoCPU) {
        mejorValor = -100;
        modificador = 1;
        turnoCPU = false;
        ficha = letraCPU;
    } else {
        mejorValor = 100;
        modificador = -1;
        turnoCPU = true;
        ficha = letraJugador;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabla[i][j] == ' ') {
                tabla[i][j] = ficha;
                espaciosLibres--;
                valMinimax = minimax(turnoCPU);
                if (valMinimax * modificador > mejorValor * modificador)
                    mejorValor = valMinimax;
                tabla[i][j] = ' ';
                espaciosLibres++;
            }
        }
    }
    return mejorValor;
}