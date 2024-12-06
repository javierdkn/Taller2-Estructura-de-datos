#include <iostream>
#include <vector>
#include "Tablero.h"

class Tablero3x3 {
private:
    char tablero[3][3]; 

public:
    
    Tablero3x3() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                tablero[i][j] = ' ';
            }
        }
    }

    
    void mostrarTablero() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << tablero[i][j];
                if (j < 2) std::cout << " | "; 
            }
            std::cout << "\n";
            if (i < 2) std::cout << "---------\n"; 
        }
    }

    
    bool colocar(int fila, int columna, char simbolo) {
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

    
    char verificarGanador() {
        
        for (int i = 0; i < 3; ++i) {
            if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ')
                return tablero[i][0];
            if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ')
                return tablero[0][i];
        }
        
        if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ')
            return tablero[0][0];
        if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ')
            return tablero[0][2];

        return ' '; 
    }
};