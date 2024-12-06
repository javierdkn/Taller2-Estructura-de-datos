#include <iostream>
#include <vector>

class Tablero3x3 {
private:
    char tablero[3][3];

public:
    tablero3x3();
    void mostrarTablero();
    bool colocar(int fila, int columna, char simbolo);
    char verificarGanador();

};