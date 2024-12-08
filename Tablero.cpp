#include "Tablero.h"
#include <iostream>
#include <limits>

#define CLEAR "clear" 

using namespace std;


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


bool Tablero::estadoTerminal() {
    int i,j=0;
    for(i=0;i<3;i++)
    {
        if(tabla[i][j]!=' ')
        {
            if(tabla[i][j]==tabla[i][j+1] && tabla[i][j]==tabla[i][j+2])
                return true;
        }
    }
    i=0;
    for(j=0;j<3;j++)
    {
        if(tabla[i][j]!=' ')
        {
            if(tabla[i][j]==tabla[i+1][j] && tabla[i][j]==tabla[i+2][j])
                return true;
        }
    }
    i=0;
    j=0;
    if(tabla[i][j]!=' ')
    {
        if(tabla[i][j]==tabla[i+1][j+1]&& tabla[i][j]==tabla[i+2][j+2])
            return true;
    }
    if(tabla[i+2][j]!=' ')
    {
        if(tabla[i+2][j]==tabla[i+1][j+1] && tabla[i+2][j]==tabla[i][j+2])
            return true;
    }
    return false;
}


bool Tablero::fueraDeRango(int fila, int columna) {
    if (fila < 0 || fila >= 3 || columna < 0 || columna >= 3)
        return true;
    return false;
}


void Tablero::insertarFichaHumano() {
    mostrarTabla();
    if (estadoTerminal()) {
        cout << endl << "PERDISTE. GANADOR CPU" << endl;
        reiniciarTablero();
        return;
    } else if (espaciosLibres == 0) {
        cout << endl << "EL JUEGO TERMINA EN EMPATE." << endl;
        reiniciarTablero();
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


void Tablero::insertarFichaCPU() {
    if (estadoTerminal()) {
        mostrarTabla();
        cout << endl << "GANASTE. GATO TIPICO CHILENO" << endl;
        reiniciarTablero();
        return;
    } else if (espaciosLibres == 0) {
        mostrarTabla();
        reiniciarTablero();
        cout << endl << "EL JUEGO TERMINA EN EMPATE." << endl;
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


void Tablero::elegirFicha(char jugadorFicha) {
    letraJugador = jugadorFicha;
    letraCPU = (jugadorFicha == 'X') ? 'O' : 'X';
}


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
void Tablero::reiniciarTablero() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tabla[i][j] = ' '; 
        }
    }
    espaciosLibres = 9; 
}
char Tablero::getLetraJugador() {
    return this-> letraJugador;
}