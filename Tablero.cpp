#include <iostream>
#include <vector>
#include "Tablero.h"

Tablero::Tablero() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tablero[i][j] = ' ';
        }
    }
}

    
void Tablero::mostrarTablero() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << tablero[i][j];
            if (j < 2) std::cout << " | "; 
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---------\n"; 
    }
}

    
bool Tablero::colocar(int fila, int columna, char simbolo) {
    if (fila < 0 || fila >= 3 || columna < 0 || columna >= 3) {
        std::cerr << "Posición fuera de rango.\n";
        return false;
    }
    if (tablero[fila][columna] != ' ') {
        std::cerr << "La celda ya está ocupada.\n";
        return false;
    }
    tablero[fila][columna] = simbolo;
    return true;
}

    
bool Tablero::verificarGanador() {

    int i,j=0;
    for(i=0;i<3;i++)
    {
        if(tablero[i][j]!=' ')
        {
            if(tablero[i][j]==tablero[i][j+1] && tablero[i][j]==tablero[i][j+2])
                return true;
        }
    }
    i=0;
    for(j=0;j<3;j++)
    {
        if(tablero[i][j]!=' ')
        {
            if(tablero[i][j]==tablero[i+1][j] && tablero[i][j]==tablero[i+2][j])
                return true;
        }
    }
    i=0;
    j=0;
    if(tablero[i][j]!=' ')
    {
        if(tablero[i][j]==tablero[i+1][j+1]&& tablero[i][j]==tablero[i+2][j+2])
            return true;
    }
    if(tablero[i+2][j]!=' ')
    {
        if(tablero[i+2][j]==tablero[i+1][j+1] && tablero[i+2][j]==tablero[i][j+2])
            return true;
    }
    return false;
}

